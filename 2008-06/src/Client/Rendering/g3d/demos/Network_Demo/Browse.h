/**
  @file Network_Demo/Browse.h

  @author Morgan McGuire, matrix@graphics3d.com
  @created 2004-03-28
  @edited  2004-03-28
 */

#ifndef BROWSE_H
#define BROWSE_H

#include <G3DAll.h>
#include "ServerAd.h"

/**
 The applet that first appears and lets the user
 choose to join an existing game or host a new
 game.

 When Browse::run returns, one of the following is true:

  host == false               selectedServer contains the server to connect to

  host == true                Listen server

  App::endProgram == true     Quit

 */
class Browse : public GApplet {
private:

    class App*                          app;

    DiscoveryClient<ServerAd>           discoveryClient;

    /**
      The last button is exit, the 2nd to last
      is host, the others correspond to discoveryClient
      servers.
      */
    Array<Rect2D>                       button;

public:

    /** When a server is selected, this field is set */
    ServerAd                            selectedServer;

    /** Whether this machine should host */
    bool                                host;

    Browse(App* app);

    virtual ~Browse() {}

    virtual void init();

    virtual void doLogic();

	virtual void doNetwork();

    virtual void doSimulation(SimTime dt);

    virtual void doGraphics();

    virtual void cleanup();
};

#endif
