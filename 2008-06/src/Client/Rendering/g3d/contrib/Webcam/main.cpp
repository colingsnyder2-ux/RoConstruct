// mainp.cpp Sample program mixing webcam with 3D rendering.
// Peter Hunt, p222h@aol.com
// Windows only

#include "stdafx.h"
#include "VideoCapture.h"

#include <G3DAll.h>

#if G3D_VER < 60800
    #error Requires G3D 6.08
#endif

class App : public GApp {
protected:
    void main();
public:
    VideoCapture        camera;
    SkyRef              sky;

    App(const GAppSettings& settings);
};


class Demo : public GApplet {
    TextureRef          video;
public:

    class App*          app;

    Demo(App* app);    

    virtual void init();

    virtual void doLogic();

	virtual void doNetwork();

    virtual void doSimulation(SimTime dt);

    virtual void doGraphics();

    virtual void cleanup();

};


Demo::Demo(App* _app) : GApplet(_app), app(_app) {
}


void Demo::init()  {
    // Called before Demo::run() beings
    app->debugCamera.setPosition(Vector3(0, 2, 10));
    app->debugCamera.lookAt(Vector3(0, 2, 0));
}


void Demo::cleanup() {
    // Called when Demo::run() exits
}


void Demo::doNetwork() {
	// Poll net messages here
}


void Demo::doSimulation(SimTime dt) {
	// Add physical simulation here
    static GImage im;
    app->camera.captureFrame();
    app->camera.getGImage(im);
    video = Texture::fromGImage("Video", im, TextureFormat::RGBA8, Texture::CLAMP, Texture::BILINEAR_NO_MIPMAP, Texture::DIM_2D_RECT);
}


void Demo::doLogic() {
    if (app->userInput->keyPressed(SDLK_ESCAPE)) {
        // Even when we aren't in debug mode, quit on escape.
        endApplet = true;
        app->endProgram = true;
    }

	// Add other key handling here
}


void Demo::doGraphics() {

    LightingParameters lighting(G3D::toSeconds(11, 00, 00, AM));
    app->renderDevice->setProjectionAndCameraMatrix(app->debugCamera);

    // Cyan background
    app->renderDevice->setColorClearValue(Color3(.1f, .5f, 1));

    app->renderDevice->clear(app->sky.isNull(), true, true);
    if (app->sky.notNull()) {
        app->sky->render(lighting);
    }

    // Setup lighting
    app->renderDevice->enableLighting();
		app->renderDevice->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));
		app->renderDevice->setAmbientLightColor(lighting.ambient);

		Draw::axes(CoordinateFrame(Vector3(0, 4, 0)), app->renderDevice);
    app->renderDevice->disableLighting();

    app->renderDevice->setTexture(0, video);
    double u = video->texelWidth();
    double v = video->texelHeight();
    double w = 1;
    double h = (w * v) / u;
    app->renderDevice->beginPrimitive(RenderDevice::QUADS);
        app->renderDevice->setTexCoord(0, Vector2(0, v));
        app->renderDevice->sendVertex(Vector2(0, 0));

        app->renderDevice->setTexCoord(0, Vector2(u, v));
        app->renderDevice->sendVertex(Vector2(w, 0));

        app->renderDevice->setTexCoord(0, Vector2(u, 0));
        app->renderDevice->sendVertex(Vector2(w, h));

        app->renderDevice->setTexCoord(0, Vector2(0, 0));
        app->renderDevice->sendVertex(Vector2(0, h));
    app->renderDevice->endPrimitive();

    /*Draw::rect2D(Rect2D::xywh(-1, 1, 2, -2),
        app->renderDevice, Color3::white(), 
        Rect2D::xywh(0, 0, video->texelWidth(), video->texelHeight()));
    app->renderDevice->setTexture(0, NULL);*/

    if (app->sky.notNull()) {
        app->sky->renderLensFlare(lighting);
    }

}


void App::main() {
	setDebugMode(true);
	debugController.setActive(true);

    camera.init(VideoCapture::enumerateDeviceNames()[0], 128, 96);
    // Load objects here
    sky = Sky::create(renderDevice, dataDir + "sky/");
    
    Demo(this).run();
}


App::App(const GAppSettings& settings) : GApp(settings) {
}


int main(int argc, char** argv) {
    GAppSettings settings;
    settings.useNetwork = false;
    App(settings).run();
    return 0;
}
