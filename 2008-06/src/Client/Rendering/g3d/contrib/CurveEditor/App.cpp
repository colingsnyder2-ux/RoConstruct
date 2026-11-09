#include "App.h"
#include "Editor.h"


void App::main() {
	setDebugMode(false);
	debugController.setActive(false);
    Editor(this).run();
}


App::App(const GAppSettings& settings) : GApp(settings) {
    window()->setCaption("Curve Editor");
    font = GFont::fromFile(renderDevice, "D:/games/data/font/eurostyle-small.fnt");
}


int main(int argc, char** argv) {
    GAppSettings settings;
    settings.window.fsaaSamples = 1;
    App(settings).run();
    return 0;
}
