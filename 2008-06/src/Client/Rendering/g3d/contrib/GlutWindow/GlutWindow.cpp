/**
 @file GlutWindow.cpp
 @author Morgan McGuire and Dan Keefe
 */
#include "GlutWindow.h"

GlutWindow* GlutWindow::currentGlutWindow = NULL;
bool GlutWindow::glutInitialized = false;

void GlutWindow::postEvent(GEvent& evt) {
    eventQueue.pushBack(evt);
}

void GlutWindow::g_draw() {
    if (currentGlutWindow->notDone()) {
        currentGlutWindow->executeLoopBody();

        // Request another redisplay
        glutPostRedisplay();
    } else {
        exit(0);
    }
}


void GlutWindow::g_reshape(int width, int height) {
    GEvent e;
    e.resize.type = SDL_VIDEORESIZE;
    e.resize.w = width;
    e.resize.h = height;

    currentGlutWindow->postEvent(e);
}


static void glutToSDLKeyEvent(GEvent& e, unsigned char c) {
    e.key.keysym.unicode = c;

    if ((c >= 'A') && (c <= 'Z')) {
        // Make key codes lower case canonically
        e.key.keysym.sym = (SDLKey)(c - 'A' + 'a');
    } else {
        e.key.keysym.sym = (SDLKey)c;
    }
    e.key.keysym.scancode = 0;

    e.key.keysym.mod = KMOD_NONE;
    int mods = glutGetModifiers();

    if (mods & GLUT_ACTIVE_SHIFT) {
        e.key.keysym.mod = (SDLMod)(e.key.keysym.mod | KMOD_LSHIFT);
    }

    if (mods & GLUT_ACTIVE_CTRL) {
        e.key.keysym.mod = (SDLMod)(e.key.keysym.mod | KMOD_LCTRL);
    }

    if (mods & GLUT_ACTIVE_ALT) {
        e.key.keysym.mod = (SDLMod)(e.key.keysym.mod | KMOD_LALT);
    }

}

void GlutWindow::g_keyboard(unsigned char c, int x, int y) {

    GEvent e;
    e.key.type = SDL_KEYDOWN;
    e.key.state = SDL_PRESSED;

    glutToSDLKeyEvent(e, c);

    currentGlutWindow->postEvent(e);
}


void GlutWindow::g_keyboardspecial(int key, int x, int y) {
    // TODO
}


void GlutWindow::g_keyboardup(unsigned char c, int x, int y) {
    GEvent e;
    e.key.type = SDL_KEYUP;
    e.key.state = SDL_RELEASED;

    glutToSDLKeyEvent(e, c);

    currentGlutWindow->postEvent(e);
}


void GlutWindow::g_keyboardspecialup(int key, int x, int y) {
    // TODO
}


void GlutWindow::g_mousemotion(int x, int y) {
    GEvent e;
    e.motion.type = SDL_MOUSEMOTION;
    e.motion.state = currentGlutWindow->mouseButtons;
    e.motion.xrel = (int16)(x - currentGlutWindow->mouse.x);
    e.motion.yrel = (int16)(y - currentGlutWindow->mouse.y);
    e.motion.x = x;
    e.motion.y = y;

    currentGlutWindow->mouse.x = x;
    currentGlutWindow->mouse.y = y;

    currentGlutWindow->postEvent(e);
}


void GlutWindow::g_mousebtn(int b, int s, int x, int y) {
    currentGlutWindow->mouse.x = x;
    currentGlutWindow->mouse.y = y;

    // Turn corresponding mouseButtons bit on/off and
    // make a GEvent
    GEvent e;

    switch (b) {
    case GLUT_LEFT_BUTTON:
        e.button.button = SDL_BUTTON_LEFT;
        if (s == GLUT_UP) {
            currentGlutWindow->mouseButtons &= 0xFE;
        } else {
            currentGlutWindow->mouseButtons |= 0x01;
        }
        break;

    case GLUT_RIGHT_BUTTON:
        // Button index 1
        e.button.button = SDL_BUTTON_RIGHT;
        if (s == GLUT_UP) {
            currentGlutWindow->mouseButtons &= 0xFD;
        } else {
            currentGlutWindow->mouseButtons |= 0x02;
        }
        break;

    case GLUT_MIDDLE_BUTTON:
        // Button index 2
        e.button.button = SDL_BUTTON_MIDDLE;
        if (s == GLUT_UP) {
            currentGlutWindow->mouseButtons &= 0xFB;
        } else {
            currentGlutWindow->mouseButtons |= 0x04;
        }
        break;
    }

    if (s == GLUT_UP) {
        e.button.type = SDL_MOUSEBUTTONUP;
        e.button.state = SDL_RELEASED;
    } else {
        e.button.type = SDL_MOUSEBUTTONDOWN;
        e.button.state = SDL_PRESSED;
    }

    e.button.x = x;
    e.button.y = y;

    currentGlutWindow->postEvent(e);
}


