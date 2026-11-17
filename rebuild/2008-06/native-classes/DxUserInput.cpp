// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 RBX::DxUserInput (004675e0..004690f0): DirectInput 8 keyboard/mouse input source. Inactive native unit.
// Byte-exact against the target (native-asm --obj, relocations masked): 00467530 00467550 004675e0 00467720 004677f0
// 00467a90 00467bf0 00467c50 00467cb0 00468050 004680c0 00468520 004689c0 00468a60 00468b20 00468e70 00469070 00469080
// 00469090 and the deleting destructor 004690d0.
// Close but not exact (see comments at each body): 00467670 00467ad0 00467b50 (the target multiplies by a dword 0.5f
// loaded into a register; every source form tried here makes MSVC load a qword constant and fimul one operand),
// 00467880 (target calls the imported std::string::c_str), 00467f10 (stack frame), 004684a0 (UIEvent temporaries),
// 00468e90 (target keeps a redundant test of the DirectInput pointer; the Stepped removeListener offset 0x170 differs
// because the native RunService header places that Notifier at 0x150).
// Not recovered: 00467a00 postEvent (needs a DataModel method taking const UIEvent&, 00577460, not in the shared
// DataModel.h), 004681b0 processKeyboard, 004685b0 processMouse, 00467d50, 00468b90 window message handler,
// 004690f0 constructor: recovered below, byte-identical to the target except the Stepped addListener offset (0x150 here
// vs 0x170, the native RunService header places that Notifier differently); also built here: DxCriticalSection 004328c0
// (exact). postEvent / processKeyboard (needs CMainFrame member +0x104) / processMouse / 00468b90 / 00467d50 stay open.
// (the last two lines of the old list: 004690f0 is no longer open)
#include "util/DxUserInput.h"
#include "v8datamodel/DataModel.h"
#include "util/Object.h"

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

	// 00467ad0
	G3D::Vector2 DxUserInput::getCenteredPosition()
	{
		mutex.Lock();
		CRect rect;
		window->GetClientRect(&rect);
		float w = (float)rect.Width();
		float h = (float)rect.Height();
		G3D::Vector2 result(w * 0.5f + lastPosition.x, h * 0.5f + lastPosition.y);
		mutex.Unlock();
		return result;
	}

	// 00467b50
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

	// 004684a0: mouse button 3 / 4 toggle the drag flag, then the event goes to the DataModel
	void DxUserInput::postMouseEvent(int eventType, const G3D::Vector2& position)
	{
		if (eventType == 3)
			dragging = true;
		else if (eventType == 4)
			dragging = false;
		G3D::Vector2int16 mousePosition(position);
		UIEvent event(this, (UIEvent::EventType)eventType, mousePosition, G3D::Vector2int16(0, 0), sub_00467440());
		postEvent(event);
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
		if (directInput)
		{
			directInput.p->Release();
			directInput.p = NULL;
		}
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
