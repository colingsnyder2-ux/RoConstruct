// >>> native-status (generated) -- do not edit >>>
// BasicVerbConstructors | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 8fb45018 | roc native-status --write
#include "../../native-headers/v8datamodel/DataModel.h"
#include "../../native-headers/StandardVerbs.h"

namespace RBX {

FirstPersonCommand::FirstPersonCommand(DataModel* model) : Verb(model, "FirstPersonIndicator"), dataModel(model) {}
StatsCommand::StatsCommand(DataModel* model) : Verb(model, "Stats"), dataModel(model) {}
EngineStatsCommand::EngineStatsCommand(DataModel* model) : Verb(model, "EngineStats"), dataModel(model) {}
JoinCommand::JoinCommand(DataModel* model) : Verb(model, "JoinCommand"), dataModel(model) {}
ClearStarterpack::ClearStarterpack(DataModel* model) : Verb(model, "ClearStarterpack"), dataModel(model) {}
ClearBackpack::ClearBackpack(DataModel* model) : Verb(model, "ClearBackpack"), dataModel(model) {}
ForceAssertionCommand::ForceAssertionCommand(DataModel* model) : Verb(model, "ForceAssertion") {}
DeleteBase::DeleteBase(DataModel* model, std::string name, bool reward) : EditSelectionVerb(name, model), rewardHopper(reward) {}
inline MoveUpSelectionVerb::MoveUpSelectionVerb(DataModel* dm, const std::string& name, float height)
    : EditSelectionVerb(name, dm), moveUpHeight(height) {}
MoveUpPlateVerb::MoveUpPlateVerb(DataModel* dm) : MoveUpSelectionVerb(dm, "SelectionUpPlate", 0.4f) {}
MoveUpBrickVerb::MoveUpBrickVerb(DataModel* dm) : MoveUpSelectionVerb(dm, "SelectionUpBrick", 1.2f) {}

}
