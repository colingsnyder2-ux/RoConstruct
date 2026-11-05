/**
  @file gfxmeter/Report.cpp

  @author Morgan McGuire, matrix@graphics3d.com
 */

#include "Report.h"
#include "App.h"

/** Converts a bug count into a quality rating*/
const char* quality(int bugCount) {
    static const char* q[] = {"A+", "A-", "B+", "B-", "C+", "C-", "D+", "D-", "F"};
    return q[iClamp(bugCount, 0, 8)];
}

Report::Report(App* _app) : GApplet(_app), app(_app) {
}


void Report::init()  {
    popup = NONE;

    // Called before Report::run() beings
    app->debugCamera.setPosition(Vector3(0, 2, 10));
    app->debugCamera.lookAt(Vector3(0, 2, 0));

    // Init the fun stuff
    knight.load("pknight");
    knight.cframe.translation = Vector3(-5, 0, 0);

    ogre.load("ogro");
    ogre.cframe.translation = Vector3(-1.5, 0, 0);

    knight.cframe.lookAt(ogre.cframe.translation + Vector3(0,0,1));
    ogre.cframe.lookAt(knight.cframe.translation + Vector3(0,0,1));
}


void Report::cleanup() {
    // Called when Report::run() exits
}


void Report::doNetwork() {
	// Poll net messages here
}


void Report::doSimulation(SimTime dt) {
	// Add physical simulation here

    GameTime deltaTime = 0.02;

    knight.doSimulation(deltaTime);
    ogre.doSimulation(deltaTime);
}


void Report::doLogic() {    
    int w = app->renderDevice->getWidth();
    int h = app->renderDevice->getHeight();

    Vector2 mouse = app->userInput->mouseXY();

    if (app->userInput->keyPressed(SDL_LEFT_MOUSE_KEY)) {
        if (popup == NONE) {
            if (performanceButton.contains(mouse)) {
                popup = PERFORMANCE;
            }
        } else {
            popup = NONE;
        }
    }

    if (app->userInput->keyPressed(SDLK_ESCAPE)) {
        if (popup == NONE) {
            // Even when we aren't in debug mode, quit on escape.
            endApplet = true;
            app->endProgram = true;
        } else {
            popup = NONE;
        }
    }

}


void Report::doFunStuff() {
    app->renderDevice->pushState();
        GCamera camera;
        camera.setCoordinateFrame(Vector3(0,1,10));
        camera.lookAt(Vector3(0,2.8f,0));

        app->renderDevice->setProjectionAndCameraMatrix(camera);

        knight.renderShadow(app->renderDevice);
        ogre.renderShadow(app->renderDevice);

        app->renderDevice->enableLighting();
        app->renderDevice->setLight(0, GLight::directional(Vector3(-1,1,2).direction(), Color3(.8f,.8f,.7f)));
        app->renderDevice->setLight(1, GLight::directional(Vector3(.5f,-1,1).direction(), Color3::red() * 0.2f));
        app->renderDevice->setAmbientLightColor(Color3(.5f,.5f,.6f));

        knight.render(app->renderDevice);
        ogre.render(app->renderDevice);

    app->renderDevice->popState();
}


static void drawBar(RenderDevice* rd, int value, const Vector2& p) {
    float s = rd->getWidth() * 0.35f / 100.0f;
    Draw::rect2D(Rect2D::xywh(p.x, p.y, 100 * s, 20), rd, Color3::white() * 0.9f);
    Draw::rect2D(Rect2D::xywh(p.x, p.y, value * s, 20), rd, Color3::yellow());
    Draw::rect2DBorder(Rect2D::xywh(p.x, p.y, 100 * s, 20), rd, Color3::black());
}


