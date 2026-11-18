#include "util/DxUserInput.h"
#include "v8datamodel/DataModel.h"
#include "util/Object.h"

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
	static inline void check(HRESULT hr)
	{
		if (FAILED(hr))
			AtlThrow(hr);
	}

	void DxUserInput::setKeyState(SDLKey key, bool down)
	{
		heldKey = down ? key : (SDLKey)0;
	}

	void DxUserInput::createMouse()
	{
		check(directInput->CreateDevice(GUID_SysMouse, &mouse, NULL));
		check(mouse->SetDataFormat(c_dfDIMouse2));
		DxPropDword prop = { 0x14, 0x10, 0, 0, 0x800 };
		check(mouse->SetProperty((const GUID*)1, &prop));
	}

	void DxUserInput::createKeyboard()
	{
		check(directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL));
		check(keyboard->SetDataFormat(c_dfDIKeyboard));
		DxPropDword prop = { 0x14, 0x10, 0, 0, 0x800 };
		check(keyboard->SetProperty((const GUID*)1, &prop));
	}

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

	void DxUserInput::acquireKeyboard()
	{
		keyboard->Unacquire();
		if (keyboard->SetCooperativeLevel(hwnd, 5) == 0)
		{
			if (SUCCEEDED(keyboard->Acquire()))
				keyboardAcquired = true;
		}
	}

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

	G3D::ReferenceCountedPointer<TextureProxyBase> DxUserInput::getGameCursor(Adorn* adorn)
	{
		if (mouseAcquired)
			return UserInputBase::getGameCursor(adorn);
		return G3D::ReferenceCountedPointer<TextureProxyBase>();
	}

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

	G3D::Vector2 DxUserInput::getWindowCursorPosition()
	{
		CComCritSecLock<DxCriticalSection> lock(mutex);
		POINT point;
		::GetCursorPos(&point);
		window->ScreenToClient(&point);
		return G3D::Vector2((float)point.x, (float)point.y);
	}

	G3D::Vector2 DxUserInput::getCursorPosition()
	{
		mutex.Lock();
		G3D::Vector2 result = mouseAcquired ? getCenteredPosition() : getWindowCursorPosition();
		mutex.Unlock();
		return result;
	}

	bool DxUserInput::keyDown(SDLKey key) const
	{
		CComCritSecLock<DxCriticalSection> lock(mutex);
		if (heldKey && key == heldKey)
			return true;
		if (keyState[sub_004697e0(key)] & 0x80)
			return true;
		return false;
	}

	void DxUserInput::setKeyboardWanted(bool wanted)
	{
		CComCritSecLock<DxCriticalSection> lock(mutex);
		keyboardWanted = wanted;
		syncKeyboard();
	}

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

	void DxUserInput::updateMouse()
	{
		CComCritSecLock<DxCriticalSection> lock(mutex);
		if (mouseAcquired)
		{
			G3D::Vector2 position = getCenteredPosition();
			updateMouseWanted(position);
		}
	}

	void DxUserInput::onEvent(const RunService*, Stepped)
	{
		syncKeyboard();
		updateMouse();
	}

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

	void DxUserInput::setWrapMode(WrapMode mode)
	{
		wrapMode = mode;
	}

	UserInputBase::WrapMode DxUserInput::getWrapMode() const
	{
		return wrapMode;
	}

	void DxUserInput::centerCursor()
	{
		lastPosition = G3D::Vector2::zero();
	}
}
