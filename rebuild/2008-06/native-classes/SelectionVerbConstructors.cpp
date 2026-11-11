// >>> native-status (generated) -- do not edit >>>
// SelectionVerbConstructors | 2008-06 | draft (no current byte proof)
// 0/14 mapped addresses byte-exact | 14 unproved | no mapped strings | by colin (+1) (mixed 3)
// <<< native-status | src d436a674 | roc native-status --write
#include "StandardVerbs.h"

namespace RBX {

BoolPropertyVerb::BoolPropertyVerb(const std::string& name, DataModel* model, const char* property)
    : EditSelectionVerb(name, model), propertyName(Name::declare(property, -1)) {}

AnchorVerb::AnchorVerb(DataModel* model) : BoolPropertyVerb("AnchorVerb", model, "Anchored") {}
TranslucentVerb::TranslucentVerb(DataModel* model) : BoolPropertyVerb("TranslucentVerb", model, "Transparent") {}
CanCollideVerb::CanCollideVerb(DataModel* model) : BoolPropertyVerb("CanCollideVerb", model, "CanCollide") {}
GroupSelectionVerb::GroupSelectionVerb(DataModel* model) : EditSelectionVerb("Group", model) {}
WeldSelectionVerb::WeldSelectionVerb(DataModel* model) : EditSelectionVerb("WeldSelection", model) {}
SnapSelectionVerb::SnapSelectionVerb(DataModel* model) : EditSelectionVerb("SnapSelection", model) {}
UngroupSelectionVerb::UngroupSelectionVerb(DataModel* model) : EditSelectionVerb("UnGroup", model) {}
DuplicateSelectionVerb::DuplicateSelectionVerb(DataModel* model) : EditSelectionVerb("Duplicate", model) {}
AttachCameraCommand::AttachCameraCommand(DataModel* model) : EditSelectionVerb("AttachCamera", model) {}
TrackCameraCommand::TrackCameraCommand(DataModel* model) : EditSelectionVerb("TrackCamera", model) {}
FollowCameraCommand::FollowCameraCommand(DataModel* model) : EditSelectionVerb("FollowCamera", model) {}
WatchCameraCommand::WatchCameraCommand(DataModel* model) : EditSelectionVerb("WatchCamera", model) {}
MoveDownSelectionVerb::MoveDownSelectionVerb(DataModel* model) : EditSelectionVerb("SelectionDown", model) {}

}
