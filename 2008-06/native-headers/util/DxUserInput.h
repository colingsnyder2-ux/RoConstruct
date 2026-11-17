#pragma once
// 2008-06 RBX::DxUserInput (inactive native header). DirectInput 8 backed UserInputBase used by the Studio/player view.
// Layout evidence (all offsets from the 2008-06 binary):
//   ctor/dtor body 00468e90 stores vftable 0081c404 at +0 and the two Listener vftables 0081c3f8 (+0x28) and
//   0081c3ec (+0x2c); RTTI complete-object locators 00885d9c/00885ed8/00885ec4 give the base offsets 0, 0x28, 0x2c.
//   +0x28/+0x2c are Listener<RunService, X> bases: the dtor removes them from the RunService notifier lists at
//   +0x130 (this+0x2c) and +0x170 (this+0x28) (005e5a80 = Notifier::removeListener).
#include <afxwin.h>
#include <atlbase.h>
#include "util/UserInputBase.h"
#include "util/Events.h"
#include "util/RunStateOwner.h"
#include "util/UIEvent2008.h"
#include <boost/shared_ptr.hpp>
#include <G3D/Vector2.h>
#include <G3D/Vector2int16.h>
#include <G3D/Rect2D.h>
#include "util/standardout.h"

// INFERRED: minimal DirectInput 8 COM subset (no dinput.h in the toolchain). Slot numbers come from the call sites:
// device vtable +0x1c Acquire, +0x20 Unacquire, +0x24 GetDeviceState, +0x28 GetDeviceData, +0x18 SetProperty,
// +0x2c SetDataFormat, +0x34 SetCooperativeLevel; IDirectInput8 +0xc CreateDevice.
struct DxDeviceObjectData
{
	DWORD dwOfs;
	DWORD dwData;
	DWORD dwTimeStamp;
	DWORD dwSequence;
	UINT_PTR uAppData;
};

struct DxPropDword
{
	DWORD dwSize;
	DWORD dwHeaderSize;
	DWORD dwObj;
	DWORD dwHow;
	DWORD dwData;
};

struct IDxInputDevice : public IUnknown
{
	virtual HRESULT __stdcall GetCapabilities(void*) = 0;
	virtual HRESULT __stdcall EnumObjects(void*, void*, DWORD) = 0;
	virtual HRESULT __stdcall GetProperty(const GUID*, void*) = 0;
	virtual HRESULT __stdcall SetProperty(const GUID*, const DxPropDword*) = 0;
	virtual HRESULT __stdcall Acquire() = 0;
	virtual HRESULT __stdcall Unacquire() = 0;
	virtual HRESULT __stdcall GetDeviceState(DWORD, void*) = 0;
	virtual HRESULT __stdcall GetDeviceData(DWORD, DxDeviceObjectData*, DWORD*, DWORD) = 0;
	virtual HRESULT __stdcall SetDataFormat(const void*) = 0;
	virtual HRESULT __stdcall SetEventNotification(HANDLE) = 0;
	virtual HRESULT __stdcall SetCooperativeLevel(HWND, DWORD) = 0;
};

struct IDxInput : public IUnknown
{
	virtual HRESULT __stdcall CreateDevice(const GUID&, IDxInputDevice**, IUnknown*) = 0;
};

// dxguid.lib / dinput8.lib statics referenced by the device setup (addresses: GUID_SysKeyboard 0081f038,
// GUID_SysMouse 0085012c, c_dfDIKeyboard 00850114, c_dfDIMouse2 0084ff0c).
extern "C" const GUID GUID_SysKeyboard;
extern "C" const GUID GUID_SysMouse;
extern "C" const char c_dfDIKeyboard[];
extern "C" const char c_dfDIMouse2[];
extern "C" const GUID IID_IDirectInput8A;   // 0081f028
extern "C" HRESULT __stdcall DirectInput8Create(HINSTANCE, DWORD, const GUID&, void**, IUnknown*);   // dinput8.lib import, 0x800 = DIRECTINPUT_VERSION

// INFERRED: the constructor 004328c0 (shared with other critical-section owners) is out of line, SEH-guarded
// InitializeCriticalSection and AtlThrow(E_OUTOFMEMORY), with no zeroing before it; the destructor is an inline
// DeleteCriticalSection (0046903e). It is not CComAutoCriticalSection (inline ctor, memset, Term in the dtor).
class DxCriticalSection
{
public:
	__declspec(noinline) DxCriticalSection();
	~DxCriticalSection() { DeleteCriticalSection(&m_sec); }   // 00469042 inline in ~DxUserInput
	HRESULT Lock() { EnterCriticalSection(&m_sec); return S_OK; }
	HRESULT Unlock() { LeaveCriticalSection(&m_sec); return S_OK; }
	CRITICAL_SECTION m_sec;
};

namespace RBX
{
	class DataModel;

