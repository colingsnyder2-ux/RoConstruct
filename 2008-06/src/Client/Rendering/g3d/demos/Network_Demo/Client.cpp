/**
  @file Network_Demo/Client.cpp

  @author Morgan McGuire, matrix@graphics3d.com
  @created 2004-03-28
  @edited  2005-01-22
 */

#include "Client.h"
#include "Server.h"
#include "App.h"
#include "messages.h"

// Windows.h defines DEFAULT_PITCH, which we use as a variable name
#ifdef DEFAULT_PITCH
#undef DEFAULT_PITCH
#endif

Client::Client(App* _app) : GApplet(_app), app(_app) {
    serverProxy = ServerProxy(_app, this);
}


void Client::onInit()  {
    // Called before Client::run() beings
    app->debugCamera.setPosition(Vector3(0, 2, 10));
    app->debugCamera.lookAt(Vector3(0, 2, 0));

    localID = Entity::NO_ID;

    // Connect
    serverProxy.connect(selectedServer.address);

    camera.setPosition(Vector3::ZERO);
    camera.lookAt(-Vector3::UNIT_Z);
    Log::common()->printf("Client::init\n");

    setDesiredFrameRate(40);
}


void Client::onCleanup() {
    // Called when Client::run() exits
    entityTable.clear();
}


void Client::onNetwork() {

	// Poll net messages here
    if (app->hostingServer) {
        app->hostingServer->onNetwork();
    }

    while (serverProxy.net->messageWaiting() && serverProxy.net->ok()) {
        switch (serverProxy.net->waitingMessageType()) {
        case NO_MSG:
            // No message waiting
            break;

        case SignOnMessage_MSG:
            {
                SignOnMessage msg;
                serverProxy.net->receive(msg);
                localID = msg.id;
            }
            break;

        case CreateEntityMessage_MSG:
            {
                Entity entity;
                serverProxy.net->receive(entity);
                entityTable.set(entity.id, entity);

                if (localID == entity.id) {
                    // This is the client's own entity.  Set the
                    // window caption.
                    app->renderDevice->setCaption(entity.name + " - G3D Network Demo");
                }
                app->debugLog->printf("CLIENT: Created entity \"%s\"\n\n", 
                    entity.name.c_str());
            }
            break;

        case EntityStateMessage_MSG:
            {
                EntityStateMessage msg;
                serverProxy.net->receive(msg);
                if (entityTable.containsKey(msg.id)) {
                    entityTable[msg.id].clientUpdateFromStateMessage(msg, localID);
                }
            }
            break;

        default:
            app->debugLog->printf("CLIENT: Ignored unknown message type %d\n",
                serverProxy.net->waitingMessageType());
            serverProxy.net->receive();
        }
    }
}


void Client::simulateCamera(SimTime dt) {
    if (entityTable.containsKey(localID)) {
        const Entity& me = entityTable[localID];

        double FOLLOW_DISTANCE = 20;
        double FOLLOW_HEIGHT = 4;

        const CoordinateFrame cframe = me.smoothCoordinateFrame();

        // Move the camera to follow the plane
        
        camera.setPosition(cframe.translation 
                + cframe.rotation.getColumn(2) * FOLLOW_DISTANCE
                + Vector3::UNIT_Y * FOLLOW_HEIGHT);

        camera.lookAt(cframe.translation + Vector3::UNIT_Y * FOLLOW_HEIGHT / 2);
    }
}


void Client::onSimulation(RealTime rdt, SimTime sdt, SimTime idt) {
    if (app->hostingServer) {
        app->hostingServer->onSimulation(rdt, sdt, idt);
    }

    simulateEntities(entityTable, sdt);

    simulateCamera(sdt);
}

void Client::onUserInput(UserInput* ui) {
    if (ui->keyPressed(SDLK_ESCAPE)) {
        // Quit back to main menu
        endApplet = true;
    }


    if (entityTable.containsKey(localID) && ! app->debugController.active() && app->userInput->appHasFocus()) {
        Entity& entity = entityTable[localID];
        Controls newControls = entity.controls;

        const int UP_KEY1          = ' ';
        const int UP_KEY2          = SDLK_BACKSPACE;
        const int DOWN_KEY1        = 'z';
        const int DOWN_KEY2        = SDLK_LCTRL;

        // Construct the local reference frame vectors in the world frame
        // (ignores roll and pitch of the aircraft).
        Vector3 localY = Vector3::unitY();
        Vector3 localX = entity.coordinateFrame().rightVector();
        localX = (localX - localY * localX.dot(localY)).direction();
        Vector3 localZ = localX.cross(localY);

        const double speed = 2;

        double dx = app->userInput->getX();
        double dz = app->userInput->getY();
        double mag = sqrt(square(dx) + square(dz));
        if (mag > 0) {
            newControls.desiredVelocity =
                (localX * app->userInput->getX() +
                 -localZ * app->userInput->getY()) * speed / mag;
        } else {
            newControls.desiredVelocity = Vector3::zero();
        }


        // The vertical axis is independent of the others 
        if (app->userInput->keyDown(UP_KEY1) ||
            app->userInput->keyDown(UP_KEY2)) {
            newControls.desiredVelocity.y = speed/2;
        } else if (app->userInput->keyDown(DOWN_KEY1) ||
                   app->userInput->keyDown(DOWN_KEY2)) {
            newControls.desiredVelocity.y = -speed/2;
        } else {
            newControls.desiredVelocity.y = 0;
        }

        // Normalized [-1,-1] to [1,1] mouse
        Vector2 mouse  = -((app->userInput->mouseXY() / 
            Vector2(app->window()->width(), app->window()->height())) * 2 - 
            Vector2(1, 1));

        double mx = mouse.x;
        // Create a dead zone
        mx = max(0.0f, fabsf(mx) - 0.25f) * sign(mx);

        newControls.desiredYawVelocity = mx * toRadians(180);

        if (entity.controls != newControls) {
            // Tell the server our new controls
            app->debugPrintf("CLIENT: send");
            entity.oldDesiredVelocity = entity.currentTiltVelocity;
            entity.oldDesiredVelocityTime = System::time();
            entity.controls = newControls;
            EntityStateMessage msg;
            entity.makeStateMessage(msg);
            serverProxy.net->send(EntityStateMessage_MSG, msg);
        }
    }

	// Add other key handling here
}


