/**
  @file Network_Demo/ServerAd.h

  @author Morgan McGuire, matrix@graphics3d.com
  @created 2004-03-28
  @edited  2004-03-28
 */

#ifndef SERVERAD_H
#define SERVERAD_H

#include <G3DAll.h>

/**
 An advertisement used by servers to tell potential clients
 about themselves.
 */
class ServerAd : public DiscoveryAdvertisement {
public:
    ServerAd();

    /** Name of the hosting server */
    std::string     name;

    // Can add other information here (e.g. current score,
    // number of players) to broadcast other information
    // about a server.

    virtual void serialize(BinaryOutput& b) const;

    virtual void deserialize(BinaryInput& b);

    virtual uint32 type () const;
};

enum {GAME_PORT = 1424};

#endif
