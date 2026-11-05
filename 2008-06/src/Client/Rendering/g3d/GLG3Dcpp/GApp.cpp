/**
 @file GApp.cpp
  
 @maintainer Morgan McGuire, matrix@graphics3d.com
 
 @created 2003-11-03
 @edited  2006-04-22
 */

#include "G3D/platform.h"

#include "GLG3D/GApp.h"
#include "G3D/GCamera.h"
#include "G3D/fileutils.h"
#include "G3D/Log.h"
#include "G3D/NetworkDevice.h"
#include "GLG3D/ManualCameraController.h"
#include "GLG3D/UserInput.h"
#include "GLG3D/GWindow.h"
#include "GLG3D/Shader.h"
#include "GLG3D/Draw.h"

namespace G3D {

/** Attempt to write license file */
static void writeLicense() {
    FILE* f = fopen("g3d-license.txt", "wt");
    if (f != NULL) {
        fprintf(f, "%s", license().c_str());
        fclose(f);
    }
}


GApp::GApp(const Settings& settings, GWindow* window) {
    debugLog          = NULL;
    debugFont         = NULL;
    endProgram        = false;
    _debugControllerWasActive = false;
    m_moduleManager = GModuleManager::create();

    if (settings.dataDir == "<AUTO>") {
        dataDir = demoFindData(false);
    } else {
        dataDir = settings.dataDir;
    }


    if (settings.writeLicenseFile && ! fileExists("g3d-license.txt")) {
        writeLicense();
    }

    debugLog	 = new Log(settings.logFilename);
    renderDevice = new RenderDevice();

    if (window != NULL) {
        _hasUserCreatedWindow = true;
        renderDevice->init(window, debugLog);
    } else {
        _hasUserCreatedWindow = false;    
        renderDevice->init(settings.window, debugLog);
    }

    debugAssertGLOk();

    _window = renderDevice->window();
    _window->makeCurrent();
    debugAssertGLOk();

    if (settings.useNetwork) {
        networkDevice = new NetworkDevice();
        networkDevice->init(debugLog);
    } else {
        networkDevice = NULL;
    }


    {
        TextOutput t;

        t.writeSymbols("System","{");
        t.pushIndent();
        t.writeNewline();
        System::describeSystem(t);
        if (renderDevice) {
            renderDevice->describeSystem(t);
        }

        if (networkDevice) {
            networkDevice->describeSystem(t);
        }
        t.writeNewline();
        t.writeSymbol("}");
        t.writeNewline();

        std::string s;
        t.commitString(s);
        debugLog->printf("%s\n", s.c_str());
    }

    debugCamera  = GCamera();

    debugAssertGLOk();
    loadFont(settings.debugFontName);
    debugAssertGLOk();

    userInput = new UserInput();

    debugController.init(renderDevice, userInput);
    debugController.setMoveRate(10);
    debugController.setPosition(Vector3(0, 0, 4));
    debugController.lookAt(Vector3::zero());
    debugController.setActive(true);
    debugCamera.setPosition(debugController.getPosition());
    debugCamera.lookAt(Vector3::zero());

    autoResize                  = true;
    _debugMode                  = false;
    debugShowText               = true;
    debugQuitOnEscape           = true;
    debugTabSwitchCamera        = true;
    debugShowRenderingStats     = true;
    catchCommonExceptions       = true;

    debugAssertGLOk();
}


void GApp::loadFont(const std::string& fontName) {
    std::string filename = fontName;
    if (! fileExists(filename)) {

        if (fileExists(dataDir + filename)) {
            filename = dataDir + filename;
        } else if (fileExists(dataDir + "font/" + filename)) {
            filename = dataDir + "font/" + filename;
        }
    }

    if (fileExists(filename)) {
        debugFont = GFont::fromFile(renderDevice, filename);
    } else {
        debugLog->printf(
            "Warning: G3D::GApp could not load font \"%s\".\n"
            "This may be because the G3D::GApp::Settings::dataDir was not\n"
            "properly set in main().\n",
            filename.c_str());

        debugFont = NULL;
    }
}


bool GApp::debugMode() const {
    return _debugMode;
}


void GApp::setDebugMode(bool b) {
    if (! b) {
        _debugControllerWasActive = debugMode();
    } else {
        debugController.setActive(_debugControllerWasActive);
    }
    _debugMode = b;
}


void GApp::debugPrintf(const char* fmt ...) {
    if (debugMode() && debugShowText) {

        va_list argList;
        va_start(argList, fmt);
        std::string s = G3D::vformat(fmt, argList);
        va_end(argList);

        debugText.append(s);
    }    
}


GApp::~GApp() {
    if (networkDevice) {
        networkDevice->cleanup();
        delete networkDevice;
    }

    debugFont = NULL;
    delete userInput;
    userInput = NULL;

    renderDevice->cleanup();
    delete renderDevice;
    renderDevice = NULL;

    if (_hasUserCreatedWindow) {
        delete _window;
        _window = NULL;
    }

    VARArea::cleanupAllVARAreas();

    delete debugLog;
    debugLog = NULL;
}


void GApp::run() {
    if (catchCommonExceptions) {
        try {
            main();
        } catch (const char* e) {
            alwaysAssertM(false, e);
        } catch (const GImage::Error& e) {
            alwaysAssertM(false, e.reason + "\n" + e.filename);
        } catch (const std::string& s) {
            alwaysAssertM(false, s);
        } catch (const TextInput::WrongTokenType& t) {
            alwaysAssertM(false, t.message);
        } catch (const TextInput::WrongSymbol& t) {
            alwaysAssertM(false, t.message);
        } catch (const VertexAndPixelShader::ArgumentError& e) {
            alwaysAssertM(false, e.message);
        } catch (const LightweightConduit::PacketSizeException& e) {
            alwaysAssertM(false, e.message);
        }
    } else {
        main();
    }
}


void GApp::renderDebugInfo() {
    if (debugMode() && ! debugFont.isNull()) {
        // Capture these values before we render debug output
        int majGL  = renderDevice->debugNumMajorOpenGLStateChanges();
        int majAll = renderDevice->debugNumMajorStateChanges();
        int minGL  = renderDevice->debugNumMinorOpenGLStateChanges();
        int minAll = renderDevice->debugNumMinorStateChanges();
        int pushCalls = renderDevice->debugNumPushStateCalls();

        renderDevice->push2D();
            Color3 color = Color3::white();
            double size = 10;

            double x = 5;
            Vector2 pos(x, 5);

            if (debugShowRenderingStats) {

                renderDevice->setBlendFunc(RenderDevice::BLEND_SRC_ALPHA, RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);
                Draw::fastRect2D(Rect2D::xywh(2, 2, 796, size * 5), renderDevice, Color4(0, 0, 0, 0.3f));

                Color3 statColor = Color3::yellow();

                debugFont->draw2D(renderDevice->getCardDescription() + "   " + System::version(), 
                    pos, size, color);
                pos.y += size * 1.5f;
                
                std::string s = format(
                    "% 4dfps % 4.1gM tris % 4.1gM tris/s   GL Calls: %d/%d Maj; %d/%d Min; %d push", 
                    iRound(m_graphicsWatch.smoothFPS()),
                    iRound(renderDevice->getTrianglesPerFrame() / 1e5) * .1f,
                    iRound(renderDevice->getTrianglesPerFrame() / 1e5) * .1f,
                    majGL, majAll, minGL, minAll, pushCalls);
                debugFont->draw2D(s, pos, size, statColor);

                pos.x = x;
                pos.y += size * 1.5;

                {
                float g = m_graphicsWatch.smoothElapsedTime();
                float n = m_networkWatch.smoothElapsedTime();
                float s = m_simulationWatch.smoothElapsedTime();
                float L = m_logicWatch.smoothElapsedTime();
                float u = m_userInputWatch.smoothElapsedTime();
                float w = m_waitWatch.smoothElapsedTime();

                float total = g + n + s + L + u + w;

                float norm = 100.0f / total;

                // Normalize the numbers
                g *= norm;
                n *= norm;
                s *= norm;
                L *= norm;
                u *= norm;
                w *= norm;

                std::string str = 
                    format("Time: %3.0f%% Gfx, %3.0f%% Sim, %3.0f%% Lgc, %3.0f%% Net, %3.0f%% UI, %3.0f%% wait", 
                        g, s, L, n, u, w);
                debugFont->draw2D(str, pos, size, statColor);
                }

                pos.x = x;
                pos.y += size * 3;
            }

            for (int i = 0; i < debugText.length(); ++i) {
                debugFont->draw2D(debugText[i], pos, size, color, Color3::black());
                pos.y += size * 1.5;
            }


        renderDevice->pop2D();
    }
}

void GApp::addModule(const GModuleRef& module, GModuleManager::EventPriority priority) {
    m_moduleManager->add(module, priority);
}


void GApp::removeModule(const GModuleRef& module) {
    m_moduleManager->remove(module);
}

//////////////////////////////////////////////


GApplet::GApplet(GApp* _app) : 
    app(_app), 
	lastWaitTime(System::time()),
    m_desiredFrameRate(inf()),
    m_simTimeRate(1.0), 
    m_realTime(0), 
    m_simTime(0),
    m_moduleManager(GModuleManager::create()) {
    
    debugAssert(app != NULL);
}


bool GApplet::onEvent(const GEvent& event) {
    processEvent(event); // TODO: Remove when deprecated

    return GModuleManager::onEvent(event, app->m_moduleManager, m_moduleManager);
}


void GApplet::getPosedModel(
    Array<PosedModelRef>& posedArray, 
    Array<PosedModel2DRef>& posed2DArray) {

    m_moduleManager->getPosedModel(posedArray, posed2DArray);
    app->m_moduleManager->getPosedModel(posedArray, posed2DArray);

}


void GApplet::onGraphics(RenderDevice* rd) {
    (void)rd;
    doGraphics();
}


void GApplet::doGraphics() {
    Array<PosedModelRef>        posedArray;
    Array<PosedModel2DRef>      posed2DArray;
    Array<PosedModelRef>        opaque, transparent;

    // By default, render the installed modules
    getPosedModel(posedArray, posed2DArray);

    // 3D
    if (posedArray.size() > 0) {
        Vector3 lookVector = app->renderDevice->getCameraToWorldMatrix().lookVector();
        PosedModel::sort(posedArray, lookVector, opaque, transparent);

        for (int i = 0; i < opaque.size(); ++i) {
            opaque[i]->render(app->renderDevice);
        }

        for (int i = 0; i < transparent.size(); ++i) {
            transparent[i]->render(app->renderDevice);
        }
    }

    // 2D
    if (posed2DArray.size() > 0) {
        app->renderDevice->push2D();
            PosedModel2D::sort(posed2DArray);
            for (int i = 0; i < posed2DArray.size(); ++i) {
                posed2DArray[i]->render(app->renderDevice);
            }
        app->renderDevice->pop2D();
    }
}


void GApplet::onNetwork() {
    doNetwork();
}

    
void GApplet::addModule(const GModuleRef& module, GModuleManager::EventPriority priority) {
    m_moduleManager->add(module, priority);
}


void GApplet::removeModule(const GModuleRef& module) {
    m_moduleManager->remove(module);
}


void GApplet::beginRun() {
    endApplet = false;

    onInit();

    // Move the controller to the camera's location
    app->debugController.setCoordinateFrame
        (app->debugCamera.getCoordinateFrame());

    now = System::getTick() - 0.001;
}


void GApplet::oneFrame() {
    lastTime = now;
    now = System::getTick();
    RealTime timeStep = now - lastTime;

    // User input
    app->m_userInputWatch.tick();
    doUserInput(); // TODO: remove
    onUserInput(app->userInput);
    app->m_moduleManager->onUserInput(app->userInput);
    m_moduleManager->onUserInput(app->userInput);
    app->m_userInputWatch.tock();

    // Network
    app->m_networkWatch.tick();
    onNetwork();
    app->m_moduleManager->onNetwork();
    m_moduleManager->onNetwork();
    app->m_networkWatch.tock();

    // Simulation
    app->m_simulationWatch.tick();
		app->debugController.doSimulation(clamp(timeStep, 0.0, 0.1));
		app->debugCamera.setCoordinateFrame
			(app->debugController.getCoordinateFrame());

		double rate = simTimeRate();    
        RealTime rdt = timeStep;
        SimTime  sdt = timeStep * rate;
        SimTime  idt = desiredFrameDuration() * rate;

		onSimulation(rdt, sdt, idt);
        app->m_moduleManager->onSimulation(rdt, sdt, idt);
        m_moduleManager->onSimulation(rdt, sdt, idt);

		setRealTime(realTime() + rdt);
		setSimTime(simTime() + sdt);
		setIdealSimTime(idealSimTime() + idt);
    app->m_simulationWatch.tock();

    // Logic
    app->m_logicWatch.tick();
        onLogic();
        app->m_moduleManager->onLogic();
        m_moduleManager->onLogic();
    app->m_logicWatch.tock();

    // Wait 
    // Note: we might end up spending all of our time inside of
    // RenderDevice::beginFrame.  Waiting here isn't double waiting,
    // though, because while we're sleeping the CPU the GPU is working
    // to catch up.

    app->m_waitWatch.tick();
    {
        RealTime now = System::time();
        // Compute accumulated time
        onWait(now - lastWaitTime, desiredFrameDuration());
        lastWaitTime = System::time();
    }
    app->m_waitWatch.tock();

    // Graphics
    app->m_graphicsWatch.tick();
        app->renderDevice->beginFrame();
            app->renderDevice->pushState();
                onGraphics(app->renderDevice);
            app->renderDevice->popState();
            app->renderDebugInfo();
        app->renderDevice->endFrame();
        app->debugText.clear();
    app->m_graphicsWatch.tock();

    if ((endApplet || app->endProgram) && app->window()->requiresMainLoop()) {
        app->window()->popLoopBody();
    }
}


void GApplet::onWait(RealTime t, RealTime desiredT) {
    System::sleep(max(0.0, desiredT - t));
}


void GApplet::endRun() {
    onCleanup();

    Log::common()->section("Files Used");
    for (int i = 0; i < _internal::currentFilesUsed.size(); ++i) {
        Log::common()->println(_internal::currentFilesUsed[i]);
    }
    Log::common()->println("");

    if (app->window()->requiresMainLoop() && app->endProgram) {
        exit(0);
    }
}


void GApplet::run() {

    if (app->window()->requiresMainLoop()) {

        app->window()->pushLoopBody(this);

    } else {
        beginRun();

        // Main loop
        do {
            oneFrame();   
        } while (! app->endProgram && ! endApplet);

        endRun();
    }
}


void GApplet::doUserInput() {

    app->userInput->beginEvents();

    // Event handling
    GEvent event;
    while (app->window()->pollEvent(event)) {

        if (onEvent(event)) {
            continue;
        }

        switch(event.type) {
        case SDL_QUIT:
	        app->endProgram = true;
            endApplet = true;
	        break;

        case SDL_VIDEORESIZE:
            if (app->autoResize) {
                app->renderDevice->notifyResize
                    (event.resize.w, event.resize.h);
                Rect2D full = 
                    Rect2D::xywh(0, 0, 
                                 app->renderDevice->getWidth(), 
                                 app->renderDevice->getHeight());
                app->renderDevice->setViewport(full);
            }
            break;

	    case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                if (app->debugMode() && app->debugQuitOnEscape) {
                    app->endProgram = true;
                }
                break;

            case SDLK_TAB:
                // Make sure it wasn't ALT-TAB that was pressed !
                if (app->debugMode() && app->debugTabSwitchCamera && 
                    ! (app->userInput->keyDown(SDLK_RALT) || 
                       app->userInput->keyDown(SDLK_LALT))) {

                    app->debugController.setActive
                        (! app->debugController.active());
                }
                break;

            // Add other key handlers here
            default:;
            }
            break;

        // Add other event handlers here

        default:;
        }

        app->userInput->processEvent(event);
    }

    app->userInput->endEvents();
}

}
