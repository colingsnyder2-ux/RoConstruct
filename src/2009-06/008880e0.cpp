// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_unit_fb1c3133f28c6dc2.cpp

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
static RBX::Reflection::BoundFuncDesc<RBX::Network::Server, void(int, int), 2> server_startFunction(&RBX::Network::Server::start, "Start", "port", 0, "threadSleepTime", 20, (RBX::Reflection::FunctionDescriptor::Security)1);
