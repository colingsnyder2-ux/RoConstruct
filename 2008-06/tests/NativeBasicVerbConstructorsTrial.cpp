#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"
namespace RBX {
FirstPersonCommand::FirstPersonCommand(DataModel* model) : Verb(model, "FirstPersonIndicator"), dataModel(model) {}
StatsCommand::StatsCommand(DataModel* model) : Verb(model, "Stats"), dataModel(model) {}
EngineStatsCommand::EngineStatsCommand(DataModel* model) : Verb(model, "EngineStats"), dataModel(model) {}
JoinCommand::JoinCommand(DataModel* model) : Verb(model, "JoinCommand"), dataModel(model) {}
ClearStarterpack::ClearStarterpack(DataModel* model) : Verb(model, "ClearStarterpack"), dataModel(model) {}
ClearBackpack::ClearBackpack(DataModel* model) : Verb(model, "ClearBackpack"), dataModel(model) {}
ForceAssertionCommand::ForceAssertionCommand(DataModel* model) : Verb(model, "ForceAssertion") {}
DeleteBase::DeleteBase(DataModel* model, std::string name, bool reward) : EditSelectionVerb(name, model), rewardHopper(reward) {}
}
