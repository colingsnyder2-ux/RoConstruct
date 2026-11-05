/**
 @file Collision_Demo/main.cpp

 <P>
 This demo uses the G3D collision detection routines to implement a simple physics
 system.  
 <P>

 This is not the greatest collision simulation ever written-- see OPCODE for
 better collision detection and Guendelman et. al's SIGGRAPH 2003 paper for better
 simulation.
 
 G3D's collision detection routines are intended for convenient bounding volume
 tests and ray casting, not high-performance collision detection, so this is 
 really a stress test.
  
 <P>
 Requires:
   OpenGL
   <A HREF="http://www.libsdl.org">SDL</A>
   G3D
   GLG3D

 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2003-02-07
 @edited  2006-01-29
 */
#include <G3DAll.h>
#include "Model.h"
#include "Object.h"
#include "Scene.h"
#include "Demo.h"

GApp*                app            = NULL;
VARAreaRef           varStatic      = NULL;

class App : public GApp {
protected:
    void main();
public:
    App(const GAppSettings& settings);
};


const double                  maxFrameRate    = 30.5;


Demo::Demo(App* _app) : GApplet(_app), app(_app), gameTime(0) {
    // Allocate the two VARAreas used in this demo
    ::varStatic    = VARArea::create(1024 * 1024);
    debugAssert(::varStatic.notNull());
}


void Demo::onInit()  {
    app->debugCamera.setPosition(Vector3(15, 20, 15));
    app->debugCamera.lookAt(Vector3(-2,3,-5));
    app->debugController.setActive(false);

    debugAssertGLOk();
    buildScene();
    debugAssertGLOk();
    
    gameTime     = G3D::toSeconds(10, 00, 00, AM); 

    setDesiredFrameRate(60);
    simStartTime = System::time();
}


Demo::~Demo() {
    app->debugLog->printf("Static VAR peak size was  %d bytes.\n",
                     varStatic->peakAllocatedSize());
    ::varStatic = NULL;
}

void Demo::onSimulation(RealTime rdt, SimTime sdt, SimTime idt) {
    if (simStartTime + 10 < System::time()) {
        // Periodically reset
        scene.clear();
        buildScene();
        simStartTime = System::time();
    }

    scene.simulate(idt);
}


void Demo::onGraphics(RenderDevice* rd) {
    rd->pushState();
    
    rd->setProjectionAndCameraMatrix(app->debugCamera);
        
        LightingParameters lighting(gameTime);
        lighting.lightDirection = (lighting.lightDirection + Vector3(0,0,.4f)).direction();
        lighting.ambient = lighting.ambient + Color3(.3f,.3f,.4f);

        scene.render(lighting);
    rd->popState();
}


void App::main() {
    debugAssertGLOk();
    setDebugMode(true);
    debugQuitOnEscape = true;
    Demo(this).run();
}


App::App(const GAppSettings& settings) : GApp(settings) {
}


int main(int argc, char** argv) {
    app = new App(GAppSettings());
    app->run();
    Model::freeModels();
    delete app;

    return 0;
}