void Client::renderEntity(const Entity& entity) {
    static HelicopterRef model;

    if (model.isNull()) {
        model = Helicopter::create(app->dataDir);
    }

    // Lerp between old and new values
    CoordinateFrame cframe = entity.smoothCoordinateFrame();

    // Pose it
    GMaterial material;
    material.color = entity.color;
    material.specularCoefficient = 1.0;
    model->render(app->renderDevice, cframe, entity.pose, material);
}


void Client::renderEntities() {
    EntityTable::Iterator end = entityTable.end();
    for (EntityTable::Iterator e = entityTable.begin(); e != end; ++e) {
        renderEntity(e->value);
    }
}


void Client::onGraphics(RenderDevice* rd) {

    const GCamera& cam = app->debugController.active() ? app->debugCamera : camera;

    LightingParameters lighting(G3D::toSeconds(11, 00, 00, AM));
    app->renderDevice->setProjectionAndCameraMatrix(cam);

    // Cyan background
    app->renderDevice->setColorClearValue(Color3(.1f, .5f, 1));

    app->renderDevice->clear(app->sky.isNull(), true, true);
    if (app->sky.notNull()) {
        app->sky->render(lighting);
    }

    // Setup lighting
    app->renderDevice->enableLighting();
		app->renderDevice->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));
        // Splash light
        app->renderDevice->setLight(1, GLight::directional(-Vector3::unitY(), Color3::white() * 0.20f, false));
		app->renderDevice->setAmbientLightColor(lighting.ambient);

		Draw::axes(CoordinateFrame(Vector3(0, 4, 0)), app->renderDevice);

        for (int x = -10; x < 10; x+=4) {
            for (int z = -10; z < 10; z+=4) {
                Vector3 v(x * 20, -10, z * 20); 
                Draw::box(AABox(v, v + Vector3(2,.2f,2)), app->renderDevice, Color3::RED, Color3::BLACK);
            }
        }

        renderEntities();

    app->renderDevice->disableLighting();

    if (app->sky.notNull()) {
        app->sky->renderLensFlare(lighting);
    }

    app->renderDevice->push2D();

        // Entity names
        {
            EntityTable::Iterator end = entityTable.end();
            for (EntityTable::Iterator e = entityTable.begin(); e != end; ++e) {
                const Entity& entity = e->value;
                Vector3 pos = cam.project(entity.smoothCoordinateFrame().translation,
                    app->renderDevice->getViewport());

                if (pos.isFinite()) {
                    app->font->draw2D(app->renderDevice, entity.name, pos.xy(), 16, Color3::WHITE, Color3::BLACK,
                        GFont::XALIGN_CENTER);
                }
            }
        }

        // Server crash messages
        if (! serverProxy.ok()) {
            app->font->draw2D(app->renderDevice, "Lost connection to server.", Vector2(5, 5), 14,
                Color3(1.0f, 0.4f, 0.4f), Color3::BLACK);
        }

        if (app->hostingServer && ! app->hostingServer->ok()) {
            app->font->draw2D(app->renderDevice, "(Local Server Crashed)", Vector2(5, 25), 14,
                Color3(1.0f, 0.4f, 0.4f), Color3::BLACK);
        }
    app->renderDevice->pop2D();

    if (app->hostingServer) {
        app->hostingServer->onGraphics(rd);
    }
}


///////////////////////////////////////////////////////////////////////////

ServerProxy::ServerProxy(App* app, Client* client) : app(app), client(client) {
}


void ServerProxy::connect(const NetAddress& address) {
    app->debugLog->printf("\nCLIENT: --------------------------\n");
    app->debugLog->printf("\nConnecting to \"%s\"\n\n", address.toString().c_str());

    net = app->networkDevice->createReliableConduit(address);

    if (net.isNull() || ! net->ok()) {
        app->debugLog->printf("\nConnect failed\n\n");
    } else {
        app->debugLog->printf("\nConnected to server\n\n");
    }

    app->debugLog->printf("--------------------------------\n");
}


bool ServerProxy::ok() const {
    return net.notNull() && (net->ok());
}
