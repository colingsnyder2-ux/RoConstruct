#include "wxGWindow.h"

// Static functions at end of file
static void initWXKeys();


// Hashtable to map wxWidgets keys to SDL keys
static Table<int, int> sdlKeyMap;


// wxWidgets event table
BEGIN_EVENT_TABLE(wxG3DCanvas, wxGLCanvas)
  EVT_KEY_DOWN( wxG3DCanvas::handleKeyDown )
  EVT_KEY_UP( wxG3DCanvas::handleKeyUp )
  EVT_LEFT_DOWN( wxG3DCanvas::handleMouseLeftDown )
  EVT_LEFT_UP( wxG3DCanvas::handleMouseLeftUp )
  EVT_RIGHT_DOWN( wxG3DCanvas::handleMouseRightDown )
  EVT_RIGHT_UP( wxG3DCanvas::handleMouseRightUp )
  EVT_MIDDLE_DOWN( wxG3DCanvas::handleMouseMiddleDown )
  EVT_MIDDLE_UP( wxG3DCanvas::handleMouseMiddleUp )
  EVT_MOTION( wxG3DCanvas::handleMouseMove )
  EVT_MOVE( wxG3DCanvas::handleWindowMove )
  EVT_CLOSE( wxG3DCanvas::handleWindowClose )
  EVT_IDLE( wxG3DCanvas::handleIdle )
END_EVENT_TABLE()


void wxGWindow::makeAttribList(
        const GWindowSettings&  settings,
        Array<int>&             attribList) {

    // The wx attrib list does not contain exclusively pairs; some options
    // are either present or absent (e.g. WX_GL_STEREO).

    attribList.clear();
    attribList.append(WX_GL_RGBA, 1);
    attribList.append(WX_GL_LEVEL, 0);

    attribList.append(WX_GL_DOUBLEBUFFER);

    if (settings.stereo) {
        attribList.append(WX_GL_STEREO);
    }
    attribList.append(WX_GL_MIN_RED, settings.rgbBits);
    attribList.append(WX_GL_MIN_GREEN, settings.rgbBits);
    attribList.append(WX_GL_MIN_BLUE, settings.rgbBits);
    attribList.append(WX_GL_MIN_ALPHA, settings.alphaBits);
    attribList.append(WX_GL_DEPTH_SIZE, 
        (settings.depthBits == 24 || settings.depthBits == -1) ? 
        32 : settings.depthBits);
    attribList.append(WX_GL_STENCIL_SIZE, settings.stencilBits); 
    attribList.append(0);
}

wxGWindow::wxGWindow(
    const GWindowSettings&  _settings,
    wxWindow*               parent,
    wxWindowID              id)  : invisible(wxCURSOR_BLANK), arrow(wxCURSOR_ARROW) {

    // For now a crude check to initialize once per process.
    if (sdlKeyMap.size() == 0) {
        initWXKeys();
    }

    Array<int> attribList;
    makeAttribList(_settings, attribList);
    settings = _settings;

    wxPoint pos(_settings.x, _settings.y);
    wxSize size(_settings.width, _settings.height);

    clientX = _settings.x;
    clientY = _settings.y;
    relativeX = 0;
    relativeY = 0;

    window = new wxG3DCanvas( this,
        parent, id, pos, size, 0, 
        "WxWindow", attribList.getCArray(), 
        wxNullPalette);

    glGetIntegerv(GL_DEPTH_BITS, &settings.depthBits);
    glGetIntegerv(GL_STENCIL_BITS, &settings.stencilBits);

    int redBits, greenBits, blueBits;
    glGetIntegerv(GL_RED_BITS,   &redBits);
    glGetIntegerv(GL_GREEN_BITS, &greenBits);
    glGetIntegerv(GL_BLUE_BITS,  &blueBits);

    settings.rgbBits = iMin(redBits, iMin(greenBits, blueBits));
    glGetIntegerv(GL_ALPHA_BITS, &settings.alphaBits);

    if (window->IsTopLevel()) {
        window->SetClientSize(_settings.width, _settings.height);
    }

    if (settings.center) {
        window->Center();
    }

    if (! settings.visible) {
        window->Hide();
    }

    window->GetPosition(&settings.x, &settings.y);
    window->GetClientSize(&settings.width, &settings.height);
}


