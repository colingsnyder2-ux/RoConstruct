#include "OgreGLSupport.h"
#include "OgreGLContext.h"
#include "OgreGLRenderSystem.h"
#include "OgreRenderWindow.h"
#include "OgreViewport.h"
#include "OgreException.h"
#include "OgreImage.h"
#include <emscripten/html5.h>
#include <emscripten/html5_webgl.h>
// Emscripten's desktop-compatible resolver includes legacy shader-emulation
// functions; the html5 WebGL resolver intentionally contains only WebGL calls.
extern "C" void* emscripten_GetProcAddress(const char*);

namespace Ogre {
class BrowserContext : public GLContext {
public:
    EMSCRIPTEN_WEBGL_CONTEXT_HANDLE handle;
    BrowserContext() : handle(0) {}
    void setCurrent() {
        if (emscripten_webgl_make_context_current(handle) != EMSCRIPTEN_RESULT_SUCCESS)
            OGRE_EXCEPT(Exception::ERR_RENDERINGAPI_ERROR, "Cannot activate browser GL context", "BrowserContext");
    }
    void endCurrent() { emscripten_webgl_make_context_current(0); }
    GLContext* clone() const {
        OGRE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "Demo uses one browser GL context", "BrowserContext::clone");
    }
};

class BrowserWindow : public RenderWindow {
    BrowserContext context;
    bool closed;
public:
    BrowserWindow() : closed(true) {}
    ~BrowserWindow() { destroy(); }
    void create(const String& name, unsigned width, unsigned height, bool fullscreen,
                const NameValuePairList*) {
        EmscriptenWebGLContextAttributes attributes;
        emscripten_webgl_init_context_attributes(&attributes);
        attributes.majorVersion = 2;
        attributes.minorVersion = 0;
        attributes.depth = true;
        attributes.stencil = true;
        attributes.alpha = false;
        attributes.antialias = false;
        attributes.preserveDrawingBuffer = true;
        context.handle = emscripten_webgl_create_context("#canvas", &attributes);
        if (context.handle <= 0)
            OGRE_EXCEPT(Exception::ERR_RENDERINGAPI_ERROR, "WebGL 2 context creation failed", "BrowserWindow::create");
        context.setCurrent();
        // Direct html5 context creation bypasses Emscripten Browser.createContext.
        // Run the same initialization hook used by its legacy-GL shader layer.
        EM_ASM({ Module['ctx'] = GLctx; Browser.useWebGL = true;
                 Browser.moduleContextCreatedCallbacks.forEach(callback => callback());
                 Browser.init(); });
        mName = name;
        mColourDepth = 32;
        mLeft = mTop = 0;
        mIsFullScreen = fullscreen;
        mActive = true;
        closed = false;
        resize(width, height);
    }
    void destroy() {
        if (!closed) emscripten_webgl_destroy_context(context.handle);
        context.handle = 0;
        closed = true;
        mActive = false;
    }
    bool isClosed() const { return closed; }
    bool requiresTextureFlipping() const { return false; }
    void resize(unsigned width, unsigned height) {
        mWidth = width;
        mHeight = height;
        emscripten_set_canvas_element_size("#canvas", width, height);
        for (ViewportList::iterator i = mViewportList.begin(); i != mViewportList.end(); ++i)
            i->second->_updateDimensions();
    }
    void reposition(int left, int top) {
        mLeft = left;
        mTop = top;
        EM_ASM({ var c = document.querySelector('#canvas'); c.style.position = 'relative';
                 c.style.left = $0 + 'px'; c.style.top = $1 + 'px'; }, left, top);
    }
    void swapBuffers(bool) {
        // Browser presents the default framebuffer after the animation callback.
        glFlush();
    }
    void getCustomAttribute(const String& name, void* output) {
        if (name == "GLCONTEXT") *static_cast<GLContext**>(output) = &context;
        else RenderTarget::getCustomAttribute(name, output);
    }
    void writeContentsToFile(const String& filename) {
        std::vector<unsigned char> pixels(mWidth * mHeight * 4);
        glReadPixels(0, 0, mWidth, mHeight, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[0]);
        Image image;
        image.loadDynamicImage(&pixels[0], mWidth, mHeight, 1, PF_BYTE_RGBA);
        image.flipAroundX();
        image.save(filename);
    }
};

class BrowserGLSupport : public GLSupport {
public:
    void addConfig() {
        ConfigOption mode;
        mode.name = "Video Mode";
        mode.currentValue = "960 x 640";
        mode.possibleValues.push_back(mode.currentValue);
        mode.immutable = true;
        mOptions[mode.name] = mode;
        ConfigOption rtt;
        rtt.name = "RTT Preferred Mode";
        rtt.currentValue = "FBO";
        rtt.possibleValues.push_back("FBO");
        rtt.immutable = true;
        mOptions[rtt.name] = rtt;
    }
    String validateConfig() { return ""; }
    void start() { emscripten_set_canvas_element_size("#canvas", 960, 640); }
    void stop() { emscripten_webgl_make_context_current(0); }
    RenderWindow* createWindow(bool automatic, GLRenderSystem* renderer, const String& title) {
        return automatic ? renderer->createRenderWindow(title, 960, 640, false) : 0;
    }
    RenderWindow* newWindow(const String& name, unsigned width, unsigned height, bool fullscreen,
                            const NameValuePairList* params) {
        BrowserWindow* window = new BrowserWindow;
        try { window->create(name, width, height, fullscreen, params); }
        catch (...) { delete window; throw; }
        return window;
    }
    void* getProcAddress(const String& name) {
        if (name == "glGetProgramivARB") return 0; // ARB assembly, not a GLSL program query.
        return emscripten_GetProcAddress(name.c_str());
    }
};
GLSupport* getGLSupport() { return new BrowserGLSupport; }
}
