/**
  @file map/main.cpp
  
  @maintainer Morgan McGuire, matrix@graphics3d.com

  This project loads and renders Quake III maps.  These maps
  contain information in a BSP tree that allows efficient
  rendering and collision detection.

  You do not need Quake III to use this code.  Many maps
  can be downloaded from the internet and are included with
  mods like Urban Terror.  You can also make your own Quake III
  maps.

  Note that Quake II, Half-Life, and Kingpin have a very similar
  map format.  This code can be modified to load those maps as 
  well.

  This code is provided as-is; it has some known bugs in the 
  visibility and collision detection computations.  I'd appreciate
  patches that fix these bugs, and may release improved code
  at some point in the future.

  I highly recommend walking through the code before using it.
  There are many features not exposed through the public interface. 

  @created 2003-05-22
  @edited  2003-12-30
 */ 

#include <G3DAll.h>
#include "BSPMAP.h"

#if G3D_VER < 60900
    #error Requires G3D 6.09
#endif


class DepthBlur {
private:

    ShaderRef           shader;

    TextureRef          depth;
    TextureRef          color;

    void allocateTextures(const Rect2D& screenRect) {
        if (depth.isNull() || 
            (depth->vector2Bounds() != screenRect.wh())) {
        /*
            Texture::Parameters depthParameters;
            depthParameters.autoMipMap = false;
            depthParameters.maxAnisotropy = 1;
            depthParameters.wrapMode = Texture::CLAMP;
            depthParameters.interpolateMode = Texture::NO_INTERPOLATION;
*/
            depth = Texture::createEmpty("Depth Buffer", screenRect.width(), screenRect.height(),
                TextureFormat::depth(), Texture::DIM_2D_NPOT, Texture::Parameters::video());

            color = Texture::createEmpty("Color Buffer", screenRect.width(), screenRect.height(),
                TextureFormat::RGB8, Texture::DIM_2D_NPOT, Texture::Parameters::video());

            shader->args.set("depth", depth);
            shader->args.set("color", color);
        }
    }

public:

    DepthBlur() {
        shader = Shader::fromFiles("", "depthblur.frg");
    }

    void apply(RenderDevice* rd) {
        rd->push2D();
            Rect2D screenRect = rd->getViewport();
            allocateTextures(screenRect);
            
            // Read back the depth buffer
            depth->copyFromScreen(screenRect, true);
            color->copyFromScreen(screenRect, true);

            rd->setShader(shader);
            Draw::rect2D(screenRect, rd);
        rd->pop2D();
    }

};

/**
 This simple demo applet uses the debug mode as the regular
 rendering mode so you can fly around the scene.
 */
class Demo : public GApplet {
public:

    // Add state that should be visible to this applet.
    // If you have multiple applets that need to share
    // state, put it in the App.

    class App*          app;

    DepthBlur           depthBlur;

    Demo(App* app);

    virtual ~Demo() {}

    virtual void init();

    virtual void doLogic();

	virtual void doNetwork();

    virtual void doSimulation(SimTime dt);

    virtual void doGraphics();

    virtual void cleanup();

};



class App : public GApp {
protected:
    void main();
public:
    /**
     Set this directory to the root path of your quake install.
     i.e. The directory with "maps, scripts, sound, textures" as
     subdirectories. */
    static const std::string QUAKE_DIR;

    bool                clipMovement;

    SkyRef              sky;

    Demo*               applet;


    BSPMAP::Map*        map;

    /**
     When true, the visible set of polygons is saved
     to a file.
     */
    bool                dumpPolygons;


    App(const GAppSettings& settings);

    ~App();
};


Demo::Demo(App* _app) : GApplet(_app), app(_app) {
}


void Demo::init()  {
}


void Demo::cleanup() {
    // Called when Demo::run() exits
}


void Demo::doNetwork() {
	// Poll net messages here
}



void Demo::doGraphics() {

    LightingParameters lighting(G3D::toSeconds(6,00,00,PM));
    app->renderDevice->setProjectionAndCameraMatrix(app->debugCamera);

    app->renderDevice->clear(app->sky.isNull(), true, true);
    if (app->sky.notNull()) {
        app->sky->render(lighting);
    }

    // Setup lighting
    app->renderDevice->enableLighting();
		app->renderDevice->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));
		app->renderDevice->setAmbientLightColor(lighting.ambient);

        app->map->render(app->renderDevice, app->debugCamera);

    app->renderDevice->disableLighting();

    if (app->sky.notNull()) {
        app->sky->renderLensFlare(lighting);
    }

    depthBlur.apply(app->renderDevice);
}


void App::main() {

    window()->setCaption("Q3 Renderer");

	setDebugMode(true);
	debugController.setActive(true);

    dumpPolygons = false;
    clipMovement = true;

    sky = Sky::create(renderDevice, dataDir + "sky/");
    debugCamera.setNearPlaneZ(-0.5f);
    debugCamera.setFarPlaneZ(-100);//(float)-inf());
    debugController.init(renderDevice, userInput);
    debugController.setMoveRate(500 * BSPMAP::LOAD_SCALE);
    debugController.setActive(true);
	renderDevice->setColorClearValue(Color3(0.1f, 0.5f, 1.0f));
    // Load the map
    map = new BSPMAP::Map();
    bool ret = map->load("D:/games/dojo/scratch/data-files/q3/", "ut_ricochet.bsp");
//    bool ret = map->load("D:/media/models/q3/maps/urbanterror/", "ut_ricochet.bsp");
      
    debugAssert(ret); (void)ret;

    debugController.setPosition(map->getStartingPosition());
    debugController.lookAt(map->getStartingPosition() - Vector3::unitZ());
    debugCamera.setCoordinateFrame(debugController.getCoordinateFrame());
    
    applet->run();
}


App::App(const GAppSettings& settings) : GApp(settings) {
    applet = new Demo(this);
}


App::~App() {
    delete applet;
}

int main(int argc, char** argv) {
    GAppSettings settings;
    App(settings).run();
    return 0;
}

 

void Demo::doSimulation(GameTime timeStep) {
    // Simulation

    Vector3 originalTrans = app->debugController.getCoordinateFrame().translation;

    app->debugController.doSimulation(clamp(timeStep, 0.0, 0.1));

    CoordinateFrame newCframe;
    app->debugController.getCoordinateFrame(newCframe);

    if (app->clipMovement) {
        Vector3 extent(14, 14, 14);
        extent *= BSPMAP::LOAD_SCALE;
        Vector3 pos(originalTrans.x, originalTrans.y, originalTrans.z);
        Vector3 vel(newCframe.translation.x - originalTrans.x, newCframe.translation.y - originalTrans.y, newCframe.translation.z - originalTrans.z);

        app->map->slideCollision(pos, vel, extent);

        newCframe.translation.x = pos.x;
        newCframe.translation.y = pos.y;
        newCframe.translation.z = pos.z;

        app->debugController.setPosition(newCframe.translation);
    }

    app->debugCamera.setCoordinateFrame(newCframe);
}


void Demo::doLogic() {
    if (app->userInput->keyPressed(SDLK_ESCAPE)) {
        // Even when we aren't in debug mode, quit on escape.
        endApplet = true;
        app->endProgram = true;
    }

    if (app->userInput->keyPressed(' ')) {
        app->clipMovement = ! app->clipMovement;
    }

    if (app->userInput->keyPressed('p')) {
        app->dumpPolygons = true;
    }
}