Rect2D Report::drawPopup(const char* title) {
    int w = app->renderDevice->getWidth();
    int h = app->renderDevice->getHeight();

    // Drop shadow
    app->renderDevice->pushState();
        app->renderDevice->setBlendFunc(RenderDevice::BLEND_SRC_ALPHA, RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);
        Rect2D rect = Rect2D::xywh(w/2 - 20, h/2 - 20, w/2, h/2);
        Draw::rect2D(rect + Vector2(5, 5), app->renderDevice, Color4(0, 0, 0, 0.15f));
    app->renderDevice->popState();

    // White box
    Draw::rect2D(rect, app->renderDevice, Color3::white());
    Draw::rect2DBorder(rect, app->renderDevice, Color3::black());

    // The close box
    Draw::rect2DBorder(Rect2D::xywh(rect.x1() - 16, rect.y0(), 16, 16), app->renderDevice, Color3::black());
    app->renderDevice->setColor(Color3::black());
    app->renderDevice->beginPrimitive(RenderDevice::LINES);
        app->renderDevice->sendVertex(Vector2(rect.x1() - 14, rect.y0() + 2));
        app->renderDevice->sendVertex(Vector2(rect.x1() - 2, rect.y0() + 14));   
        app->renderDevice->sendVertex(Vector2(rect.x1() - 2, rect.y0() + 2));
        app->renderDevice->sendVertex(Vector2(rect.x1() - 14, rect.y0() + 14));   
    app->renderDevice->endPrimitive();

    float s = w * 0.013;
    app->titleFont->draw2D(app->renderDevice, title, Vector2(rect.x0() + 4, rect.y0()), s * 1.5, Color3::black(), Color4::clear(), GFont::XALIGN_LEFT, GFont::YALIGN_TOP);

    return rect;
}


