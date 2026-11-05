/**
  @file Network_Demo/Browse.cpp

  @author Morgan McGuire, matrix@graphics3d.com
  @created 2004-03-28
  @edited  2005-02-24
 */

#include "Browse.h"
#include "App.h"

Browse::Browse(App* app) : GApplet(app), app(app) {
}


void Browse::init() {
    discoveryClient.init(app->networkDevice, &app->discoverySettings);
    host = false;
}


void Browse::doLogic() {
    if (app->userInput->keyPressed(SDL_LEFT_MOUSE_KEY)) {
        const int HOST = button.size() - 2;
        const int EXIT = button.size() - 1;
        const Vector2 mouse = app->userInput->mouseXY();
        // See what button the user pressed
        for (int b = 0; b < button.size(); ++b) {
            if (button[b].contains(mouse)) {
                if (b == HOST) {
                    host            = true;
                    endApplet       = true;
                    break;
                } else if (b == EXIT) {
                    app->endProgram = true;
                    endApplet       = true;
                    break;
                } else if (discoveryClient.serverList.size() > b) {
                    selectedServer  = discoveryClient.serverList[b];
                    endApplet       = true;
                    break;
                }
            }
        }
    }

    if (app->userInput->keyPressed(SDLK_ESCAPE)) {
        endApplet = true;
        app->endProgram = true;
    }
}


void Browse::doNetwork() {
    // Allow the discovery client talk to the
    // network and search for servers.
    discoveryClient.doNetwork();
}


void Browse::doSimulation(SimTime dt) {
}


void Browse::doGraphics() {
    app->renderDevice->setColorClearValue(Color3::WHITE);
    app->renderDevice->clear(true, true, true);

    app->renderDevice->push2D();
        double width            = app->renderDevice->width();
        double height           = app->renderDevice->height();
        double titleFontSize    = 30 * width / 800;
        double optionFontSize   = 25 * width / 800;
        Color4 titleFontColor   = Color3::BLACK;
        Color4 titleFontBorder  = Color4::CLEAR;
        Color4 optionFontColor  = Color3::YELLOW;
        Color4 optionFontBorder = Color3::BLACK;

        double y = 10;
        app->font->draw2D(app->renderDevice, "Choose A Network Demo Server", Vector2(width / 2, y),
            titleFontSize, titleFontColor, titleFontBorder, GFont::XALIGN_CENTER);
        y += titleFontSize * 2;

        button.clear();

        // Display the servers found
        for (int s = 0; s < discoveryClient.serverList.size(); ++s) {
            
            Vector2 bounds = app->font->draw2D(app->renderDevice, discoveryClient.serverList[s].name,
                Vector2(width / 2, y),
                optionFontSize, optionFontColor, 
                optionFontBorder, GFont::XALIGN_CENTER);

            button.append(Rect2D::xywh(width / 2 - bounds.x / 2, y, bounds.x, bounds.y));

            y += optionFontSize * 2;
        }

        if (discoveryClient.serverList.size() == 0) {
            app->font->draw2D(app->renderDevice, "(No servers found-- host one yourself!)",
                Vector2(width / 2, y),
                optionFontSize, titleFontColor, 
                titleFontBorder, GFont::XALIGN_CENTER);

            y += optionFontSize * 2;
        }

        y = height - optionFontSize * 6;

        Vector2 bounds = app->font->draw2D(app->renderDevice, "Create Server", Vector2(width / 2, y),
            optionFontSize, optionFontColor, optionFontBorder, GFont::XALIGN_CENTER);
        button.append(Rect2D::xywh(width / 2 - bounds.x / 2, y, bounds.x, bounds.y));
        y += optionFontSize * 2;

        bounds = app->font->draw2D(app->renderDevice, "Exit", Vector2(width / 2, y),
            optionFontSize, optionFontColor, optionFontBorder, GFont::XALIGN_CENTER);
        button.append(Rect2D::xywh(width / 2 - bounds.x / 2, y, bounds.x, bounds.y));
        y += optionFontSize * 2;

    app->renderDevice->pop2D();
}


void Browse::cleanup() {
    discoveryClient.cleanup();
}
