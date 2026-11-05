/**
  @file demos/main.cpp

  This is a prototype main.cpp to use for your programs.  It is a good
  infrastructure for building an interactive demo.  See also G3D::GApp
  and G3D::GApplet for a more object-oriented approach (that automates
  most of the boilerplate).
  
  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2002-02-27
  @edited  2006-05-10
 */ 

#include <G3DAll.h>

#if G3D_VER != 60900
    #error Requires G3D 6.09
#endif

std::string             DATA_DIR;

Log*                    debugLog		= NULL;
RenderDevice*           renderDevice	= NULL;
GFontRef                font			= NULL;
UserInput*              userInput		= NULL;
ManualCameraController* controller      = NULL;
GCamera  				camera;
bool                    endProgram		= false;

void doSimulation(GameTime timeStep);
void doGraphics();
void doUserInput();


// No error checking
int main(int argc, char** argv) {

    // Initialize
    DATA_DIR     = demoFindData();
    debugLog	 = new Log;
    renderDevice = new RenderDevice;
    RenderDeviceSettings settings;
    settings.fsaaSamples = 1;
    settings.resizable = true;
    renderDevice->init(settings, debugLog);

    userInput    = new UserInput();

    font         = GFont::fromFile(renderDevice, DATA_DIR + "font/dominant.fnt");

    controller   = new ManualCameraController(renderDevice, userInput);

    controller->setMoveRate(10);
    controller->setPosition(Vector3(0.0f, 0.0f, 4.0f));
    controller->lookAt(Vector3(-2.0f, 3.0f, -5.0f));

    controller->setActive(true);

    renderDevice->resetState();
	renderDevice->setColorClearValue(Color3(0.1f, 0.5f, 1.0f));

    RealTime now = System::getTick() - 0.001f, lastTime;

    // Main loop
    do {
        lastTime = now;
        now = System::getTick();
        RealTime timeStep = now - lastTime;

        doUserInput();

        doSimulation(timeStep);

        doGraphics();
   
    } while ( !endProgram );

    // Cleanup
    delete controller;
    delete userInput;
    renderDevice->cleanup();
    delete renderDevice;
    delete debugLog;

    return 0;
}

//////////////////////////////////////////////////////////////////////////////


void doSimulation(GameTime timeStep) {
    // Simulation
    controller->doSimulation(clamp(timeStep, 0.0, 0.1));
	camera.setCoordinateFrame(controller->getCoordinateFrame());
}



void doGraphics() {

    LightingParameters lighting(G3D::toSeconds(11, 00, 00, AM));

    renderDevice->beginFrame();
        // Cyan background
	    glClearColor(0.1f, 0.5f, 1.0f, 0.0f);

        renderDevice->clear(true, true, true);
        renderDevice->pushState();

            renderDevice->setProjectionAndCameraMatrix(camera);

            renderDevice->enableLighting();
            renderDevice->setLight(0, GLight::directional(lighting.lightDirection, 
lighting.lightColor));
            renderDevice->setAmbientLightColor(lighting.ambient);

            Draw::axes(renderDevice);

        renderDevice->popState();
	    
    renderDevice->endFrame();
}


void doUserInput() {

    userInput->beginEvents();

    // Event handling
    GEvent inputEvent;
    while ( renderDevice->window()->pollEvent(inputEvent) ) {
        switch(inputEvent.type) {
        case SDL_QUIT:
	        endProgram = true;
	        break;

        case SDL_VIDEORESIZE:
            {
                renderDevice->notifyResize(inputEvent.resize.w, inputEvent.resize.h);
                Rect2D full = Rect2D::xywh(0.0f, 0.0f, renderDevice->getWidth(), 
renderDevice->getHeight());
                renderDevice->setViewport(full);
            }
            break;


	    case SDL_KEYDOWN:
            switch (inputEvent.key.keysym.sym) {
            case SDLK_ESCAPE:
                endProgram = true;
                break;

            case SDLK_TAB:
                controller->setActive(! controller->active());
                break;

            // Add other key handlers here
            default:;
            }
            break;

        // Add other event handlers here

        default:;
        }

        userInput->processEvent(inputEvent);
    }

    userInput->endEvents();
}
