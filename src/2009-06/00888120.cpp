// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_unit_2054d593ab842fd5.cpp

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
static RBX::Reflection::BoundFuncDesc<RBX::Network::Server, void(int), 1>  f_disconnect(&RBX::Network::Server::stop, "Stop", "blockDuration", 1000, (RBX::Reflection::FunctionDescriptor::Security)1);
