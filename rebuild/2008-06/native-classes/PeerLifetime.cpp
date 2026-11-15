#include <RakPeer.h>
#include "Replicator.h"
namespace RBX { namespace Network {
Peer::~Peer() { rakPeer->DetachPlugin(this); }
}}