/** Called from GlutWindow::GlutWindow */
static int computeGlutFlags(const GWindowSettings& settings) {
    int flags = 
        GLUT_RGB |
        GLUT_DOUBLE;
    
    if (settings.stereo) {
        flags |= GLUT_STEREO;
    }

    if (settings.alphaBits > 0) {
        flags |= GLUT_ALPHA;
    }

    if (settings.fsaaSamples > 0) {
        flags |= GLUT_MULTISAMPLE;
    }

    if (settings.stencilBits > 0) {
        flags |= GLUT_STENCIL;
    }

    if (settings.depthBits > 0) {
        flags |= GLUT_DEPTH;
    }

    return flags;
}


static void glutInitDummy() {
    int argc = 1;
    char** argv = (char**)malloc(sizeof(char*));
    argv[0] = "";
    char** argv2 = argv;
    glutInit(&argc, argv2);
    free(argv);
}


GlutWindow::GlutWindow(const GWindowSettings& s) {
    _mouseVisible = true;
    _windowTitle = "G3D";
    settings = s;

    currentGlutWindow = this;

    // Set window size and position
    glutInitWindowSize(settings.width, settings.height);
    glutInitWindowPosition(settings.x, settings.y);   
    glutInitDisplayMode(computeGlutFlags(settings));

    if (! glutInitialized) {
        glutInitDummy();
        glutInitialized = true;
    }

    glutWindowHandle = glutCreateWindow("G3D");

    if (settings.center) {
        glutPositionWindow(
            iMax(0,(glutGet(GLUT_SCREEN_WIDTH) - settings.width) / 2),
            iMax(0,(glutGet(GLUT_SCREEN_HEIGHT) - settings.height) / 2));            
    }

    if (settings.fullScreen) {
        glutFullScreen();
    }

    // See what settings we actually got
    settings.alphaBits = glutGet(GLUT_WINDOW_ALPHA_SIZE);
    settings.depthBits = glutGet(GLUT_WINDOW_DEPTH_SIZE);

    // No gamma ramp on Glut windows
    settings.lightSaturation = 1.0;
    settings.stencilBits = glutGet(GLUT_WINDOW_STENCIL_SIZE);
    settings.fsaaSamples = glutGet(GLUT_WINDOW_NUM_SAMPLES);

    settings.stereo = (glutGet(GLUT_WINDOW_STEREO) != 0);

    mouseButtons = 0;

	#ifdef G3D_LINUX
		if (glXGetCurrentDisplay != NULL) {
			G3D::_internal::x11Display = glXGetCurrentDisplay();
		}

		if (glXGetCurrentDrawable != NULL) {
			G3D::_internal::x11Window  = glXGetCurrentDrawable();
		}
	#endif

    glutReshapeFunc(g_reshape);
    glutKeyboardFunc(g_keyboard);
    glutKeyboardUpFunc(g_keyboardup);
    glutSpecialFunc(g_keyboardspecial);
    glutSpecialUpFunc(g_keyboardspecialup);
    glutMotionFunc(g_mousemotion);
    glutPassiveMotionFunc(g_mousemotion);
    glutMouseFunc(g_mousebtn);
    glutDisplayFunc(g_draw);
}


void GlutWindow::runMainLoop() {
    glutMainLoop();
}


GlutWindow::~GlutWindow() {
    currentGlutWindow = NULL;
    glutDestroyWindow(glutWindowHandle);
}