wxGWindow::wxGWindow(wxG3DCanvas* canvas) : 
    invisible(wxCURSOR_BLANK), 
    arrow(wxCURSOR_ARROW), 
    window(canvas) {

    window->GetPosition(&settings.x, &settings.y);
    window->GetClientSize(&settings.width, &settings.height);
    settings.visible = window->IsShown();

    clientX = settings.x;
    clientY = settings.y;
    relativeX = 0;
    relativeY = 0;    
}


std::string wxGWindow::getAPIVersion () const {
    return wxVERSION_STRING;
}

std::string wxGWindow::getAPIName () const {
    return "wxWindows";
}

/** The wxWindow represented by this object */
wxG3DCanvas* wxGWindow::wxHandle() const {
    return window;
}

void wxGWindow::swapGLBuffers() {
    window->SwapBuffers();
}

void wxGWindow::getSettings(GWindowSettings& _settings) const {
    wxGWindow* t = const_cast<wxGWindow*>(this);
    window->GetPosition(&t->settings.x, &t->settings.y);
    _settings = settings;
}

int	wxGWindow::width() const {
    return settings.width;
}

int wxGWindow::height() const {
    return settings.height;
}

Rect2D wxGWindow::dimensions () const {
    wxGWindow* t = const_cast<wxGWindow*>(this);
    window->GetPosition(&t->settings.x, &t->settings.y);
    window->GetClientSize(&t->settings.width, &t->settings.height);
    return Rect2D::xywh(settings.x, settings.y, settings.width, settings.height);
}

void wxGWindow::setDimensions (const Rect2D &dims) {
    window->SetSize(dims.x0(), dims.y0(), dims.width(), dims.height());
}

void wxGWindow::setPosition (int x, int y) {
    window->Move(x, y);
}

bool wxGWindow::hasFocus () const {
    return window->IsEnabled() && (wxWindow::FindFocus() == window);
}

void wxGWindow::setGammaRamp (const Array<uint16>& gammaRamp) {
    // Ignore
}

void wxGWindow::setCaption (const std::string& caption) {
    window->SetTitle(caption.c_str());
}

int wxGWindow::numJoysticks () const {
    return 0;
}

std::string wxGWindow::joystickName (unsigned int sticknum) {
    return "";
}

std::string wxGWindow::caption() {
    return std::string(window->GetTitle());
}

void wxGWindow::notifyResize (int w, int h) {
    window->GetPosition(&settings.x, &settings.y);
    window->GetClientSize(&settings.width, &settings.height);
}

void wxGWindow::setRelativeMousePosition(double x, double y) {
    window->WarpPointer(x, y);
}

void wxGWindow::setRelativeMousePosition (const Vector2 &p) {
    window->WarpPointer(p.x, p.y);
}

void wxGWindow::getRelativeMouseState (Vector2 &position, uint8 &mouseButtons) const {
    
    int _x, _y;
    getRelativeMouseState(_x, _y, mouseButtons);
    position.x = (float)_x;
    position.y = (float)_y;
}

void wxGWindow::getRelativeMouseState (int &x, int &y, uint8 &mouseButtons) const {
    
    x = relativeX;
    y = relativeY;

    // Clear mouseButtons and set each button bit.
	mouseButtons = 0;
    mouseButtons |= (buttons[0] ? 1 : 0) << 0;
    mouseButtons |= (buttons[1] ? 1 : 0) << 1;
    mouseButtons |= (buttons[2] ? 1 : 0) << 2;
}

void wxGWindow::getRelativeMouseState (double &x, double &y, uint8 &mouseButtons) const {

    int _x, _y;
    getRelativeMouseState(_x, _y, mouseButtons);
    x = (double)_x;
    y = (double)_y;
}