	class DxUserInput : public UserInputBase,
						public Listener<RunService, Stepped>,
						public Listener<RunService, Heartbeat>
	{
	public:
		int reserved30;                                      // +0x30 INFERRED: the critical section at +0x34 needs 4 bytes before it; nothing reads it
		mutable DxCriticalSection mutex;                     // +0x34 (0x18 bytes, ctor 004328c0)
		CFrameWnd* mainFrame;                                // +0x4c: PostMessage target for accelerator commands (GetParentFrame, ctor 004690f0)
		ACCEL* accelerators;                                 // +0x50: 6-byte ACCEL entries, freed with operator delete[] in the dtor
		unsigned int numAccelerators;                        // +0x54
		bool ignoreNextLeftClick;                            // +0x58: 00468bde sets, 00468c62 clears on WM_LBUTTONDOWN
		bool dragging;                                       // +0x59: set by tool mouse messages 3 (down) / 4 (up)
		WrapMode wrapMode;                                   // +0x5c: setWrapMode 00469070 / getWrapMode 00469080
		G3D::Vector2 lastPosition;                           // +0x60: 00469090 zero-initialises, 00467bf0 adds it to positions
		unsigned char keyState[256];                         // +0x68: DIK keyboard state, bit 7 = down (GetDeviceState 0x100)
		SDLKey heldKey;                                      // +0x168: 00467530 setKeyState records the pressed key, 0 when released
		CWnd* window;                                        // +0x16c: client window (m_hWnd at +0x20)
		HWND hwnd;                                           // +0x170: cooperative level window for SetCooperativeLevel
		CComPtr<IDxInput> directInput;                       // +0x174 (dtor 00468e90 releases each at its own EH state)
		CComPtr<IDxInputDevice> mouse;                       // +0x178
		CComPtr<IDxInputDevice> keyboard;                    // +0x17c
		boost::shared_ptr<DataModel> dataModel;              // +0x180 (px) / +0x184 (pn)
		boost::shared_ptr<RunService> runService;            // +0x188 (px) / +0x18c (pn): notifier owner the Listener bases attach to
		bool mouseWanted;                                    // +0x190: window active and cursor inside (00468a60)
		bool keyboardWanted;                                 // +0x191: 00468050 setKeyboardWanted
		bool mouseAcquired;                                  // +0x192: 00467670 acquire / 004680c0 release
		bool keyboardAcquired;                               // +0x193: 00467720 acquire / 004677f0 sync

		// vftable 0081c404 slots (UserInputBase order)
		virtual G3D::Vector2 getCursorPosition();                      // 00467c50
		virtual G3D::ReferenceCountedPointer<TextureProxyBase> getGameCursor(Adorn*); // 00467a90 (ret 8 override)
		virtual void setWrapMode(WrapMode mode);                       // 00469070
		virtual WrapMode getWrapMode() const;                          // 00469080
		virtual void centerCursor();                                   // 00469090
		virtual bool keyDown(SDLKey key) const;                        // 00467cb0
		virtual void setKeyState(SDLKey key, bool down);               // 00467530

		virtual void onEvent(const RunService*, Stepped);              // 00468e70 (thunk 004690b0 adjusts this by -0x28)
		virtual void onEvent(const RunService*, Heartbeat);            // 004689c0 (thunk 004690c0 adjusts this by -0x2c)
		virtual ~DxUserInput();                                        // 00468e90 (deleting form 004690d0)
		DxUserInput(CWnd* window, DataModel* dataModel);                // 004690f0 (ret 8: the DataModel arrives as a raw pointer, shared_from<DataModel> 00618a40)

		void createMouse();                                            // 00467550
		void createKeyboard();                                         // 004675e0
		void acquireMouse(const G3D::Vector2& position);               // 00467670
		void acquireKeyboard();                                        // 00467720
		void syncKeyboard();                                           // 004677f0
		G3D::Vector2 getCenteredPosition();                            // 00467ad0
		G3D::Vector2 getBiasedCenterPosition();                        // 00467b50
		G3D::Vector2 getWindowCursorPosition();                        // 00467bf0
		void setKeyboardWanted(bool wanted);                           // 00468050
		void releaseMouse();                                           // 004680c0
		void updateMouseAcquisition(const G3D::Vector2& position);     // 00468520
		void updateMouseWanted(const G3D::Vector2& position);          // 00468a60
		void updateMouse();                                            // 00468b20
		bool readDeviceData(DxDeviceObjectData* data, DWORD* count, IDxInputDevice* device); // 00467880
		void applyMouseDelta(const G3D::Vector2& input, G3D::Vector2& output);  // 00467f10
		void postMouseEvent(int eventType, const G3D::Vector2& position);       // 004684a0
		void postEvent(const UIEvent& event);                                   // 00467a00 (blocked: DataModel method)
		void processKeyboard();                                                // 004681b0 (not recovered)
		void processMouse();                                                   // 004685b0 (not recovered)

		// Out-of-line helpers outside the 19 recovered bodies (identity-tier placeholder names).
		G3D::Rect2D sub_004673f0() const;                              // client rect as (0,0)-(width,height)
		bool sub_00467380() const;                                     // client rect origin equals its screen position
		G3D::Vector2int16 sub_00467440() const;                        // client size as Vector2int16
	};

}

// Free helpers called by DxUserInput (identity-tier placeholder names, bodies recovered elsewhere).
G3D::Vector2& sub_004672e0(G3D::Vector2& out, const G3D::Vector2& in, int n);  // 004672e0, cdecl
int sub_004697e0(SDLKey key);                                                   // 004697e0, cdecl
void sub_00469320(const G3D::Vector2& input, G3D::Vector2& output, G3D::Vector2& last);                          // 00469320, cdecl
void sub_004692f0(const G3D::Vector2& input, G3D::Vector2& output, G3D::Vector2& last);                          // 004692f0, cdecl
void sub_0046a100(const G3D::Vector2& input, G3D::Vector2& output, G3D::Vector2& last, const G3D::Vector2& size); // 0046a100, cdecl
void sub_0046a130(const G3D::Vector2& input, G3D::Vector2& output, G3D::Vector2& last, const G3D::Vector2& size); // 0046a130, cdecl
void sub_0046a1b0(const G3D::Vector2& input, G3D::Vector2& output, G3D::Vector2& last, const G3D::Vector2& size); // 0046a1b0, cdecl
bool sub_00467d50();                                                                                             // 00467d50, cdecl, no arguments
