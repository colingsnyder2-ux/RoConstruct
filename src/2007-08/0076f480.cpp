// from server: 100% by Yeetserama
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-net roc_unit_57a53b965cd4edd0.cpp

// Candidate translation unit (score above; library headers required).
#include <RakPeer.h>
#include "Server.h"
#include "IdManager.h"
#include "NetworkSettings.h"
#include "PacketIds.h"
#include "API.h"
#include "util/Http.h"
#include "util/standardout.h"
#include <boost/thread.hpp>
static RBX::Reflection::BoundFuncDesc<RBX::Network::Server, void(int), 1>  f_disconnect(&RBX::Network::Server::stop, "Stop", "blockDuration", 1000, (RBX::Reflection::FunctionDescriptor::Security)0);
