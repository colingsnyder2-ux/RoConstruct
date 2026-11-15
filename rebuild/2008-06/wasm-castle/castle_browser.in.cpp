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
    int activeScene=0;
    DemoSubEntity* windmillRotor=nullptr;
    DemoSubEntity* windmillHub=nullptr;
    unsigned windmillHubKey=0;
    unsigned windmillTransformKey=0;
    float windmillAngle=0;
    float yaw = 0.65f, pitch = 0.48f;
    bool orbit = false, dragging = false, hudVisible = false, wireframe = false;
    bool shadows = true, cycle = true, celestial = false;
    bool keys[256] = {}, lastKeys[7] = {}, lastSpace = false;
    double clockSeconds = 14 * 3600, daySeconds = 90, last;
    double fpsStart=0,statusStart=0,fps=0;
    int fpsFrames=0;
    int mouseX = 0, mouseY = 0, previousX = 0, previousY = 0, frameCount = 0;

    CastleApp() : rootHandle(0), lighting(14 * 3600.0, true) {
        // NATIVE_SETUP
        EM_ASM({Module.castleGeometry=({grid:0.5,studSurfaceFaces:$0,beveledBlocks:$1,blocks:[]});},castleStudCount,castleBevelCount);
        for(const auto& block:castleBlocks) {
            EM_ASM({Module.castleGeometry.blocks.push(({center:[$0,$1,$2],size:[$3,$4,$5],material:UTF8ToString($6),studs:!!$7}));},
                block.center.x,block.center.y,block.center.z,block.size.x,block.size.y,block.size.z,block.material.c_str(),block.studs);
        }
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
            if(EM_ASM_INT({return !!document.fullscreenElement;})) {
                EM_ASM({document.exitFullscreen();});return true;
            }
            app.cycle = false; app.orbit = false;
            emscripten_cancel_main_loop();
            EM_ASM({document.querySelector('#status').textContent = 'Stopped — reload to restart';});
        }
        return code == 32 || code == 27 || code == 'W' || code == 'S' ||
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
            if(!fpsStart) fpsStart=now;
            ++fpsFrames;
            if(now-fpsStart>=500) {fps=fpsFrames*1000.0/(now-fpsStart);fpsFrames=0;fpsStart=now;}
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
                    if (k == 1) { wireframe = !wireframe; camera->setPolygonMode(wireframe ? Ogre::PM_WIREFRAME : Ogre::PM_SOLID); }
                    if (k == 2) { shadows = !shadows; scene->setShadowTechnique(shadows ? Ogre::SHADOWTYPE_STENCIL_MODULATIVE : Ogre::SHADOWTYPE_NONE); }
                    if (k == 3) cycle = true;
                    if (k == 5) cycle = false;
                    if (k == 6) celestial = !celestial;
                }
                lastKeys[k] = pressed;
            }
            if (cycle) clockSeconds = fmod(clockSeconds + dt * (keys['T'] ? 5 : 1) * 86400 / daySeconds, 86400.0);
            // NATIVE_FRAME
            if(cycle)windmillAngle=std::fmod(windmillAngle+dt*0.75f,Ogre::Math::TWO_PI);
            Ogre::Matrix4 rotorTransform;
            rotorTransform.makeTransform(Ogre::Vector3(80,12,6.5f),Ogre::Vector3::UNIT_SCALE,
                Ogre::Quaternion(Ogre::Radian(windmillAngle),Ogre::Vector3::UNIT_Z));
            auto* world=static_cast<DemoSceneManager*>(scene);
            world->worldNode->setTransform(windmillTransformKey,rotorTransform);
            windmillRotor->transform(world->worldNode->getTransform(windmillTransformKey));
            world->worldNode->setTransform(windmillHubKey,rotorTransform);
            windmillHub->transform(world->worldNode->getTransform(windmillHubKey));
            window->Ogre::RenderTarget::update();
            bool repeatHud = false;
            window->swapBuffers(false);
            ++frameCount;
            EM_ASM({
                Module.castleState = ({clockSeconds: $0, cycle: !!$1, shadows: !!$2,
                    yaw: $3, pitch: $4, zoom: $5, frames: $6, batches: $7, shadowQueries: $8,
                    celestial: !!$9, hud: false, wireframe: !!$11, fps:$12, orbit:!!$13, fullscreen:!!document.fullscreenElement, scene:$14, windmillAngle:$15});
                document.querySelector('h1').textContent=$14?'Windmill Island':'Castle Island';
                document.getElementById('game-name').textContent=$14?'ROCONSTRUCT / WINDMILL ISLAND':'ROCONSTRUCT / CASTLE ISLAND';
                var seconds = Math.floor($0);
                document.querySelector('#status').textContent = '';
            }, clockSeconds, cycle, shadows, yaw, pitch, zoom, frameCount,
                static_cast<DemoSceneManager*>(scene)->parts.size(),
                static_cast<DemoSceneManager*>(scene)->shadowQueries, celestial, hudVisible, wireframe,fps,orbit,activeScene,windmillAngle);
            Ogre::Vector3 cameraPosition=camera->getPosition();
            Ogre::Quaternion cameraRotation=camera->getOrientation();
            EM_ASM({Module.castleState.position=([$0,$1,$2]);Module.castleState.rotation=([$3,$4,$5]);Module.castleState.orientation=([$6,$7,$8,$9]);},
                cameraPosition.x,cameraPosition.y,cameraPosition.z,
                cameraRotation.getPitch().valueDegrees(),cameraRotation.getYaw().valueDegrees(),cameraRotation.getRoll().valueDegrees(),
                cameraRotation.x,cameraRotation.y,cameraRotation.z,cameraRotation.w);
            if(now-statusStart>200) {
                statusStart=now;
                EM_ASM({var frame=document.getElementById('toolbar');if(frame)frame.contentWindow.postMessage({type:'castle-status',state:Module.castleState},location.origin);});
            }
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
extern "C" EMSCRIPTEN_KEEPALIVE void castle_set_view(float yaw,float pitch,float distance,double seconds) {
    castle->yaw=yaw;castle->pitch=pitch;zoom=distance;
    castle->clockSeconds=seconds;castle->cycle=false;castle->orbit=false;castle->celestial=false;
    castle->activeScene=0;
}
extern "C" EMSCRIPTEN_KEEPALIVE void castle_set_scene_view(int scene,float yaw,float pitch,float distance,double seconds,float angle) {
    castle_set_view(yaw,pitch,distance,seconds);
    castle->activeScene=scene;castle->windmillAngle=angle;
}
extern "C" EMSCRIPTEN_KEEPALIVE void castle_set_reflectance(float amount) {
    applyWindowReflectance(Ogre::MaterialManager::getSingleton().getByName("Windmill glass"),amount);
}
extern "C" EMSCRIPTEN_KEEPALIVE void castle_set_shadow_bias(float bias) {
    static_cast<DemoSceneManager*>(castle->scene)->stencilBias(bias);
}
extern "C" EMSCRIPTEN_KEEPALIVE void castle_command(int command) {
    if(!castle)return;
    if(command==100)castle->cycle=true;
    if(command==101)castle->cycle=false;
    if(command==102){castle->yaw=0.65f;castle->pitch=0.48f;zoom=castle->activeScene?44:42;castle->celestial=false;}
    if(command==103){castle->shadows=!castle->shadows;castle->scene->setShadowTechnique(castle->shadows?Ogre::SHADOWTYPE_STENCIL_MODULATIVE:Ogre::SHADOWTYPE_NONE);}
    if(command==104)castle->orbit=!castle->orbit;
    if(command==105)castle->celestial=!castle->celestial;
    if(command==106){castle->wireframe=!castle->wireframe;castle->camera->setPolygonMode(castle->wireframe?Ogre::PM_WIREFRAME:Ogre::PM_SOLID);}
    if(command==107)castle->clockSeconds=fmod(castle->clockSeconds+10800,86400.0);
    if(command==200||command==201){castle->activeScene=command-200;castle->yaw=0.65f;castle->pitch=0.48f;zoom=castle->activeScene?44:42;castle->celestial=false;}
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

