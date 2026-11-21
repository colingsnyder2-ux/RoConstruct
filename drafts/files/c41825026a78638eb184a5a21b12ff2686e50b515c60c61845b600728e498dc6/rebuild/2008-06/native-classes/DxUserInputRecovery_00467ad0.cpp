// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/std-noinline-string /I{headers}/mfc-noinline-pcxstr
// 2008-06 RBX::DxUserInput remaining-source recovery (inactive until each body proves).
// Real class and layout: rebuild/2008-06/native-headers/util/DxUserInput.h.
// The older non-exact attempts for 00467ad0/00467880 still live in DxUserInput.cpp (not this file's lease);
// its owner should drop them when this unit lands, or the two units will define the same members twice.
//
// Status (agent_prove.py, this file):
//   00467880 readDeviceData   byte-exact, inactive (binds to the DxUserInput member). The named
//                             `message` temporary is what makes the target call the imported c_str().
//   00468b90 processMessage   byte-exact, inactive (the WM_* switch needs the original case order:
//                             keys, mouse-activate, focus, kill-focus, the 0x200/0x201/0x202/0x204/0x205
//                             mouse group, the wheel, then the two no-op labels 0x211/0x231; that is what
//                             makes MSVC emit the byte-indexed jump tables 0x468d1c/0x468d30 and
//                             0x468e2c/0x468e3c instead of a compare chain).
//   00467ad0 getCenteredPosition  NOT exact: 116 target bytes vs 116 candidate bytes, one x87 scheduling
//                             pair (target `fmulp st(1); fxch st(1)`, candidate `fxch st(2); ...; fmulp st(1)`).
//                             The server's 100% recipe has the same math as one expression,
//                             `result = getWindowSize() * 0.5f + offset`, i.e. an *inline member* returning a
//                             G3D::Vector2; this header only has sub_00467440() returning Vector2int16, and
//                             every other shape tried here (7 forms) is further off (114/118/146 bytes).
//                             Batch 23 retried a unit-local inline `G3D::Vector2 clientSize(CWnd*)` getter:
//                             `clientSize(window) * 0.5f + lastPosition` and `lastPosition + clientSize(window) * 0.5f`
//                             are 118 bytes (`fld [esi+0x60]; faddp st(2)` before the fxch), and
//                             `result = clientSize(window) * 0.5f; result += lastPosition;` is this 116-byte near miss.
//   00467d50 isToolboxEnabled     body below, guarded by NATIVE_DXUSERINPUT_TOOLBOX_PENDING (batch 23); it needs CMainFrame::state104 (+0x104) from
//                             CMainFrame.h, and rebuild/2008-06/native-headers/util/MarshaledListener.h
//                             (reached through CMainFrame.h -> CSelectionCaption.h) currently closes
//                             `namespace RBX` early with a stray `}` after the acquire/release declarations,
//                             so every CMainFrame.h unit fails to compile. That header is leased to
//                             class_RBX_MarshaledListener. Measured against a repaired scratch copy of the
//                             headers, this body is 452 bytes vs the target's 443 and differs only in the
//                             flag read (`mov al,[eax+0x104]; test al,al` in the target = a bool-returning
//                             inline accessor, `cmp byte ptr [eax+0x104],0` for a direct member test).
#ifdef NATIVE_DXUSERINPUT_TOOLBOX_PENDING
// isToolboxEnabled (00467d50) needs CMainFrame.h, which still fails through util/MarshaledListener.h (see below).
#include <afxwin.h>
#include "util/Events.h"
using namespace RBX; // MarshaledListener.h names Listener<> unqualified at global scope
#include "CMainFrame.h"
#endif
#include "util/DxUserInput.h"
#include "util/standardout.h"
#ifdef NATIVE_DXUSERINPUT_TOOLBOX_PENDING
#include "v8datamodel/DataModel.h"
#include "v8tree/Verb.h"
#endif

namespace RBX
{
	// 00467ad0: the window centre plus the last mouse offset, under the input lock.
	G3D::Vector2 DxUserInput::getCenteredPosition()
	{
		mutex.Lock();
		CRect rect;
		window->GetClientRect(&rect);
		G3D::Vector2 result = G3D::Vector2((float)rect.Width(), (float)rect.Height()) * 0.5f;
		result += lastPosition;
		mutex.Unlock();
		return result;
	}

