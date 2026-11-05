/**
  @file Network_Demo/main.cpp

  Optional command line argument is the name of the log file (useful
  when running two clients on the same machine).

  This demo shows how to set up network discovery (server browsing)
  and a client server program.  It also contains a "listen server"
  that runs in parallel with a client within a single thread.

  In-game keys:
    ESC     - Quit
    W/S     - Forward/backward
    A/D     - Left/right
    Z/space - Down/up

  @author Morgan McGuire, matrix@graphics3d.com
  @created 2004-03-28
  @edited  2004-10-05
 */

#include "App.h"
#include "Browse.h"
#include "Client.h"
#include "Server.h"

App* app;

int main(int argc, char** argv) {
    GAppSettings settings;

    if (argc > 1) {
        settings.logFilename = argv[1];
    }

    settings.window.fsaaSamples = 4;
    settings.window.width       = 640;
    settings.window.height      = 480;

    System::sleep(5);
    App(settings).run();
    return 0;
}


App::App(const GAppSettings& settings) : GApp(settings),
    hostingServer(NULL),
    discoverySettings("Demo Discovery Protocol", 1) {

    ::app = this;

    renderDevice->setCaption("G3D Network Demo");
}

void showError(const std::string& s1, const std::string& s2, RenderDevice* rd, GFontRef font);

void App::main() {
	setDebugMode(true);
	debugController.setActive(false);
	debugShowRenderingStats = false;
    debugQuitOnEscape = false;

    // Load objects here
    sky  = Sky::create(renderDevice, dataDir + "sky/");
    font = GFont::fromFile(renderDevice, dataDir + "font/dominant.fnt");

    Browse browse(this);
    Client client(this);

    while (! endProgram) {
        bool error = false;

        // First browse for a server (or start our own).
        browse.run();

        if (endProgram) {
            return;
        }

        if (browse.host) {
            // Start a server
            hostingServer = new Server(this);

            if (hostingServer->ok()) {
                // Connect to that server
                client.selectedServer = hostingServer->advertisement;

                Array<NetAddress> myAddresses;
                networkDevice->localHostAddresses(myAddresses);
                client.selectedServer.address = NetAddress(myAddresses[0].ip(), GAME_PORT);
            } else {
                showError(
                    "Unable to create a server.",
                    "(Maybe there is already a server running on this machine.)",
                    renderDevice, font);
                error = true;
            }
        } else {
            // Overwrite the port
            client.selectedServer = browse.selectedServer;
            client.selectedServer.address = NetAddress(client.selectedServer.address.ip(), GAME_PORT);
        }

        if (! error) {
            // Now enter the world as a client (our own server runs in the background)
            client.run();
        }

        debugController.setActive(false);

        // If we were hosting, delete the server
        if (hostingServer) {
            delete hostingServer;
            hostingServer = NULL;
        }
    }
}


void showError(const std::string& s1, const std::string& s2, RenderDevice* rd, GFontRef font) {
    RealTime t0 = System::time();

    double w = rd->width();
    while (System::time() < t0 + 4) {
        rd->beginFrame();
            rd->clear();
            rd->push2D();
                font->draw2D(rd, s1, Vector2(w/2, 100), 30, Color3::cyan(), Color3::black(), GFont::XALIGN_CENTER);
                font->draw2D(rd, s2, Vector2(w/2, 200), 20, Color3::cyan(), Color3::black(), GFont::XALIGN_CENTER);
            rd->pop2D();
        rd->endFrame();
    }
}
