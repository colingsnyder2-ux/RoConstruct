// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_unit_59e8dbd94278a1e3.cpp

// Candidate translation unit (score above; library headers required).
#include <RakNetTypes.h>
#include <RakPeer.h>
#include <MessageIdentifiers.h>
#include "API.h"
#include "Client.h"
#include "util/standardout.h"
static RBX::Reflection::BoundFuncDesc<RBX::Network::Client, void(std::string, int, int, int), 4> f_connect(&RBX::Network::Client::connect, "Connect", "server", "serverPort", "clientPort", 0, "threadSleepTime", 30, (RBX::Reflection::FunctionDescriptor::Security)1);
