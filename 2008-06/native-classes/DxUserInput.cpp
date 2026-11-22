// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/uievent-native
// 2008-06 RBX::DxUserInput (004675e0..004690f0): DirectInput 8 keyboard/mouse input source. Inactive native unit.
// Byte-exact against the target (native-asm --obj, relocations masked): 00467530 00467550 004675e0 00467720 004677f0
// 00467a90 00467bf0 00467c50 00467cb0 00468050 004680c0 00468520 004689c0 00468a60 00468b20 00468e70 00469070 00469080
// 00469090 and the deleting destructor 004690d0.
// Close but not exact (see comments at each body): 00467670 00467ad0 00467b50 (the target multiplies by a dword 0.5f
// loaded into a register; every source form tried here makes MSVC load a qword constant and fimul one operand),
// 00467880 (target calls the imported std::string::c_str), 00467f10 (stack frame), 004684a0 (UIEvent temporaries),
// 00468e90 (472 = 472 bytes since batch 25: the redundant DirectInput test comes from the inlined by-reference release
// helper; the only remaining difference is the Stepped removeListener offset, 0x170 in the target vs 0x150 here,
// because the core util/RunStateOwner.h RunService places that Notifier at 0x150).
// 00467a00 postEvent: exact since batch 25 (through the header's func_00577460 conduit).
// Not recovered: 004681b0 processKeyboard (guarded), 004685b0 processMouse (near miss, batch 39), 00467d50, 00468b90 window message handler,
// 004690f0 constructor: recovered below, byte-identical to the target except the Stepped addListener offset (0x150 here
// vs 0x170, the native RunService header places that Notifier differently); also built here: DxCriticalSection 004328c0
// (exact). postEvent / processKeyboard (needs CMainFrame member +0x104) / processMouse / 00468b90 / 00467d50 stay open.
// (the last two lines of the old list: 004690f0 is no longer open)
#ifdef NATIVE_DXUSERINPUT_KEYBOARD_PENDING
// processKeyboard 004681b0 reads CMainFrame::state104 (+0x104) of the application main window. Included first, as
// the CMainFrame units do: the XTP headers need the windows.h min / max macros, which G3D/g3dmath.h (48, `#undef min`)
// and G3D/platform.h (NOMINMAX around windows.h) remove (batch 39: XTPVC50Helpers.h 542 C3861 'min' / 'max' gone).
#include "CMainFrame.h"
#endif
#include "util/DxUserInput.h"
#include "v8datamodel/DataModel.h"
#include "util/Object.h"
#include "v8datamodel/Workspace.h"   // processMouse 004685b0 calls Workspace::onWrapMouse 005a0220 (through /I{headers}/uievent-native)


// Identity-tier placeholder helpers (bodies byte-proved in Inferred_00469f50.cpp / Inferred_00469360.cpp /
// Inferred_00469c60.cpp), all cdecl: keyboard state -> SDLMod, DIK scan code -> SDLKey, SDLKey -> virtual key.
int sub_00469f50(const unsigned char* keys);
int sub_00469360(int key);
int __cdecl sub_00469c60(int index);
// INFERRED placeholder: 00469340 (cdecl, 30 B, body byte-proved in DonorCtx_00469340.cpp): the X/Y axis record of a
// buffered mouse read as a delta vector (dwOfs 0 -> x, otherwise y, both from the signed dwData).
G3D::Vector2 sub_00469340(const DxDeviceObjectData& data);

// 004328c0
DxCriticalSection::DxCriticalSection()
{
	__try
	{
		InitializeCriticalSection(&m_sec);
	}
	__except (STATUS_NO_MEMORY == GetExceptionCode())
	{
		AtlThrow(E_OUTOFMEMORY);
	}
}

namespace RBX
{
	// ATL ATLENSURE_SUCCEEDED shape: AtlThrow (00401000) on a failed HRESULT
	static inline void check(HRESULT hr)
	{
		if (FAILED(hr))
			AtlThrow(hr);
	}

