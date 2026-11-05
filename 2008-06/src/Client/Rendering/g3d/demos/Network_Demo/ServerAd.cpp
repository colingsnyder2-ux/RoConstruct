
#include "ServerAd.h"


ServerAd::ServerAd() : name("") {
}


void ServerAd::serialize(BinaryOutput& b) const {
    DiscoveryAdvertisement::serialize(b);
    b.writeString(name);
}


void ServerAd::deserialize(BinaryInput& b) {
    DiscoveryAdvertisement::deserialize(b);
    name = b.readString();
}


uint32 ServerAd::type () const {
    // We can return any number greater than 1000 that we want;
    // this value is application specific.
    return 1001;
}