	// 00467880: read buffered device data; DI_BUFFEROVERFLOW (1) is logged but not fatal.
	// The named `message` string matters: the target constructs the concatenation into its own
	// stack string and calls the imported c_str() on it (see the std-noinline-string shadow above).
	bool DxUserInput::readDeviceData(DxDeviceObjectData* data, DWORD* count, IDxInputDevice* device)
	{
		CComCritSecLock<DxCriticalSection> lock(mutex);
		switch (device->GetDeviceData(sizeof(DxDeviceObjectData), data, count, 0))
		{
		case 0:
			break;
		case 1:
			{
				std::string name(device == keyboard ? "Keyboard " : "Mouse ");
				std::string message = name + "DI_BUFFEROVERFLOW!\n";
				StandardOut::singleton()->print(MESSAGE_ERROR, message.c_str());
			}
			break;
		default:
			{
				std::string name(device == keyboard ? "Keyboard " : "Mouse ");
			}
			return false;
		}
		return true;
	}

	// 00468b90: window message handler. WM_SETFOCUS/WM_KILLFOCUS post the matching UIEvent,
	// WM_MOUSEACTIVATE arms the swallow flag, WM_KEYDOWN/UP request the keyboard, the mouse
	// messages forward a position event and refresh the acquisition state, and a wheel turn posts
	// button 8/9. The case order is the original's: it is what makes MSVC emit the byte-indexed
	// jump tables at 0x468d1c/0x468d30 and 0x468e2c/0x468e3c instead of a compare chain.
	void DxUserInput::processMessage(unsigned int message, int wParam, long lParam)
	{
		switch (message)
		{
		case WM_KEYDOWN:
		case WM_KEYUP:
			setKeyboardWanted(true);
			break;
		case WM_MOUSEACTIVATE:
			ignoreNextLeftClick = true;
			break;
		case WM_SETFOCUS:
			{
				UIEvent event(this, UIEvent::EVENT_13, sub_00467440());
				postEvent(event);
			}
			break;
		case WM_KILLFOCUS:
			{
				UIEvent event(this, UIEvent::EVENT_12, sub_00467440());
				postEvent(event);
			}
			break;
		case WM_MOUSEMOVE:
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_RBUTTONDOWN:
		case WM_RBUTTONUP:
			if (ignoreNextLeftClick && message == WM_LBUTTONDOWN)
			{
				ignoreNextLeftClick = false;
				break;
			}
			{
				G3D::Vector2 position((float)(short)(lParam & 0xffff), (float)(short)((unsigned long)lParam >> 16));
				postMouseEvent(sub_00469f00((int)message), position);
				updateMouseWanted(position);
			}
			break;
		case WM_MOUSEWHEEL:
			{
				G3D::Vector2 position((float)(short)(lParam & 0xffff), (float)(short)((unsigned long)lParam >> 16));
				postMouseEvent(wParam > 0.0 ? 8 : 9, position);
			}
			break;
		case WM_ENTERMENULOOP:
		case WM_ENTERSIZEMOVE:
			return;
		}
	}

#ifdef NATIVE_DXUSERINPUT_TOOLBOX_PENDING
	// PENDING (batch 23): util/MarshaledListener.h (leased to class_RBX_MarshaledListener) still ends with a stray `}`
	// at line 109 after the template and names Listener<> unqualified at global scope, so every CMainFrame.h unit
	// stops compiling there (then util/Guid.h / GuidItem.h cascade). Identities of every callee are proven in the
	// registry: AfxGetApp()->m_pMainWnd (AfxGetModuleState +4 / +0x20), sub_004306c0, DataModel::Lock 00411b40 /
	// ~Lock 005773c0, VerbContainer::getVerb(std::string) 00583380, Verb::isEnabled slot 3. Remaining codegen risk:
	// the target reads +0x104 as `mov al,[eax+0x104]; test al,al` (an inline bool accessor in CMainFrame, owner-only).
	// 00467d50: the toolbox may open unless the main frame's toolbox state (+0x104) is set and the active
	// DataModel's "ToggleToolbox" verb (VerbContainer::getVerb 00583380 on DataModel+0x1c8) reports disabled
	// (Verb slot 3, isEnabled). The DataModel is held under DataModel::Lock (ctor 00411b40, dtor 005773c0).
	bool DxUserInput::isToolboxEnabled()
	{
		CMainFrame* mainFrame = static_cast<CMainFrame*>(AfxGetApp()->m_pMainWnd);
		if (mainFrame->state104 && sub_004306c0())
		{
			DataModel::Lock lock(sub_004306c0());
			if (Verb* verb = sub_004306c0()->getVerb("ToggleToolbox"))
				return verb->isEnabled();
		}
		return true;
	}
#endif
}
