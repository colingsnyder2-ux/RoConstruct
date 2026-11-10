// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// Inactive recovery. Render predicate ABI and ClickDetector query remain unproven.
#include "tool/NullTool.h"
#include "v8datamodel/UserController.h"
#include "Network/Players.h"
#include "humanoid/Humanoid.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {
char sNewNullTool[] = "NewNullTool";
NewNullTool::NewNullTool(Workspace* workspace)
    : Base(workspace), cursor("ArrowCursor"), hasWaypoint(false) {}
NewNullTool::~NewNullTool() {}
MouseCommand* NewNullTool::onMouseUp(const UIEvent&)
{
    releaseCapture();
    return this;
}
bool NewNullTool::isLocalHeadHidden() const
{
    ModelInstance* character = Network::Players::findLocalCharacter(workspace);
    if (character) {
        Humanoid* humanoid = Humanoid::modelIsCharacter(character);
        if (humanoid) {
            PartInstance* head = humanoid->getHead();
            if (head && head->getAlphaModifier() == 0.0f) return true;
        }
    }
    return false;
}

// Original 00629b20 is a cdecl ClickDetector query. Its C++ symbol is unproven.
// This inactive declaration preserves its typed ABI without inventing a class layout.
bool queryClickDetectors(PartInstance*, float, bool);
void NewNullTool::onMouseIdle(const UIEvent& event)
{
    PartInstance* part = getUnlockedPartByLocalCharacter(event, waypoint);
    bool clickable = queryClickDetectors(part, distanceFromCharacter(waypoint), false);
    if (part) {
        if (clickable) { cursor = "DragCursor"; return; }
        if (characterCanReach(waypoint) && !isLocalHeadHidden()) {
            cursor = "ArrowCursor";
            return;
        }
    }
    cursor = "ArrowFarCursor";
}
void NewNullTool::onMouseHover(const UIEvent& event)
{
    PartInstance* part = getUnlockedPartByLocalCharacter(event, waypoint);
    bool clickable = queryClickDetectors(part, distanceFromCharacter(waypoint), false);
    if (part) {
        if (clickable) { cursor = "DragCursor"; hasWaypoint = false; return; }
        if (characterCanReach(waypoint) && !isLocalHeadHidden()) {
            cursor = "ArrowCursor";
            hasWaypoint = true;
            return;
        }
    }
    cursor = "ArrowFarCursor";
    hasWaypoint = false;
}
MouseCommand* NewNullTool::onMouseDown(const UIEvent& event)
{
    G3D::Vector3 point;
    PartInstance* part = getUnlockedPartByLocalCharacter(event, point);
    if (queryClickDetectors(part, distanceFromCharacter(point), true)) return this;
    if (part && characterCanReach(point) && !isLocalHeadHidden()) {
            ModelInstance* character = Network::Players::findLocalCharacter(workspace);
            if (character && !character->contains(part)) {
                if (Humanoid* humanoid = Humanoid::modelIsCharacter(character))
                    humanoid->moveTo(point, part);
            }
    }
    return this;
}
void NewNullTool::render3dAdorn(Adorn* adorn)
{
    if (hasWaypoint) {
        ControllerService* service = ServiceProvider::find<ControllerService>(workspace);
        if (service) {
            MovementKeys keys;
            service->getHardwareDevice()->getMovementKeys(keys);
            if (!keys.any()) Humanoid::renderWaypoint(adorn, waypoint);
        }
    }
}
template<> const Name& Named<MouseCommand, sNewNullTool>::name()
{
    static const Name& value = Name::declare(sNewNullTool, -1);
    return value;
}
template<> const Name& Named<MouseCommand, sNewNullTool>::getName() const
{
    return Name::declare<sNewNullTool>();
}
}
