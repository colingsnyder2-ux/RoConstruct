// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// SurfaceToolSiblings | 2008-06 | 20 byte-exact, inactive (not link-selected)
// 20/20 mapped addresses byte-exact | named 4 | 0 unproved | 1 referenced strings (not rechecked) | by king_originala (+2) (mixed 2)
// <<< native-status | src 4faf1d68 | roc native-status --write
#include "tool/SurfaceTools.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"

namespace RBX {
#define RBX_SURFACE_CURSOR(Class, Cursor) \
const std::string Class::getCursorName() const { return Cursor; } \
MouseCommand* Class::isSticky() const { return new Class(workspace); }

RBX_SURFACE_CURSOR(GlueTool, "GlueCursor")
void GlueTool::applyToSurface(Surface* surface) { surface->getPartInstance()->destroyJoints(); surface->flat(); surface->setSurfaceType(GLUE); surface->getPartInstance()->join(); ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(PING_SOUND); }
RBX_SURFACE_CURSOR(WeldTool, "WeldCursor")
void WeldTool::applyToSurface(Surface* surface) { surface->getPartInstance()->destroyJoints(); surface->flat(); surface->setSurfaceType(WELD); surface->getPartInstance()->join(); ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(PING_SOUND); }
RBX_SURFACE_CURSOR(StudsTool, "StudsCursor")
void StudsTool::applyToSurface(Surface* surface) { surface->getPartInstance()->destroyJoints(); surface->flat(); surface->setSurfaceType(STUDS); surface->getPartInstance()->join(); ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(PING_SOUND); }
RBX_SURFACE_CURSOR(InletTool, "InletCursor")
void InletTool::applyToSurface(Surface* surface) { surface->getPartInstance()->destroyJoints(); surface->flat(); surface->setSurfaceType(INLET); surface->getPartInstance()->join(); ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(PING_SOUND); }
RBX_SURFACE_CURSOR(HingeTool, "HingeCursor")
void HingeTool::applyToSurface(Surface* surface) { surface->getPartInstance()->destroyJoints(); surface->setSurfaceType(ROTATE); surface->setSurfaceInput(Controller::NO_INPUT); surface->setParamA(0.0f); surface->setParamB(0.0f); surface->getPartInstance()->join(); }
#undef RBX_SURFACE_CURSOR

#define RBX_MOTOR_TOOL(Class, Input) \
const std::string Class::getCursorName() const { return "MotorCursor"; } \
MouseCommand* Class::isSticky() const { return NULL; } \
void Class::applyToSurface(Surface* surface) { surface->getPartInstance()->destroyJoints(); surface->setSurfaceType(ROTATE_V); surface->setSurfaceInput(Input); surface->setParamA(-0.1f); surface->setParamB(0.1f); surface->getPartInstance()->join(); }
RBX_MOTOR_TOOL(RightMotorTool, Controller::RIGHT_TRACK_INPUT)
RBX_MOTOR_TOOL(LeftMotorTool, Controller::LEFT_TRACK_INPUT)
RBX_MOTOR_TOOL(OscillateMotorTool, Controller::SIN_INPUT)
#undef RBX_MOTOR_TOOL
}
