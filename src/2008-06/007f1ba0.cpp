// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_unit_1b4ab45a3f45626b.cpp

// Candidate translation unit (score above; library headers required).
#include <RakNetTypes.h>
#include <RakPeer.h>
#include <MessageIdentifiers.h>
#include "API.h"
#include "Client.h"
#include "util/standardout.h"
static RBX::Reflection::BoundFuncDesc<RBX::Network::Client, void(int), 1> f_disconnect(&RBX::Network::Client::disconnect, "Disconnect", "blockDuration", 3000, (RBX::Reflection::FunctionDescriptor::Security)1);
