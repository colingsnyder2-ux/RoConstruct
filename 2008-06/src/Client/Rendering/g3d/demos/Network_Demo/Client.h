/**
  @file Network_Demo/Client.h

  @author Morgan McGuire, matrix@graphics3d.com
  @created 2004-03-28
  @edited  2006-01-29
 */

#ifndef CLIENT_H
#define CLIENT_H

#include <G3DAll.h>
#include "ServerAd.h"
#include "Entity.h"

/** Client's representation of the server */
class ServerProxy {
private:
    friend class Client;

    ReliableConduitRef                  net;
    class App*                          app;
    class Client*                       client;

public:

    ServerProxy() : app(NULL), client(NULL) {}
    ServerProxy(App*, Client*);

    bool ok() const;

    void connect(const NetAddress&);

};

/**
 This simple demo applet uses the debug mode as the regular
 rendering mode so you can fly around the scene.
 */
class Client : public GApplet {
private:
    friend class ServerProxy;

    class App*          app;

    ServerProxy         serverProxy;

    EntityTable         entityTable;

    /** ID of my entity */
    Entity::ID          localID;

    GCamera             camera;

    /** Called from renderEntities */
    void renderEntity(const Entity& e);

    /** Called from doGraphics */
    void renderEntities();

    /** Called from doSimulation */
    void simulateCamera(SimTime dt);

public:

    /** Server to which the client should connect. */
    ServerAd            selectedServer;

    Client(App* app); 
    
    virtual ~Client(){}

    virtual void onInit();

    virtual void onUserInput(UserInput* ui);

	virtual void onNetwork();

    virtual void onSimulation(RealTime rdt, SimTime sdt, SimTime idt);

    virtual void onGraphics(RenderDevice* rd);

    virtual void onCleanup();

};

#endif
