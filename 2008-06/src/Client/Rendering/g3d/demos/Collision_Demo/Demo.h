#ifndef DEMO_H
#define DEMO_H

#include <G3DAll.h>
#include "Scene.h"

/**
 This simple demo applet uses the debug mode as the regular
 rendering mode so you can fly around the scene.
 */
class Demo : public GApplet {
private:

    void buildScene();

    void insertRamps();
    void insertSpiralSlide();
    void insertRollingContactSpheres();
    void insertTray();
    void insertRestingContactSpheres();

public:

    // Add state that should be visible to this applet.
    // If you have multiple applets that need to share
    // state, put it in the App.

    class App*              app;

    Scene                   scene;

    /** World time */
    GameTime                gameTime;

    /** Time at which the simulation started; used to reset when it gets boring.*/
    RealTime                simStartTime;

    Demo(App* app);

    virtual ~Demo();

    virtual void onInit();

    virtual void onSimulation(RealTime rdt, SimTime sdt, SimTime idt);

    virtual void onGraphics(RenderDevice*rd);
};

#endif