	// 00467530: remember the key while it is down, clear it on release (neg/sbb/and = down ? key : 0)
	void DxUserInput::setKeyState(SDLKey key, bool down)
	{
		heldKey = down ? key : (SDLKey)0;
	}

	// 00467550: the mouse device (GUID_SysMouse, c_dfDIMouse2) with a 0x800-entry buffer (DIPROP_BUFFERSIZE = guid 1)
	void DxUserInput::createMouse()
	{
		check(directInput->CreateDevice(GUID_SysMouse, &mouse, NULL));
		check(mouse->SetDataFormat(c_dfDIMouse2));
		DxPropDword prop = { 0x14, 0x10, 0, 0, 0x800 };
		check(mouse->SetProperty((const GUID*)1, &prop));
	}

	// 004675e0: the keyboard device (GUID_SysKeyboard, c_dfDIKeyboard) with the same buffer size
	void DxUserInput::createKeyboard()
	{
		check(directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL));
		check(keyboard->SetDataFormat(c_dfDIKeyboard));
		DxPropDword prop = { 0x14, 0x10, 0, 0, 0x800 };
		check(keyboard->SetProperty((const GUID*)1, &prop));
	}

	// 00467670: take the mouse exclusively and remember where the cursor is relative to the window centre
	void DxUserInput::acquireMouse(const G3D::Vector2& position)
	{
		mouse->Unacquire();
		if (mouse->SetCooperativeLevel(hwnd, 5) == 0)
		{
			if (mouse->Acquire() == 0)
			{
				G3D::Vector2 offset = position - sub_004673f0().center();
				lastPosition = sub_004672e0(offset, offset, -10);
				mouseAcquired = true;
				dragging = false;
			}
		}
	}

	// 00467720
	void DxUserInput::acquireKeyboard()
	{
		keyboard->Unacquire();
		if (keyboard->SetCooperativeLevel(hwnd, 5) == 0)
		{
			if (SUCCEEDED(keyboard->Acquire()))
				keyboardAcquired = true;
		}
	}

	// 004677f0
	void DxUserInput::syncKeyboard()
	{
		CComCritSecLock<DxCriticalSection> lock(mutex);
		if (keyboard && keyboardAcquired != keyboardWanted)
		{
			if (keyboardWanted)
			{
				acquireKeyboard();
			}
			else
			{
				keyboard->Unacquire();
				keyboardAcquired = false;
			}
		}
	}

	// 00467a90 (slot 1): the game cursor is only shown while the mouse is acquired
	G3D::ReferenceCountedPointer<TextureProxyBase> DxUserInput::getGameCursor(Adorn* adorn)
	{
		if (mouseAcquired)
			return UserInputBase::getGameCursor(adorn);
		return G3D::ReferenceCountedPointer<TextureProxyBase>();
	}

	// 00467ad0 (116 = 116 bytes; parked). The unit's /fp:fast (evidence: processMouse 004685b0 multiplies by the dword
	// reciprocal 1/120 and keeps 0.0f on the x87 stack) now loads 0.5f as a dword like the target; the only remaining
	// difference is one x87 schedule: the target finishes both multiplies (`fmulp st(1); fxch st(1)`) before the first
	// add, this build adds x first (`fxch st(2)`, then `fmulp`). Rejected: `Vector2(w, h) * 0.5f + lastPosition` and
	// `lastPosition + Vector2(w, h) * 0.5f` (118 B, `fld x; faddp st(2)`); the earlier per-component form (114 B, fimul).
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

	// 00467b50 (open). Header proposal (util/DxUserInput.h): 004672e0 returns the Vector2 by value through the hidden
	// pointer (`G3D::Vector2 sub_004672e0(const G3D::Vector2&, int)`; the target adds from the returned eax and never
	// zero-initializes the temporary). Measured with a trial-only local overload and `half = Vector2(w, h) * 0.5f`:
	// 148 = 148 bytes, one `lea edx` / `push esi` interleave left.
	G3D::Vector2 DxUserInput::getBiasedCenterPosition()
	{
		mutex.Lock();
		CRect rect;
		window->GetClientRect(&rect);
		G3D::Vector2 half((float)rect.Width() * 0.5f, (float)rect.Height() * 0.5f);
		G3D::Vector2 bias;
		sub_004672e0(bias, lastPosition, 10);
		G3D::Vector2 result = bias + half;
		mutex.Unlock();
		return result;
	}

	// 00467bf0
	G3D::Vector2 DxUserInput::getWindowCursorPosition()
	{
		CComCritSecLock<DxCriticalSection> lock(mutex);
		POINT point;
		::GetCursorPos(&point);
		window->ScreenToClient(&point);
		return G3D::Vector2((float)point.x, (float)point.y);
	}

	// 00467c50 (slot 0)
	G3D::Vector2 DxUserInput::getCursorPosition()
	{
		mutex.Lock();
		G3D::Vector2 result = mouseAcquired ? getCenteredPosition() : getWindowCursorPosition();
		mutex.Unlock();
		return result;
	}

	// 00467cb0 (slot 5)
	bool DxUserInput::keyDown(SDLKey key) const
	{
		CComCritSecLock<DxCriticalSection> lock(mutex);
		if (heldKey && key == heldKey)
			return true;
		if (keyState[sub_004697e0(key)] & 0x80)
			return true;
		return false;
	}

	// 00468050
	void DxUserInput::setKeyboardWanted(bool wanted)
	{
		CComCritSecLock<DxCriticalSection> lock(mutex);
		keyboardWanted = wanted;
		syncKeyboard();
	}

	// 004680c0: hand the mouse back and put the cursor where the game thought it was
	void DxUserInput::releaseMouse()
	{
		mouse->Unacquire();
		G3D::Vector2 position = getBiasedCenterPosition();
		CPoint point((int)position.x, (int)position.y);
		window->ClientToScreen(&point);
		::SetCursorPos(point.x, point.y);
		static HCURSOR arrow = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		::SetCursor(arrow);
		window->Invalidate(TRUE);
		mouseAcquired = false;
		dragging = false;
	}

	// 00468520
	void DxUserInput::updateMouseAcquisition(const G3D::Vector2& position)
	{
		CComCritSecLock<DxCriticalSection> lock(mutex);
		if (!mouse)
		{
			mouseAcquired = false;
		}
		else if (mouseAcquired != mouseWanted)
		{
			if (mouseWanted)
				acquireMouse(position);
			else
				releaseMouse();
		}
	}

	// 00468a60
	void DxUserInput::updateMouseWanted(const G3D::Vector2& position)
	{
		int y = (int)position.y;
		int x = (int)position.x;
		CClientDC dc(window);
		CDC* context = &dc;
		bool inside = context->PtVisible(x, y) != 0;
		bool active = window->IsTopParentActive() != 0;
		mouseWanted = inside && active;
		updateMouseAcquisition(position);
	}

	// 00468b20
	void DxUserInput::updateMouse()
	{
		CComCritSecLock<DxCriticalSection> lock(mutex);
		if (mouseAcquired)
		{
			G3D::Vector2 position = getCenteredPosition();
			updateMouseWanted(position);
		}
	}

	// 00468e70 (Stepped listener at +0x28)
	void DxUserInput::onEvent(const RunService*, Stepped)
	{
		syncKeyboard();
		updateMouse();
	}

	// 00467880: read buffered device data; DI_BUFFEROVERFLOW is logged but not fatal
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
				StandardOut::singleton()->print(MESSAGE_ERROR, (name + "DI_BUFFEROVERFLOW!\n").c_str());
			}
			break;
		default:
			{
				std::string name(device == keyboard ? "Keyboard " : "Mouse ");
				return false;
			}
		}
		return true;
	}

	// 00467f10: turn a raw mouse delta into the delta/position pair for the current wrap mode
	void DxUserInput::applyMouseDelta(const G3D::Vector2& input, G3D::Vector2& output)
	{
		switch (wrapMode)
		{
		case WRAP_AUTO:
			if (sub_004674a0() || dragging)
			{
				G3D::Vector2int16 size = sub_00467440();
				G3D::Vector2 v((float)size.x, (float)size.y);
				sub_0046a100(input, output, lastPosition, v);
			}
			else if (sub_00467d50())
			{
				sub_004692f0(input, output, lastPosition);
			}
			else if (sub_00467380())
			{
				G3D::Vector2 v(sub_00467440());
				sub_0046a130(input, output, lastPosition, v);
			}
			else
			{
				G3D::Vector2 v(sub_00467440());
				sub_0046a1b0(input, output, lastPosition, v);
			}
			break;
		case WRAP_CENTER:
			sub_00469320(input, output, lastPosition);
			break;
		}
	}

	// 00467a00: hand the event to the DataModel under its lock (DataModel::Lock 00411b40 / ~Lock 005773c0 from a
	// shared_ptr<const DataModel> copy of +0x180). The DataModel member at 00577460 has no declaration in the core
	// DataModel.h, so the call goes through the header's INFERRED conduit func_00577460 (ECX = the DataModel pointer).
	void DxUserInput::postEvent(const UIEvent& event)
	{
		DataModel::Lock lock(dataModel);
		reinterpret_cast<DxUserInput*>(dataModel.get())->func_00577460(event);
	}

	// 004684a0: mouse button 3 / 4 toggle the drag flag, then the event goes to the DataModel.
	// The target stores the zero mouseDelta words straight into the event (no Vector2int16 temporary) after the
	// sub_00467440 window-size call: the shape of the openrbx util/UIEvent.h constructor
	// UIEvent(userInput, eventType, Vector2int16 position, Vector2int16 size) : ..., mouseDelta(0, 0), windowSize(size).
	// The core util/UIEvent2008.h does not declare that constructor (proposal to its owner). Measured in batch 39 with
	// a scratch copy of util/UIEvent2008.h holding it (not kept): 004684a0 postMouseEvent and its two inlined copies in
	// 004685b0 processMouse are then byte-identical (both exact, with CWnd::PostMessage 004112a0 and the processMouse
	// EH handler 007c36e1). Until the header has it, the five-argument constructor with a Vector2int16(0, 0)
	// temporary is used (121 B against 113: the temporary is materialized before the window-size call).
	void DxUserInput::postMouseEvent(int eventType, const G3D::Vector2& position)
	{
		if (eventType == 3)
			dragging = true;
		else if (eventType == 4)
			dragging = false;
		G3D::Vector2int16 mousePosition(position);
#ifdef UIEVENT_HEADER_DECLARES_POSITION_SIZE_CTOR
		UIEvent event(this, (UIEvent::EventType)eventType, mousePosition, sub_00467440());
#else
		UIEvent event(this, (UIEvent::EventType)eventType, mousePosition, G3D::Vector2int16(0, 0), sub_00467440());
#endif
		postEvent(event);
	}

	// 004681b0 (registry placeholder func_004681b0; called only by the Heartbeat poll 004689c0, which the header names
	// processKeyboard): drain the buffered keyboard data under the DataModel lock. While the main frame exists, a key
	// press whose virtual key (MapVirtualKeyEx type 1, else sub_00469c60) is PrintScreen posts WM_COMMAND 0x80fc; for
	// F1, F4, or any key while CMainFrame::state104 is clear, a matching ACCEL entry (type 2 character for non-FVIRTKEY
	// entries, FSHIFT/FCONTROL/FALT from the SDLMod bits) is posted to the frame as WM_COMMAND instead of a key event.
	// PENDING (NATIVE_DXUSERINPUT_KEYBOARD_PENDING): the XTP min / max failure is fixed by including CMainFrame.h first
	// (top of this unit, batch 39). The only remaining blocker is the core util/MarshaledListener.h, which closes
	// namespace RBX before the MarshaledListener template (the stray `}` at line 19; proposal to its owner). Batch 39
	// measured once against a scratch copy of the header tree with that line removed: the unit compiles (101 rows,
	// no baseline exact lost) and this body is 723 B against 738, the same as the earlier stand-in measurement. Measured with a cast stand-in for the state104 read (trial only, not
	// kept): 723 vs 738 bytes, same frame (0xa040). Remaining diff: the target walks the DIDEVICEOBJECTDATA array
	// through &data[i].dwData (`mov ebx,[eax]; mov ebp,[eax-4]`, this build uses the element base), keeps the virtual
	// key in a stack slot for the accelerator compare (`cmp eax,[esp+0x14]`), and places the PrintScreen post out of
	// line after the return. Rejected: a materialized `same` bool / BYTE flags / char character (714 B, frame
	// 0xa03c), `accel.key == vk : accel.key == (char)ch` ternary of comparisons (756 B, sete), a found-index loop
	// (759 B), and `if (vk != VK_SNAPSHOT) {...} else post` (723 B, more diff lines).