void wxGWindow::getJoystickState (unsigned int stickNum, Array< float > &axis, Array< bool > &button) {
    // Ignore
}

void wxGWindow::setInputCapture (bool c) {
    if (c) {
        window->CaptureMouse();
        setMouseVisible(false);
    } else {
        window->ReleaseMouse();
        setMouseVisible(true);
    }
}

bool wxGWindow::inputCapture () const {
    return window->HasCapture();
}

void wxGWindow::setMouseVisible (bool b) {
    _mouseVisible = b;
    if (b) {
        window->SetCursor(arrow);
    } else {
        window->SetCursor(invisible);
    }
}

bool wxGWindow::mouseVisible () const {
    return _mouseVisible;
}


bool wxGWindow::pollEvent(GEvent& e) {

    if (keyboardEvents.length() > 0) {
        e = keyboardEvents.popFront();

        return true;
    }

    return false;
}

///////////////////////////////////////////////////////////////////////////////

static SDLKey wxKeyCodeToSDLCode(int w) {
    if ((w >= 'A') && (w <= 'Z')) {
        // Convert to lower case
        return (SDLKey)(w - 'A' + 'a');
    } else if ((w >= '0') && (w <= '9')) {
        return (SDLKey)w;
    } else if (sdlKeyMap.containsKey(w)) {
        return (SDLKey)sdlKeyMap.get(w);
    } else {
        return (SDLKey)0;
    }
}

void wxG3DCanvas::handleKeyUp(wxKeyEvent& event)
{
    if (_gWindow->keyboardEvents.length() > 200) {
        _gWindow->keyboardEvents.clear();
    }

    GEvent e;
    e.key.type = SDL_KEYUP;
    e.key.state = SDL_RELEASED;
    
    e.key.keysym.sym = wxKeyCodeToSDLCode(event.KeyCode());

#if (wxUSE_UNICODE == 1)
    e.key.keysym.unicode = event.GetUnicodeKey();
#elif defined(wxHAS_RAW_KEY_CODES)
    e.key.keysym.unicode = event.GetRawKeyCode();
#else
    e.key.keysym.unicode = e.key.keysym.sym;
#endif

#if defined(wxHAS_RAW_KEY_CODES)
    e.key.keysym.scancode = event.GetRawKeyCode();
#else
    e.key.keysym.scancode = 0;
#endif

    _gWindow->keyboardEvents.pushBack(e);
    event.Skip();
}


void wxG3DCanvas::handleKeyDown(wxKeyEvent& event) {
    if (_gWindow->keyboardEvents.length() > 200) {
        _gWindow->keyboardEvents.clear();
    }

    GEvent e;
    e.key.type = SDL_KEYDOWN;
    e.key.state = SDL_PRESSED;
    
    e.key.keysym.sym = wxKeyCodeToSDLCode(event.KeyCode());

#if (wxUSE_UNICODE == 1)
    e.key.keysym.unicode = event.GetUnicodeKey();
#elif defined(wxHAS_RAW_KEY_CODES)
    e.key.keysym.unicode = event.GetRawKeyCode();
#else
    e.key.keysym.unicode = e.key.keysym.sym;
#endif

#if defined(wxHAS_RAW_KEY_CODES)
    e.key.keysym.scancode = event.GetRawKeyCode();
#else
    e.key.keysym.scancode = 0;
#endif

    _gWindow->keyboardEvents.pushBack(e);
    event.Skip();
}


void wxG3DCanvas::handleMouseLeftUp(wxMouseEvent& event) {
    if (_gWindow->keyboardEvents.length() > 200) {
        _gWindow->keyboardEvents.clear();
    }

    GEvent e;
    e.key.type = SDL_KEYUP;
    e.key.state = SDL_RELEASED;
    e.key.keysym.sym = (SDLKey)SDL_LEFT_MOUSE_KEY;
    e.key.keysym.unicode = ' ';
    e.key.keysym.scancode = 0;
    e.key.keysym.mod = KMOD_NONE;

    _gWindow->keyboardEvents.pushBack(e);

    _gWindow->buttons[0] = 0;
    event.Skip();
}


