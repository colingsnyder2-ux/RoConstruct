/**
  @file IFSBuilder/main.cpp

  This is not a demo.  It is a piece of code I wrote to create
  IFS files which may be useful to others trying to use the
  format.

  A utility for converting some common 3D file formats into IFS format.
  This only handles a subset of all possible 3DS, OBJ, and MD2 files-- 
  models in these formats certainly exist that cannot be converted
  by this simple utility.  You can use IFSBuilder to create
  IFS files from triangle soups and write them out.  This also doubles
  as a model viewer, but it is not as nice as the IFSDemo one which
  has smoothed surface normals and lighting.

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2002-02-27
  @edited  2004-09-09
 */ 

#include <G3DAll.h>
#include "IFSModel.h"

std::string             DATA_DIR        = "data/";

Log*                    debugLog        = NULL;
RenderDevice*           renderDevice    = NULL;
CFontRef                font            = NULL;
UserInput*              userInput       = NULL;
GCamera                 camera;
ManualCameraController* controller      = NULL;
bool                    endProgram      = false;

XIFSModel*              model           = NULL;

double                  closeDistance  = 0;  
bool                    pauseBetweenModels = true;

void doSimulation(GameTime timeStep);
void doGraphics();
void doUserInput();

/**
 Returns the base name (between the last slash and the extension).
 */
std::string getFilename(const std::string& filename);
IFSModel* makeDinosaur();


int main(int argc, char** argv) {

    // Search for the data
    DATA_DIR = demoFindData();

    // Initialize
    debugLog     = new Log();
    renderDevice = new RenderDevice();
    RenderDeviceSettings settings;
    settings.width = 800;
    settings.height = 600;
    settings.fsaaSamples = 4;
    renderDevice->init(settings, debugLog);

    font         = GFont::fromFile(renderDevice, DATA_DIR + "font/dominant.fnt");

    userInput    = new UserInput();

    controller   = new ManualCameraController(renderDevice, userInput);

    controller->setMoveRate(.1);

    controller->setPosition(Vector3(2, 2, 2));
    controller->lookAt(Vector3(0,-.25,0));

    renderDevice->resetState();
    renderDevice->setColorClearValue(Color3(.5, .7, .8));

    camera.setFarPlaneZ(-100);
    camera.setNearPlaneZ(-.05);
    RealTime now = System::getTick() - 0.001, lastTime;

    std::string in("");
    std::string outDir("d:/tmp/");

    Array<std::string> filename;
    getFiles(in, filename, true);

    camera.setCoordinateFrame(controller->getCoordinateFrame());

    debugAssertM(filename.size() > 0, "No files found");

    //renderDevice->setCullFace(RenderDevice::CULL_NONE);

    for (int i = 0; i < filename.size(); ++i) {
        std::string base = getFilename(filename[i]);
        
        /*
        // Code to prevent recreation of models
        if (fileExists(outDir + base + ".ifs")) {
            // Skip this model
            continue;
        }
        */

	    controller->setActive(false);
        model = new XIFSModel(filename[i], false);
        model->name = filename[i];
	    controller->setActive(true);

        //if (! pauseBetweenModels) {
        //    model->save("d:/games/data/ifs/cylinder.ifs");//outDir + base + ".ifs");
        //    exit(0);
        //}

        // Main loop (display 3D object)
        do {
            lastTime = now;
            now = System::getTick();
            RealTime timeStep = now - lastTime;

            if (pauseBetweenModels) {
                doUserInput();
                doSimulation(timeStep);
            }

            doGraphics();
   
        } while (! endProgram && pauseBetweenModels);
        
    }


    // Cleanup
    delete controller;
    delete userInput;
    renderDevice->cleanup();
    delete renderDevice;
    delete debugLog;
    delete model;

    return 0;
}

//////////////////////////////////////////////////////////////////////////////


void doSimulation(GameTime timeStep) {
    // Simulation
    controller->doSimulation(max(0.1, min(0, timeStep)));
    camera.setCoordinateFrame(controller->getCoordinateFrame());
}


void doGraphics() {
    renderDevice->beginFrame();
    renderDevice->setColorClearValue(Color3::WHITE);
        renderDevice->clear(true, true, true);
        renderDevice->pushState();
                
            renderDevice->setProjectionAndCameraMatrix(camera);

            if (model != NULL) {

                renderDevice->enableLighting();
                renderDevice->setLight(0, GLight::directional(Vector3(-1,1,1), Color3::WHITE * .7));
                renderDevice->setLight(1, GLight::directional(-Vector3(-1,1,1), -Color3::YELLOW * 0.25, false));
                renderDevice->setAmbientLightColor(Color3::WHITE * 0.5);

                model->render();

                
                renderDevice->push2D();
                    double y = 10;
                    font->draw2D(model->name, Vector2(10, y), 20, Color3::WHITE, Color3::BLACK); y += 30;
                    font->draw2D(format("%d verts", model->numVertices()), Vector2(15, y), 15, Color3::YELLOW, Color3::BLACK); y += 20;
                    font->draw2D(format("%d faces", model->numFaces()), Vector2(15, y), 15, Color3::WHITE, Color3::BLACK); y += 20;
                    if (model->numBrokenEdges() > 0) {
                        font->draw2D(format("%d broken edges", model->numBrokenEdges()), Vector2(15, y), 15, Color3::RED, Color3::BLACK); y += 20;
                    }

                    y = renderDevice->getHeight();
                    font->draw2D(format("Vertices within radius %g collapsed", closeDistance), Vector2(10, y - 15), 10, Color3::BLACK);
                renderDevice->pop2D();
                
            }
            
        renderDevice->popState();
        
    renderDevice->endFrame();
}


void doUserInput() {

    userInput->beginEvents();

    // Event handling
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch(event.type) {
        case SDL_QUIT:
        endProgram = true;
        break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                endProgram = true;
                break;

            // Add other key handlers here
            default:;
            }
            break;

        default:;
            // Add other event handlers here
        }

        userInput->processEvent(event);
    }

    userInput->endEvents();
}