#ifdef NATIVE_DXUSERINPUT_KEYBOARD_PENDING
	void DxUserInput::processKeyboard()
	{
		DWORD count = 0x800;
		DxDeviceObjectData data[0x800];
		{
			CComCritSecLock<DxCriticalSection> lock(mutex);
			if (!readDeviceData(data, &count, keyboard))
			{
				keyboardAcquired = false;
				return;
			}
		}
		DataModel::Lock lock(dataModel);
		for (DWORD i = 0; i < count; ++i)
		{
			bool down = (data[i].dwData & 0x80) != 0;
			UINT scanCode = data[i].dwOfs;
			SDLMod mod = (SDLMod)sub_00469f50(keyState);
			SDLKey key = (SDLKey)sub_00469360(scanCode);
			if (down && mainFrame)
			{
				static HKL layout = GetKeyboardLayout(0);
				UINT virtualKey = MapVirtualKeyEx(scanCode, 1, layout);
				if (!virtualKey)
					virtualKey = sub_00469c60(key);
				if (virtualKey == VK_SNAPSHOT)
					::PostMessage(mainFrame->m_hWnd, WM_COMMAND, MAKEWPARAM(0x80fc, 1), 0);
				else if (virtualKey == VK_F1 || virtualKey == VK_F4 || !static_cast<CMainFrame*>(AfxGetApp()->m_pMainWnd)->state104)
				{
					UINT character = MapVirtualKeyEx(virtualKey, 2, layout);
					int flags = ((mod & KMOD_ALT) ? FALT : 0) | ((mod & KMOD_CTRL) ? FCONTROL : 0) | ((mod & KMOD_SHIFT) ? FSHIFT : 0);
					bool handled = false;
					for (unsigned int j = 0; j < numAccelerators; ++j)
					{
						const ACCEL& accel = accelerators[j];
						if (accel.key == ((accel.fVirt & FVIRTKEY) ? virtualKey : (char)character)
							&& (accel.fVirt & (FSHIFT | FCONTROL | FALT)) == flags)
						{
							::PostMessage(mainFrame->m_hWnd, WM_COMMAND, MAKEWPARAM(accelerators[j].cmd, 1), 0);
							handled = true;
							break;
						}
					}
					if (handled)
						continue;
				}
			}
			UIEvent event(this, down ? UIEvent::KEY_DOWN : UIEvent::KEY_UP, key, mod);
			postEvent(event);
		}
	}
