/**
  @file Console/main.cpp

  Example of how to use GConsole.  You only need GConsole.h and GConsole.cpp to add console support to your own programs.

  Look at GConsoleApplet::consoleCallback() to see how to implement your own command interpreter.

  @author Morgan McGuire, matrix@graphics3d.com
 */

#include <G3DAll.h>
#include "GConsole.h"

#if G3D_VER < 60800
    #error Requires G3D 6.08
#endif


/**
 This simple demo applet uses the debug mode as the regular
 rendering mode so you can fly around the scene.
 */
class Demo : public GApplet {
private:

    void consoleCallback(const std::string& cmd);
    
    static void _consoleCallback(const std::string& cmd, void* me) {
        static_cast<Demo*>(me)->consoleCallback(cmd);
    }

    void printHelp();

    GConsoleRef         m_console;

public:

    // Add state that should be visible to this applet.
    // If you have multiple applets that need to share
    // state, put it in the App.

    class App*          app;

    Demo(App* app);

    virtual ~Demo() {}

    virtual void onInit();

    virtual void onLogic();

	virtual void onNetwork();

    virtual void onSimulation(RealTime rdt, SimTime sdt, SimTime idt);

    virtual void onGraphics(RenderDevice* rd);

    virtual void onUserInput(UserInput* ui);

    virtual void onCleanup();
};



class App : public GApp {
protected:
    void main();
public:
    SkyRef              sky;

    Demo*               applet;

    App(const GAppSettings& settings);

    ~App();
};


Demo::Demo(App* _app) : GApplet(_app), app(_app) {
    GConsole::Settings s;
    m_console = GConsole::create(app->debugFont, s, _consoleCallback, this);
    addModule(m_console, GApp::HIGH_PRIORITY);
    printHelp();
}


void Demo::consoleCallback(const std::string& cmd) {
    // Extremely simple interpreter.  You could easily connect to a scripting language
    // like lua or Python, or write your own language here.  See G3D::TextInput
    // for an easy way of parsing this string into useful tokens.

    if (cmd == "exit") {
        endApplet = true;
        app->endProgram = true;
        return;
    }

    if (cmd == "help") {
        printHelp();
    }
}

void Demo::printHelp() {
    m_console->printf(" ----------------------------------------------------\n");
    m_console->printf(" PAGEUP/PAGEDOWN    Scroll console buffer\n");
    m_console->printf(" LEFT/RIGHT         Move cursor\n");
    m_console->printf(" ESCAPE             Close console\n");
    m_console->printf(" ~                  Open console\n");
    m_console->printf(" ENTER              Execute command\n");
    m_console->printf(" TAB                Autocomplete variable or filename\n");
    m_console->printf(" exit               Quit program\n");
    m_console->printf(" help               Print this information\n");
    m_console->printf(" ----------------------------------------------------\n");
}


void Demo::onInit()  {
    // Called before Demo::run() beings
    app->debugCamera.setPosition(Vector3(0, 2, 10));
    app->debugCamera.lookAt(Vector3(0, 2, 0));
}


void Demo::onCleanup() {
    // Called when Demo::run() exits
}


void Demo::onLogic() {
    // Add non-simulation game logic and AI code here
}


void Demo::onNetwork() {
	// Poll net messages here
}


void Demo::onSimulation(RealTime rdt, SimTime sdt, SimTime idt) {
	// Add physical simulation here.  You can make your time advancement
    // based on any of the three arguments.
}


void Demo::onUserInput(UserInput* ui) {
    if (ui->keyPressed(SDLK_ESCAPE)) {
        // Even when we aren't in debug mode, quit on escape.
        endApplet = true;
        app->endProgram = true;
    }

}


void Demo::onGraphics(RenderDevice* rd) {

    LightingParameters lighting(G3D::toSeconds(11, 00, 00, AM));
    app->renderDevice->setProjectionAndCameraMatrix(app->debugCamera);

    // Cyan background
    app->renderDevice->setColorClearValue(Color3(.1, .5, 1));

    app->renderDevice->clear(app->sky.isNull(), true, true);
    if (app->sky.notNull()) {
        app->sky->render(app->renderDevice, lighting);
    }

    // Setup lighting
    app->renderDevice->enableLighting();
		app->renderDevice->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));
		app->renderDevice->setAmbientLightColor(lighting.ambient);

		Draw::axes(CoordinateFrame(Vector3(0, 4, 0)), app->renderDevice);

    app->renderDevice->disableLighting();

    if (app->sky.notNull()) {
        app->sky->renderLensFlare(app->renderDevice, lighting);
    }

    // Process the modules
    GApplet::onGraphics(rd);
}


void App::main() {
	setDebugMode(true);

    // Load objects here
    sky = Sky::create(NULL, dataDir + "sky/");
    
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
    settings.useNetwork = false;
    App(settings).run();
    return 0;
}
