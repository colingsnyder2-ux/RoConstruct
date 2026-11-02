#include "StandardVerbs.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
namespace RBX {
bool AttachCameraCommand::isChecked() const { return workspace->getCamera()->getCameraType() == 1; }
bool TrackCameraCommand::isChecked() const { return workspace->getCamera()->getCameraType() == 3; }
bool FollowCameraCommand::isChecked() const { return workspace->getCamera()->getCameraType() == 4; }
bool WatchCameraCommand::isChecked() const { return workspace->getCamera()->getCameraType() == 2; }
}
