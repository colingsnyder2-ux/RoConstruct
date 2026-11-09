/**
  @file Network_Demo/App.h

  @author Morgan McGuire, matrix@graphics3d.com
  @created 2004-03-28
  @edited  2004-03-30
 */

#ifndef APP_H
#define APP_H

#include <G3DAll.h>

class App : public GApp {
protected:

    void main();

public:

    SkyRef              sky;

    GFontRef            font;

    /** NULL if not hosting.  Client is responsible
        for calling doSimulation and doNetwork
        on the hostingServer when it is non-null.
     */
    class Server*       hostingServer;

    DiscoverySettings   discoverySettings;

    App(const GAppSettings& settings);
};

/** Used for debugging */
extern App*         app;

#endif

