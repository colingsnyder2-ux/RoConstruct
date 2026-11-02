#include "StandardVerbs.h"
#include "v8datamodel/Workspace.h"
namespace RBX {
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
bool AttachCameraCommand::isChecked() const {
    Camera* camera = workspace->getCamera();
    return camera->getCameraType() == Camera::ATTACH_CAMERA;
}
bool TrackCameraCommand::isChecked() const {
    Camera* camera = workspace->getCamera();
    return camera->getCameraType() == Camera::TRACK_CAMERA;
}
bool FollowCameraCommand::isChecked() const {
    Camera* camera = workspace->getCamera();
    return camera->getCameraType() == Camera::FOLLOW_CAMERA;
}
bool WatchCameraCommand::isChecked() const {
    Camera* camera = workspace->getCamera();
    return camera->getCameraType() == Camera::WATCH_CAMERA;
}
}