void Report::doGraphics() {
    app->renderDevice->setColorClearValue(Color3::white());
    app->renderDevice->clear();

    doFunStuff();

    app->renderDevice->push2D();

        int w = app->renderDevice->getWidth();
        int h = app->renderDevice->getHeight();

        ///////////////////////////////////////
        // Left panel
#       define LABEL(str) p.y += app->titleFont->draw2D(app->renderDevice, str, p - Vector2((float)w * 0.0075f, 0), s * 2, Color3::white() * 0.4f).y
#       define PRINT(str) p.y += app->reportFont->draw2D(app->renderDevice, str, p, s, Color3::black()).y

        int x0 = w * 0.015;
        // Cursor position
        Vector2 p(x0, h * 0.02);

        // Font size
        float s = w * 0.013;

        LABEL("Shaders");
        PRINT(std::string("Combiners: ") + app->combineShader);
        PRINT(std::string("Assembly:   ") + app->asmShader);
        PRINT(std::string("GLSL:         ") + app->glslShader);

        p.y += s * 2;
        LABEL("Extensions");
        PRINT(std::string("FSAA:                           ") + ((GLCaps::supports("WGL_ARB_multisample") || GLCaps::supports("GL_ARB_multisample")) ? "Yes" : "No"));
        PRINT(std::string("Two-sided Stencil:        ") + ((GLCaps::supports_two_sided_stencil() ? "Yes" : "No")));
        PRINT(std::string("Stencil Wrap:               ") + (GLCaps::supports("GL_EXT_stencil_wrap") ? "Yes" : "No"));
        PRINT(std::string("Texture Compression: ") + (GLCaps::supports("GL_EXT_texture_compression_s3tc") ? "Yes" : "No"));
        PRINT(std::string("Shadow Maps:             ") + (GLCaps::supports("GL_ARB_shadow") ? "Yes" : "No"));
        PRINT(std::string("Frame Buffer Object:   ") + (GLCaps::supports("GL_EXT_framebuffer_object") ? "Yes" : "No"));
        PRINT(std::string("Vertex Arrays:              ") + (GLCaps::supports_GL_ARB_vertex_buffer_object() ? "Yes" : "No"));
        
            
        ///////////////////////////////////////
        // Right Panel
        x0 = w * 0.6f;
        // Cursor position
        p = Vector2(x0, h * 0.02f);

        // Graphics Card
        LABEL("Graphics Card");
        app->renderDevice->setTexture(0, app->cardLogo);
        Draw::rect2D(Rect2D::xywh(p.x - s * 6, p.y, s * 5, s * 5), app->renderDevice);
        app->renderDevice->setTexture(0, NULL);

        PRINT(GLCaps::vendor().c_str());
        PRINT(GLCaps::renderer().c_str());
        PRINT(format("Driver Version %s", GLCaps::driverVersion().c_str()));

#       ifdef G3D_WIN32        
            PRINT(format("%d MB Video RAM", DXCaps::videoMemorySize() / (1024 * 1024)));
            {
                uint32 ver = DXCaps::version();
                PRINT(format("DirectX %d.%d", ver/100, ver%100));
            }
#       endif

        p.y += s * 2;

        // Processor
        LABEL("Processor");
        app->renderDevice->setTexture(0, app->chipLogo);
        Draw::rect2D(Rect2D::xywh(p.x - s * 6, p.y, s * 5, s * 5), app->renderDevice);
        app->renderDevice->setTexture(0, NULL);

        PRINT(System::cpuVendor().c_str());
        PRINT(System::cpuArchitecture().c_str());

        Array<std::string> features;
        if (System::has3DNow()) {
            features.append("3DNow");
        }
        if (System::hasMMX()) {
            features.append("MMX");
        }
        if (System::hasSSE()) {
            features.append("SSE");
        }
        if (System::hasSSE2()) {
            features.append("SSE2");
        }
        if (app->chipSpeed != "") {
            PRINT(app->chipSpeed + " " + stringJoin(features, '/'));
        } else {
            PRINT(stringJoin(features, '/'));
        }

        p.y += s * 2;

        // Operating System
        LABEL("OS");
        app->renderDevice->setTexture(0, app->osLogo);
        Draw::rect2D(Rect2D::xywh(p.x - s * 6, p.y - s * 2, s * 5, s * 5), app->renderDevice);
        app->renderDevice->setTexture(0, NULL);


        if (beginsWith(System::operatingSystem(), "Windows 5.0")) {
            PRINT("Windows 2000");
        } else if (beginsWith(System::operatingSystem(), "Windows 5.1")) {
            PRINT("Windows XP");
        }
        PRINT(System::operatingSystem().c_str());

        p.y += s * 3;

        x0 = w - s * 10;
        app->titleFont->draw2D(app->renderDevice, "Features", p - Vector2(w * 0.0075f, 0), s * 2, Color3::white() * 0.4f);
        p.y += app->reportFont->draw2D(app->renderDevice, format("f%d", app->featureRating), Vector2(x0, p.y), s*2, Color3::red() * 0.5).y;
        drawBar(app->renderDevice, app->featureRating, p);

        // Designed to put NV40 at 50
        app->performanceRating = app->renderDevice->getFrameRate() / 5.0;

        p.y += s * 4;
        performanceButton = Rect2D::xywh(p,
            app->titleFont->draw2D(app->renderDevice, "Speed", p - Vector2(w * 0.0075f, 0), s * 2, Color3::white() * 0.4f));

        p.y += app->reportFont->draw2D(app->renderDevice, format("%5.1f", iRound(app->performanceRating * 10) / 10.0f), Vector2(x0 - s*2, p.y), s*2, Color3::red() * 0.5).y;
        drawBar(app->renderDevice, app->performanceRating, p);

        p.y += s * 4;
        app->titleFont->draw2D(app->renderDevice, "Quality", p - Vector2(w * 0.0075f, 0), s * 2, Color3::white() * 0.4f);
        p.y += app->reportFont->draw2D(app->renderDevice, quality(app->bugCount), Vector2(x0, p.y), s*2, Color3::red() * 0.5f).y;
        drawBar(app->renderDevice, iClamp(100 - app->bugCount * 10, 0, 100), p);

#       undef PRINT


        p.y = h - 50;
#       define PRINT(str) p.y += app->reportFont->draw2D(app->renderDevice, str, p, 8, Color3::black()).y;

        PRINT("These ratings are based on the performance of G3D apps.");
        PRINT("They may not be representative of overall 3D performance.");
        PRINT("Speed is based on both processor and graphics card. Upgrading");
        PRINT("your graphics driver may improve Quality and Features.");
#       undef  PRINT
#       undef LABEL

        switch (popup) {
        case NONE:
            break;

        case PERFORMANCE:
            {
                //  Draw the popup box
                Rect2D box = drawPopup("Performance Details");
                p.x = box.x0() + 10;
                p.y = box.y0() + 30;

                std::string str;

                float factor = 3 * app->vertexPerformance.numTris / 1e6;

#               define PRINT(cap, val)   \
                    app->reportFont->draw2D(app->renderDevice, cap, p, s, Color3::black());\
                    app->reportFont->draw2D(app->renderDevice, (app->vertexPerformance.val[0] > 0) ? \
                        format("%5.1f", app->vertexPerformance.val[0]) : \
                        std::string("X"), p + Vector2(190, 0), s, Color3::red() * 0.5, Color4::clear(), GFont::XALIGN_RIGHT);\
                    app->reportFont->draw2D(app->renderDevice, (app->vertexPerformance.val[0] > 0) ? \
                        format("%5.1f", factor * app->vertexPerformance.val[0]) : \
                        std::string("X"), p + Vector2(240, 0), s, Color3::red() * 0.5, Color4::clear(), GFont::XALIGN_RIGHT);\
                    app->reportFont->draw2D(app->renderDevice, (app->vertexPerformance.val[1] > 0) ? \
                        format("%5.1f", app->vertexPerformance.val[1]) : \
                        std::string("X"), p + Vector2(330, 0), s, Color3::red() * 0.5, Color4::clear(), GFont::XALIGN_RIGHT);\
                    p.y += app->reportFont->draw2D(app->renderDevice, (app->vertexPerformance.val[1] > 0) ? \
                        format("%5.1f", factor * app->vertexPerformance.val[1]) : \
                        std::string("X"), p + Vector2(380, 0), s, Color3::red() * 0.5, Color4::clear(), GFont::XALIGN_RIGHT).y;

                app->reportFont->draw2D(app->renderDevice, "Incoherent", p + Vector2(220, 0), s, Color3::black(), Color4::clear(), GFont::XALIGN_RIGHT);
                p.y += app->reportFont->draw2D(app->renderDevice, "Coherent", p + Vector2(350, 0), s, Color3::black(), Color4::clear(), GFont::XALIGN_RIGHT).y;

                app->reportFont->draw2D(app->renderDevice, "FPS*   MVerts/s", p + Vector2(240, 0), s, Color3::black(), Color4::clear(), GFont::XALIGN_RIGHT);
                p.y += app->reportFont->draw2D(app->renderDevice, "FPS*   MVerts/s", p + Vector2(370, 0), s, Color3::black(), Color4::clear(), GFont::XALIGN_RIGHT).y;
                
                PRINT("glBegin/glEnd", beginEndFPS);
                PRINT("glDrawElements", drawElementsRAMFPS); 
                PRINT("  + VBO", drawElementsVBOFPS);
                PRINT("  + uint16", drawElementsVBO16FPS);
                PRINT("  + interleaving", drawElementsVBOIFPS);
                PRINT("  (without shading)", drawElementsVBOPeakFPS);

                app->reportFont->draw2D(app->renderDevice, "glDrawArrays", p, s, Color3::black());
                app->reportFont->draw2D(app->renderDevice, (app->vertexPerformance.drawArraysVBOPeakFPS > 0) ? \
                    format("%5.1f", app->vertexPerformance.drawArraysVBOPeakFPS) : \
                    std::string("X"), p + Vector2(330, 0), s, Color3::red() * 0.5, Color4::clear(), GFont::XALIGN_RIGHT);\
                p.y += app->reportFont->draw2D(app->renderDevice, (app->vertexPerformance.drawArraysVBOPeakFPS > 0) ? \
                    format("%5.1f", factor * app->vertexPerformance.drawArraysVBOPeakFPS) : \
                    std::string("X"), p + Vector2(380, 0), s, Color3::red() * 0.5, Color4::clear(), GFont::XALIGN_RIGHT).y;

#               undef PRINT

                p.y += s;
                p.y += app->reportFont->draw2D(app->renderDevice, format("* FPS at %d k polys/frame.", 
                    iRound(app->vertexPerformance.numTris / 1000.0)), p + Vector2(20, 0), s, Color3::black()).y;
            }
        }

    app->renderDevice->pop2D();
}
