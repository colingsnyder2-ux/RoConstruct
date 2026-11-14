// Generated with the frozen demo's real classes, geometry construction and frame
// logic. Only window creation, input, timing and the browser loop are adapted.
// NATIVE_PREFIX
#include "OgreGLPlugin.h"
#include <emscripten.h>
#include <emscripten/html5.h>
namespace Ogre { void registerBrowserImageCodecs(); }

class CastleApp {
public:
    DemoFactory factory;
    Ogre::Root* rootHandle;
    Ogre::RenderWindow* window;
    Ogre::SceneManager* scene;
    Ogre::Camera* camera;
    Ogre::Light* sun;
    Ogre::VisualEngine skyContext;
    G3D::LightingParameters lighting;
    Ogre::TwoDManager hud;
    Ogre::FrameHistory history;
    float yaw = 0.65f, pitch = 0.48f;
    bool orbit = false, dragging = false, hudVisible = true, wireframe = false;
    bool shadows = true, cycle = true, celestial = false;
    bool keys[256] = {}, lastKeys[7] = {}, lastSpace = false;
    double clockSeconds = 14 * 3600, daySeconds = 90, last;
    int mouseX = 0, mouseY = 0, previousX = 0, previousY = 0, frameCount = 0;

    CastleApp() : rootHandle(0), lighting(14 * 3600.0, true) {
        // NATIVE_SETUP
        emscripten_set_keydown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, this, true, keyboard);
        emscripten_set_keyup_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, this, true, keyboard);
        emscripten_set_mousedown_callback("#canvas", this, true, mouse);
        emscripten_set_mouseup_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, this, true, mouse);
        emscripten_set_mousemove_callback("#canvas", this, true, mouse);
        emscripten_set_wheel_callback("#canvas", this, true, wheel);
        last = emscripten_get_now();
        std::puts("Native RBX castle initialized");
    }
    static EM_BOOL keyboard(int type, const EmscriptenKeyboardEvent* event, void* pointer) {
        CastleApp& app = *static_cast<CastleApp*>(pointer);
        int code = event->keyCode;
        if (code >= 256) return false;
        app.keys[code] = type == EMSCRIPTEN_EVENT_KEYDOWN;
        if (code == 27 && type == EMSCRIPTEN_EVENT_KEYDOWN) {
            app.cycle = false; app.orbit = false;
            emscripten_cancel_main_loop();
            EM_ASM({document.querySelector('#status').textContent = 'Stopped — reload to restart';});
        }
        return code == 32 || code == 27 || code == 'H' || code == 'W' || code == 'S' ||
            code == 'D' || code == 'T' || code == 'P' || code == 'C' || code == 'R';
    }
    static EM_BOOL mouse(int type, const EmscriptenMouseEvent* event, void* pointer) {
        CastleApp& app = *static_cast<CastleApp*>(pointer);
        if (type == EMSCRIPTEN_EVENT_MOUSEDOWN && event->button == 0) {
            app.dragging = true;
            app.previousX = event->targetX; app.previousY = event->targetY;
            EM_ASM({document.querySelector('#canvas').focus();});
        }
        if (type == EMSCRIPTEN_EVENT_MOUSEUP) app.dragging = false;
        app.mouseX = event->targetX; app.mouseY = event->targetY;
        return true;
    }
    static EM_BOOL wheel(int, const EmscriptenWheelEvent* event, void*) {
        zoom *= event->deltaY < 0 ? 0.9f : 1.1f;
        zoom = std::max(18.0f, std::min(zoom, 85.0f));
        return true;
    }
    void frame() {
        try {
            double now = emscripten_get_now();
            float dt = (now - last) * 0.001;
            last = now;
            double width, height;
            emscripten_get_element_css_size("#canvas", &width, &height);
            if (width > 0 && height > 0 && (unsigned(width) != window->getWidth() || unsigned(height) != window->getHeight())) {
                window->resize(width, height);
                camera->setAspectRatio(width / height);
            }
            bool down = dragging;
            bool space = keys[32];
            if (space && !lastSpace) orbit = !orbit;
            lastSpace = space;
            if (dragging) { yaw -= (mouseX - previousX) * 0.008f; pitch += (mouseY - previousY) * 0.008f; }
            previousX = mouseX; previousY = mouseY;
            const int keyCodes[7] = {'H', 'W', 'S', 'D', 'T', 'P', 'C'};
            for (int k = 0; k < 7; ++k) {
                bool pressed = keys[keyCodes[k]];
                if (pressed && !lastKeys[k]) {
                    if (k == 0) hudVisible = !hudVisible;
                    if (k == 1) { wireframe = !wireframe; camera->setPolygonMode(wireframe ? Ogre::PM_WIREFRAME : Ogre::PM_SOLID); }
                    if (k == 2) { shadows = !shadows; scene->setShadowTechnique(shadows ? Ogre::SHADOWTYPE_STENCIL_MODULATIVE : Ogre::SHADOWTYPE_NONE); }
                    if (k == 3) cycle = true;
                    if (k == 4) clockSeconds = fmod(clockSeconds + 3 * 3600, 86400.0);
                    if (k == 5) cycle = false;
                    if (k == 6) celestial = !celestial;
                }
                lastKeys[k] = pressed;
            }
            if (cycle) clockSeconds = fmod(clockSeconds + dt * 86400 / daySeconds, 86400.0);
            // NATIVE_FRAME
            window->Ogre::RenderTarget::update();
            bool repeatHud = false;
            hud.renderQueueEnded(Ogre::RENDER_QUEUE_OVERLAY, "", repeatHud);
            window->swapBuffers(false);
            ++frameCount;
            EM_ASM({
                Module.castleState = ({clockSeconds: $0, cycle: !!$1, shadows: !!$2,
                    yaw: $3, pitch: $4, zoom: $5, frames: $6, batches: $7, shadowQueries: $8,
                    celestial: !!$9, hud: !!$10, wireframe: !!$11});
                var seconds = Math.floor($0);
                document.querySelector('#status').textContent =
                    String(Math.floor(seconds / 3600)).padStart(2,'0') + ':' +
                    String(Math.floor(seconds / 60) % 60).padStart(2,'0') +
                    ($1 ? ' · running' : ' · paused');
            }, clockSeconds, cycle, shadows, yaw, pitch, zoom, frameCount,
                static_cast<DemoSceneManager*>(scene)->parts.size(),
                static_cast<DemoSceneManager*>(scene)->shadowQueries, celestial, hudVisible, wireframe);
        } catch (const Ogre::Exception& error) {
            std::fprintf(stderr, "Castle frame failed: %s\n", error.getFullDescription().c_str());
            emscripten_cancel_main_loop();
        }
    }
};
CastleApp* castle;
extern "C" EMSCRIPTEN_KEEPALIVE void castle_set_time(double hour) {
    castle->clockSeconds = fmod(hour * 3600 + 86400, 86400.0);
}
int main() {
    try {
        castle = new CastleApp;
        emscripten_set_main_loop_arg([](void* pointer) { static_cast<CastleApp*>(pointer)->frame(); }, castle, 0, true);
    } catch (const Ogre::Exception& error) {
        std::fprintf(stderr, "Castle initialization failed: %s\n", error.getFullDescription().c_str());
        return 1;
    }
}
