// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_unit_70ba39c0d930824f.cpp

// Candidate translation unit (score above; library headers required).
#include <RakPeer.h>
#include <BitStream.h>
#include "Client.h"
#include "Server.h"
#include "Players.h"
#include "Streaming.h"
#include "PacketIds.h"
#include "v8datamodel/GameSettings.h"
#include "v8datamodel/Teams.h"
#include "util/standardout.h"
static RBX::Reflection::BoundFuncDesc<RBX::Network::Players, void(boost::shared_ptr<RBX::Instance>, std::string), 2> funcReportAbuse(&RBX::Network::Players::reportAbuse, "ReportAbuse", "player", "message", (RBX::Reflection::FunctionDescriptor::Security)4);