bool GlutWindow::pollEvent(GEvent& e) {
    if (eventQueue.size() > 0) {
        e = eventQueue.popFront();
        return true;
    } else {
        return false;
    }
}


void GlutWindow::getSettings(GWindowSettings& _settings) const {
    GlutWindow* w = const_cast<GlutWindow*>(this);
    
    w->settings.x = glutGet(GLUT_WINDOW_X);
    w->settings.y = glutGet(GLUT_WINDOW_Y);
    w->settings.width = glutGet(GLUT_WINDOW_WIDTH);
    w->settings.height = glutGet(GLUT_WINDOW_HEIGHT);
    _settings = settings;
}


int GlutWindow::width() const {
    const_cast<GlutWindow*>(this)->settings.width = glutGet(GLUT_WINDOW_WIDTH);
    return settings.width;
}


int GlutWindow::height() const {
    const_cast<GlutWindow*>(this)->settings.height = glutGet(GLUT_WINDOW_HEIGHT);
    return settings.height;
}


Rect2D GlutWindow::dimensions() const {
    GlutWindow* w = const_cast<GlutWindow*>(this);

    w->settings.x = glutGet(GLUT_WINDOW_X);
    w->settings.y = glutGet(GLUT_WINDOW_Y);
    w->settings.width = glutGet(GLUT_WINDOW_WIDTH);
    w->settings.height = glutGet(GLUT_WINDOW_HEIGHT);

    return Rect2D::xywh(settings.x, settings.y, settings.width, settings.height);
}


void GlutWindow::setDimensions(const Rect2D& dims) {
    setPosition((int)dims.x0(), (int)dims.x1());
    glutReshapeWindow((int)dims.width(), (int)dims.height());
}


void GlutWindow::setPosition(int x, int y) {
    glutPositionWindow(x, y);
}


bool GlutWindow::hasFocus() const {
    return true;
}


std::string GlutWindow::getAPIVersion() const {
    return format("%d", GLUT_API_VERSION);
}


std::string GlutWindow::getAPIName() const {
    return "glut";
}


void GlutWindow::setGammaRamp(const Array<uint16>& gammaRamp) {
    // Not supported
}


void GlutWindow::setCaption(const std::string& caption) {
    if (caption != _windowTitle) {
        _windowTitle = caption;
        glutSetWindowTitle(caption.c_str());
        glutSetIconTitle(caption.c_str());
    }
}


int GlutWindow::numJoysticks() const {
    return 0;
}


std::string GlutWindow::joystickName(unsigned int sticknum) {
    return "";
}


std::string GlutWindow::caption() {
    return _windowTitle;
}


void GlutWindow::setIcon(const GImage& image) {}


void GlutWindow::swapGLBuffers() {
    glutSwapBuffers();
}


void GlutWindow::notifyResize(int w, int h) {
    settings.width = w;
    settings.height = h;
}


void GlutWindow::setRelativeMousePosition(double x, double y) {
    glutWarpPointer(iRound(x), iRound(y));
}


void GlutWindow::setRelativeMousePosition(const Vector2& p) {
    setRelativeMousePosition(p.x, p.y);
}


void GlutWindow::getRelativeMouseState(Vector2& position, uint8& b) const {
    position = mouse;
    b = mouseButtons;
}


void GlutWindow::getRelativeMouseState(int& x, int& y, uint8& b) const {
    x = iRound(mouse.x);
    y = iRound(mouse.y);
    b = mouseButtons;
}


void GlutWindow::getRelativeMouseState(double& x, double& y, uint8& b) const {
    x = mouse.x;
    y = mouse.y;
    b = mouseButtons;
}


void GlutWindow::getJoystickState(unsigned int stickNum, Array<float>& axis, Array<bool>& button) {
}


void GlutWindow::setInputCapture(bool c) {
}


bool GlutWindow::inputCapture() const {
    return false;
}


void GlutWindow::setMouseVisible(bool b) {
    if (b != _mouseVisible) {
        _mouseVisible = b;
        if (_mouseVisible) {
            glutSetCursor(GLUT_CURSOR_INHERIT);
        } else {
            glutSetCursor(GLUT_CURSOR_NONE);
        }
    }
}


bool GlutWindow::mouseVisible() const {
    return _mouseVisible;
}