void wxG3DCanvas::handleMouseLeftDown(wxMouseEvent& event) {
    if (_gWindow->keyboardEvents.length() > 200) {
        _gWindow->keyboardEvents.clear();
    }

    GEvent e;
    e.key.type = SDL_KEYDOWN;
    e.key.state = SDL_PRESSED;
    e.key.keysym.sym = (SDLKey)SDL_LEFT_MOUSE_KEY;
    e.key.keysym.unicode = ' ';
    e.key.keysym.scancode = 0;
    e.key.keysym.mod = KMOD_NONE;

    _gWindow->keyboardEvents.pushBack(e);

    _gWindow->buttons[0] = 1;

    event.Skip();
}


void wxG3DCanvas::handleMouseRightUp(wxMouseEvent& event) {
    if (_gWindow->keyboardEvents.length() > 200) {
        _gWindow->keyboardEvents.clear();
    }

    GEvent e;
    e.key.type = SDL_KEYUP;
    e.key.state = SDL_RELEASED;
    e.key.keysym.sym = (SDLKey)SDL_RIGHT_MOUSE_KEY;
    e.key.keysym.unicode = ' ';
    e.key.keysym.scancode = 0;
    e.key.keysym.mod = KMOD_NONE;

    _gWindow->keyboardEvents.pushBack(e);

    _gWindow->buttons[2] = 0;
    event.Skip();
}


void wxG3DCanvas::handleMouseRightDown(wxMouseEvent& event) {
    if (_gWindow->keyboardEvents.length() > 200) {
        _gWindow->keyboardEvents.clear();
    }

    GEvent e;
    e.key.type = SDL_KEYDOWN;
    e.key.state = SDL_PRESSED;
    e.key.keysym.sym = (SDLKey)SDL_RIGHT_MOUSE_KEY;
    e.key.keysym.unicode = ' ';
    e.key.keysym.scancode = 0;
    e.key.keysym.mod = KMOD_NONE;

    _gWindow->keyboardEvents.pushBack(e);

    _gWindow->buttons[2] = 1;
    event.Skip();
}


void wxG3DCanvas::handleMouseMiddleUp(wxMouseEvent& event) {
    if (_gWindow->keyboardEvents.length() > 200) {
        _gWindow->keyboardEvents.clear();
    }

    GEvent e;
    e.key.type = SDL_KEYUP;
    e.key.state = SDL_RELEASED;
    e.key.keysym.sym = (SDLKey)SDL_MIDDLE_MOUSE_KEY;
    e.key.keysym.unicode = ' ';
    e.key.keysym.scancode = 0;
    e.key.keysym.mod = KMOD_NONE;

    _gWindow->keyboardEvents.pushBack(e);

    _gWindow->buttons[1] = 0;
    event.Skip();
}


void wxG3DCanvas::handleMouseMiddleDown(wxMouseEvent& event) {
    if (_gWindow->keyboardEvents.length() > 200) {
        _gWindow->keyboardEvents.clear();
    }

    GEvent e;
    e.key.type = SDL_KEYDOWN;
    e.key.state = SDL_PRESSED;
    e.key.keysym.sym = (SDLKey)SDL_MIDDLE_MOUSE_KEY;
    e.key.keysym.unicode = ' ';
    e.key.keysym.scancode = 0;
    e.key.keysym.mod = KMOD_NONE;

    _gWindow->keyboardEvents.pushBack(e);

    _gWindow->buttons[1] = 1;
    event.Skip();
}


void wxG3DCanvas::handleMouseMove(wxMouseEvent& event) {

    _gWindow->relativeX = event.m_x;
    _gWindow->relativeY = event.m_y;
    event.Skip();
}


