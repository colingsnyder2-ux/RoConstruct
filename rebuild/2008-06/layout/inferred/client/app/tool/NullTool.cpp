#include "humanoid/HumanoidStates1.h"
#include "humanoid/Humanoid.h"

namespace RBX {
namespace HUMAN {

RunningBase::RunningBase(Humanoid* humanoid)
    : Balancing(humanoid, 300.0f, 50.0f),
      floorVelocity(0.0f, 0.0f, 0.0f), floorRotationalVelocity(0.0f),
      desiredVelocity(0.0f, 0.0f, 0.0f), desiredYRotation(0.0f), desiredAltitude(0.0f)
{
    Humanoid::event_Running.fire(humanoid, 0.0f);
}

RunningBase::~RunningBase()
{
}

float RunningBase::getIntendedRotationAboutYAxis() const
{
    return desiredYRotation;
}

}
}

#include "tool/NullTool.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "StandardVerbs.h"

namespace RBX {
char sNullTool[] = "NullTool";
NullTool::NullTool(Workspace* workspace) : Named<MouseCommand, sNullTool>(workspace) {}
NullTool::~NullTool() {}

const std::string NullTool::getCursorName() const { return "ArrowFarCursor"; }
MouseCommand* NullTool::isSticky() const { return new NullTool(workspace); }
MouseCommand* NullTool::onMouseUp(const UIEvent&)
{
    releaseCapture();
    return this;
}

template<> const Name& Named<MouseCommand, sNullTool>::getName() const
{
    return NativeToolName<NullTool>::get();
}
template<> MouseCommand* TToolVerb<NullTool, RunStateVerb>::newMouseCommand()
{
    return new NullTool(dataModel->getWorkspace());
}
}
