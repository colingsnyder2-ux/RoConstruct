#pragma once
// 2008-06 RBX::DxUserInput (inactive native header). DirectInput 8 backed UserInputBase used by the Studio/player view.
// Layout evidence (all offsets from the 2008-06 binary):
//   ctor/dtor body 00468e90 stores vftable 0081c404 at +0 and the two Listener vftables 0081c3f8 (+0x28) and
//   0081c3ec (+0x2c); RTTI complete-object locators 00885d9c/00885ed8/00885ec4 give the base offsets 0, 0x28, 0x2c.
//   +0x28/+0x2c are Listener<RunService, X> bases: the dtor removes them from the RunService notifier lists at
//   +0x130 (this+0x2c) and +0x170 (this+0x28) (005e5a80 = Notifier::removeListener).
#include "util/UserInputBase.h"
#include "util/Events.h"
#include "util/RunStateOwner.h"
#include "util/UIEvent2008.h"
#include <boost/shared_ptr.hpp>
#include <boost/detail/lightweight_mutex.hpp>
#include <G3D/Vector2.h>
#include <G3D/Vector2int16.h>
#include <afxwin.h>

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

namespace RBX
{
	class DataModel;

	class DxUserInput : public UserInputBase,
						public Listener<RunService, Stepped>,
						public Listener<RunService, Heartbeat>
	{
	public:
		boost::detail::lightweight_mutex mutex;              // +0x34 (CRITICAL_SECTION, 0x18 bytes)
		CWnd* mainFrame;                                     // +0x4c: PostMessage target for accelerator commands
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
		IDxInput* directInput;                               // +0x174
		IDxInputDevice* mouse;                               // +0x178
		IDxInputDevice* keyboard;                            // +0x17c
		boost::shared_ptr<DataModel> dataModel;              // +0x180 (px) / +0x184 (pn)
		RunService* runService;                              // +0x188: notifier owner the Listener bases are attached to
		boost::detail::shared_count* runServiceCount;        // +0x18c (INFERRED: released in the dtor, never read)
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

		void createMouse();                                            // 00467550
		void createKeyboard();                                         // 004675e0
	};
}