void wxG3DCanvas::handleWindowMove(wxMoveEvent& event) {

    wxPoint& point = event.GetPosition();
    _gWindow->clientX = point.x;
    _gWindow->clientY = point.y;

    _gWindow->settings.x = point.x;
    _gWindow->settings.y = point.y;
    event.Skip();
}


void wxG3DCanvas::handleWindowClose(wxCloseEvent& event) {

    if (_gWindow->keyboardEvents.length() > 200) {
        _gWindow->keyboardEvents.clear();
    }

    GEvent e;
    e.key.type = SDL_QUIT;

    _gWindow->keyboardEvents.pushBack(e);
    event.Skip();
}


static void initWXKeys() {

    sdlKeyMap.set(WXK_BACK, SDLK_BACKSPACE);
    sdlKeyMap.set(WXK_TAB, SDLK_TAB);
    sdlKeyMap.set(WXK_RETURN, SDLK_RETURN);
    sdlKeyMap.set(WXK_ESCAPE, SDLK_ESCAPE);
    sdlKeyMap.set(WXK_SPACE, SDLK_SPACE);
    sdlKeyMap.set(WXK_DELETE, SDLK_DELETE);

//    sdlKeyMap.set(WXK_START, SDLK_START);
    sdlKeyMap.set(WXK_LBUTTON, SDL_LEFT_MOUSE_KEY);
    sdlKeyMap.set(WXK_RBUTTON, SDL_RIGHT_MOUSE_KEY);
//    sdlKeyMap.set(WXK_CANCEL, SDLK_CANCEL);
    sdlKeyMap.set(WXK_MBUTTON, SDL_MIDDLE_MOUSE_KEY);
    sdlKeyMap.set(WXK_CLEAR, SDLK_CLEAR);
//    sdlKeyMap.set(WXK_SHIFT, SDLK_SHIFT);
//    sdlKeyMap.set(WXK_CONTROL, SDLK_CONTROL);
//    sdlKeyMap.set(WXK_MENU, SDLK_ALT);
    sdlKeyMap.set(WXK_PAUSE, SDLK_PAUSE);
    sdlKeyMap.set(WXK_CAPITAL, SDLK_CAPSLOCK);
//    sdlKeyMap.set(WXK_PRIOR, SDLK_PRIOR);
//    sdlKeyMap.set(WXK_NEXT, SDLK_NEXT);
    sdlKeyMap.set(WXK_END, SDLK_END);
    sdlKeyMap.set(WXK_HOME, SDLK_HOME);
    sdlKeyMap.set(WXK_LEFT, SDLK_LEFT);
    sdlKeyMap.set(WXK_UP, SDLK_UP);
    sdlKeyMap.set(WXK_RIGHT, SDLK_RIGHT);
    sdlKeyMap.set(WXK_DOWN, SDLK_DOWN);
//    sdlKeyMap.set(WXK_SELECT, SDLK_SELECT);
    sdlKeyMap.set(WXK_PRINT, SDLK_PRINT);
//    sdlKeyMap.set(WXK_EXECUTE, SDLK_EXECUTE);
    sdlKeyMap.set(WXK_SNAPSHOT, SDLK_PRINT);
    sdlKeyMap.set(WXK_INSERT, SDLK_INSERT);
    sdlKeyMap.set(WXK_HELP, SDLK_HELP);
    sdlKeyMap.set(WXK_NUMPAD0, SDLK_KP0);
    sdlKeyMap.set(WXK_NUMPAD1, SDLK_KP1);
    sdlKeyMap.set(WXK_NUMPAD2, SDLK_KP2);
    sdlKeyMap.set(WXK_NUMPAD3, SDLK_KP3);
    sdlKeyMap.set(WXK_NUMPAD4, SDLK_KP4);
    sdlKeyMap.set(WXK_NUMPAD5, SDLK_KP5);
    sdlKeyMap.set(WXK_NUMPAD6, SDLK_KP6);
    sdlKeyMap.set(WXK_NUMPAD7, SDLK_KP7);
    sdlKeyMap.set(WXK_NUMPAD8, SDLK_KP8);
    sdlKeyMap.set(WXK_NUMPAD9, SDLK_KP9);
    sdlKeyMap.set(WXK_MULTIPLY, SDLK_KP_MULTIPLY);
    sdlKeyMap.set(WXK_ADD, SDLK_KP_PLUS);
//    sdlKeyMap.set(WXK_SEPARATOR, 
    sdlKeyMap.set(WXK_SUBTRACT, SDLK_MINUS);
    sdlKeyMap.set(WXK_DECIMAL, SDLK_PERIOD);
    sdlKeyMap.set(WXK_DIVIDE, SDLK_SLASH);
    sdlKeyMap.set(WXK_F1, SDLK_F1);
    sdlKeyMap.set(WXK_F2, SDLK_F2);
    sdlKeyMap.set(WXK_F3, SDLK_F3);
    sdlKeyMap.set(WXK_F4, SDLK_F4);
    sdlKeyMap.set(WXK_F5, SDLK_F5);
    sdlKeyMap.set(WXK_F6, SDLK_F6);
    sdlKeyMap.set(WXK_F7, SDLK_F7);
    sdlKeyMap.set(WXK_F8, SDLK_F8);
    sdlKeyMap.set(WXK_F9, SDLK_F9);
    sdlKeyMap.set(WXK_F10, SDLK_F10);
    sdlKeyMap.set(WXK_F11, SDLK_F11);
    sdlKeyMap.set(WXK_F12, SDLK_F12);
    sdlKeyMap.set(WXK_F13, SDLK_F13);
    sdlKeyMap.set(WXK_F14, SDLK_F14);
    sdlKeyMap.set(WXK_F15, SDLK_F15);
//    sdlKeyMap.set(WXK_F16, SDLK_F16);
//    sdlKeyMap.set(WXK_F17, SDLK_F17);
//    sdlKeyMap.set(WXK_F18, SDLK_F18);
//    sdlKeyMap.set(WXK_F19, SDLK_F19);
//    sdlKeyMap.set(WXK_F20, SDLK_F20);
//    sdlKeyMap.set(WXK_F21, SDLK_F21);
//    sdlKeyMap.set(WXK_F22, SDLK_F22);
//    sdlKeyMap.set(WXK_F23, SDLK_F23);
//    sdlKeyMap.set(WXK_F24, SDLK_F24);
    sdlKeyMap.set(WXK_NUMLOCK, SDLK_NUMLOCK);
    sdlKeyMap.set(WXK_SCROLL, SDLK_SCROLLOCK);
    sdlKeyMap.set(WXK_PAGEUP, SDLK_PAGEUP);
    sdlKeyMap.set(WXK_PAGEDOWN, SDLK_PAGEDOWN);

//    sdlKeyMap.set(WXK_NUMPAD_SPACE, SDLK_KP_SPACE);
//    sdlKeyMap.set(WXK_NUMPAD_TAB, SDLK_KP_TAB);
    sdlKeyMap.set(WXK_NUMPAD_ENTER, SDLK_KP_ENTER);
//    sdlKeyMap.set(WXK_NUMPAD_EQUALS, SDLK_KP_EQUALS);
//    sdlKeyMap.set(WXK_NUMPAD_SUBSTRACT, SDLK_KP_MINUS);
    sdlKeyMap.set(WXK_NUMPAD_DIVIDE, SDLK_KP_DIVIDE);
    sdlKeyMap.set(WXK_NUMPAD_DECIMAL, SDLK_KP_PERIOD);

    // the following key codes are only generated under Windows currently
    sdlKeyMap.set(WXK_WINDOWS_LEFT, SDLK_LSUPER);
    sdlKeyMap.set(WXK_WINDOWS_RIGHT, SDLK_RSUPER);
    sdlKeyMap.set(WXK_WINDOWS_MENU, SDLK_MENU);
}