#endif

	// 004685b0 (registry placeholder func_004685b0; header name processMouse, called only by the Heartbeat poll
	// 004689c0): drain up to 0x800 buffered DirectInput mouse records (readDeviceData 00467880 on the mouse at +0x178;
	// a failed read clears mouseAcquired +0x192) and dispatch on DIDEVICEOBJECTDATA::dwOfs through the jump table at
	// 00468990: DIMOFS_X / DIMOFS_Y (0 / 4) accumulate the wrapped delta (00469340, applyMouseDelta 00467f10), DIMOFS_Z
	// (8) posts MOUSE_WHEEL_FORWARD / BACKWARD by the sign of dwData * (1 / 120.0f) (float 0081c3e4), DIMOFS_BUTTON0 /
	// BUTTON1 (0xc / 0xd) post message 0x4bb to the client window (+0x16c, m_hWnd +0x20) and a left / right button
	// down (dwData 0x80) or up event (postMouseEvent 004684a0). Afterwards, under the DataModel lock, a non-zero delta
	// goes to Workspace::onWrapMouse 005a0220 (workspace +0x204) and posts MOUSE_DELTA then MOUSE_MOVE; a move without
	// delta posts MOUSE_MOVE only.
	// Batch 39: no longer guarded. v8datamodel/Workspace.h (onWrapMouse 005a0220) now compiles here through the
	// include-path profile /I{headers}/uievent-native, whose util/UIEvent.h forwards to util/UIEvent2008.h, so the
	// donor gui/GuiEvent.h -> util/UIEvent.h chain no longer redefines RBX::UIEvent (the former C2011). The button
	// cases use the inline CWnd::PostMessage (openrbx Client/win/DxUserInput.cpp `PostMessage(WM_USER + 0xbb)`; the
	// target reloads the window pointer into eax as the inline afxwin.inl body does). Remaining difference
	// (1050 B against 1026): only the two inlined postMouseEvent copies after the loop, which materialize the
	// Vector2int16(0, 0) delta temporary (see 004684a0 above: the core util/UIEvent2008.h lacks the
	// position / size constructor); with that constructor in a scratch header copy this body is byte-identical.
	// Rejected earlier: the source case order X/Y, Z, BUTTON0, BUTTON1 (1022 B, button tails merged, qword constants
	// before /fp:fast).
	void DxUserInput::processMouse()
	{
		DWORD count = 0x800;
		DxDeviceObjectData data[0x800];
		{
			CComCritSecLock<DxCriticalSection> lock(mutex);
			if (!readDeviceData(data, &count, mouse))
			{
				mouseAcquired = false;
				return;
			}
		}
		G3D::Vector2 delta(0.0f, 0.0f);
		bool moved = false;
		for (DWORD i = 0; i < count; ++i)
		{
			switch (data[i].dwOfs)
			{
			case 0xc: // DIMOFS_BUTTON0
				window->PostMessage(0x4bb);
				postMouseEvent(data[i].dwData == 0x80 ? UIEvent::MOUSE_LEFT_BUTTON_DOWN : UIEvent::MOUSE_LEFT_BUTTON_UP,
							   getCursorPosition());
				break;
			case 0xd: // DIMOFS_BUTTON1
				window->PostMessage(0x4bb);
				postMouseEvent(data[i].dwData == 0x80 ? UIEvent::MOUSE_RIGHT_BUTTON_DOWN : UIEvent::MOUSE_RIGHT_BUTTON_UP,
							   getCursorPosition());
				break;
			case 0:   // DIMOFS_X
			case 4:   // DIMOFS_Y
				moved = true;
				applyMouseDelta(sub_00469340(data[i]), delta);
				break;
			case 8:   // DIMOFS_Z
				postMouseEvent((int)data[i].dwData * (1.0f / 120.0f) > 0.0f ? UIEvent::MOUSE_WHEEL_FORWARD
																		 : UIEvent::MOUSE_WHEEL_BACKWARD,
							   getCursorPosition());
				break;
			}
		}
		if (delta != G3D::Vector2::zero())
		{
			DataModel::Lock lock(dataModel);
			dataModel->getWorkspace()->onWrapMouse(delta);
			postMouseEvent(UIEvent::MOUSE_DELTA, getCursorPosition());
			postMouseEvent(UIEvent::MOUSE_MOVE, getCursorPosition());
		}
		else if (moved)
		{
			DataModel::Lock lock(dataModel);
			postMouseEvent(UIEvent::MOUSE_MOVE, getCursorPosition());
		}
	}

	// 004689c0 (Heartbeat listener at +0x2c): poll both devices
	void DxUserInput::onEvent(const RunService*, Heartbeat)
	{
		CComCritSecLock<DxCriticalSection> lock(mutex);
		syncKeyboard();
		if (mouseAcquired)
			processMouse();
		if (keyboard)
			keyboard->GetDeviceState(sizeof(keyState), keyState);
		if (keyboardAcquired)
			processKeyboard();
	}

	static inline HWND topLevelHwnd(CWnd* window)
	{
		return window->GetTopLevelFrame()->GetSafeHwnd();
	}

	// 004690f0
	DxUserInput::DxUserInput(CWnd* wnd, DataModel* dataModel)
		: UserInputBase(),
		  accelerators(NULL),
		  numAccelerators(0),
		  ignoreNextLeftClick(false),
		  dragging(false),
		  wrapMode(WRAP_AUTO),
		  lastPosition(0, 0),
		  heldKey((SDLKey)0),
		  window(wnd),
		  hwnd(topLevelHwnd(wnd)),
		  dataModel(shared_from(dataModel)),
		  runService(shared_from(dataModel ? dataModel->create<RunService>() : NULL)),
		  mouseWanted(false),
		  keyboardWanted(false),
		  mouseAcquired(false),
		  keyboardAcquired(false)
	{
		mainFrame = this->window->GetParentFrame();
		while (mainFrame)
		{
			numAccelerators = ::CopyAcceleratorTableA(mainFrame->GetDefaultAccelerator(), NULL, 0);
			if (numAccelerators)
			{
				accelerators = new ACCEL[numAccelerators];
				::CopyAcceleratorTableA(mainFrame->GetDefaultAccelerator(), accelerators, numAccelerators);
				break;
			}
			mainFrame = mainFrame->GetParentFrame();
		}
		memset(keyState, 0, sizeof(keyState));
		check(DirectInput8Create(GetModuleHandleA(NULL), 0x800, IID_IDirectInput8A, (void**)&directInput, NULL));
		createMouse();
		createKeyboard();
		if (runService)
			runService->Notifier<RunService, Heartbeat>::addListener(static_cast<Listener<RunService, Heartbeat>*>(this));
		if (runService)
			runService->Notifier<RunService, Stepped>::addListener(static_cast<Listener<RunService, Stepped>*>(this));
	}

	// INFERRED helper (no address: always inlined): release through a reference so the inlined test reloads the
	// member, which is what keeps the target's second test of +0x174 after the caller's own check.
	template<class T> inline void releaseDxInterface(CComPtr<T>& ptr)
	{
		if (ptr)
		{
			ptr.p->Release();
			ptr.p = NULL;
		}
	}

	// 00468e90
	DxUserInput::~DxUserInput()
	{
		if (runService)
			runService->Notifier<RunService, Heartbeat>::removeListener(static_cast<Listener<RunService, Heartbeat>*>(this));
		if (runService)
			runService->Notifier<RunService, Stepped>::removeListener(static_cast<Listener<RunService, Stepped>*>(this));
		if (mouse)
		{
			mouse->Unacquire();
			if (mouse)
			{
				mouse.p->Release();
				mouse.p = NULL;
			}
		}
		if (keyboard)
		{
			keyboard->Unacquire();
			if (keyboard)
			{
				keyboard.p->Release();
				keyboard.p = NULL;
			}
		}
		// The target tests +0x174 twice (`cmp [esi+0x174],0` then reload/test) with no call in between.
		if (directInput)
			releaseDxInterface(directInput);
		delete[] accelerators;
	}

	// 00469070 / 00469080 (slots 2 and 3)
	void DxUserInput::setWrapMode(WrapMode mode)
	{
		wrapMode = mode;
	}

	UserInputBase::WrapMode DxUserInput::getWrapMode() const
	{
		return wrapMode;
	}

	// 00469090 (slot 4)
	void DxUserInput::centerCursor()
	{
		lastPosition = G3D::Vector2::zero();
	}
}
