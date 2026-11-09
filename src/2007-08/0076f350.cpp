// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_espeon_disconnect_aug2007_715e79693b99c027.cpp

// Candidate translation unit (score above; library headers required).
#include <RakNetTypes.h>
#include <RakPeer.h>
#include <MessageIdentifiers.h>
#include "API.h"
#include "Client.h"
#include "util/standardout.h"
static RBX::Reflection::BoundFuncDesc<RBX::Network::Client, void(int), 1> f_disconnect(&RBX::Network::Client::disconnect, "Disconnect", "blockDuration", 3000, RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
