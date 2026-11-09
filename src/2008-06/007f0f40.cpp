// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_unit_131496c3322831dc.cpp

// Candidate translation unit (score above; library headers required).
#include "Client.h"
#include "Player.h"
#include "security/SecurityContext.h"
#include "v8datamodel/TimerService.h"
#include "v8datamodel/CharacterAppearance.h"
#include "v8datamodel/Accoutrement.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/Backpack.h"
#include "v8world/World.h"
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
static RBX::Reflection::BoundFuncDesc<RBX::Network::Player, void(bool), 1> loadCharacterFunction(reinterpret_cast<void (RBX::Network::Player::*)(bool)>(&RBX::Network::Player::loadCharacter), "LoadCharacter", "inGame", true, (RBX::Reflection::FunctionDescriptor::Security)1);
