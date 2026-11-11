// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// LaserTool | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 3e27499e | roc native-status --write
#include "tool/BasicMouseTools.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Explosion.h"
#include "humanoid/Humanoid.h"
#include "util/Sound.h"
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"

namespace RBX {
char sLaserTool[] = "Laser";
const std::string LaserTool::getCursorName() const { return "GunCursor"; }
MouseCommand* LaserTool::isSticky() const { return new LaserTool(workspace); }

void LaserTool::render3dAdorn(Adorn* adorn)
{
    if (frames > 0) {
        --frames;
        adorn->setObjectToWorldMatrix(G3D::CoordinateFrame());
        G3D::Color4 color(G3D::Color3::red(), 1.0f);
        adorn->lineSegment(G3D::LineSegment::fromTwoPoints(origin, target), color, 5.0f);
    }
}

MouseCommand* LaserTool::onMouseDown(const UIEvent& input)
{
    PartInstance* torso = Humanoid::getLocalHeadFromContext(workspace);
    if (torso) {
        origin = torso->getCoordinateFrame().translation;
        G3D::Vector3 hit(0, 0, 0);
        PartInstance* part = getPart(input, NULL, hit);
        if (part) {
            boost::shared_ptr<Explosion> explosion = Creatable<Instance>::create<Explosion>();
            Explosion::propPosition.setValue(explosion.get(), hit);
            Explosion::propBlastPressure.setValue(explosion.get(), 0.0f);
            explosion->setParent(workspace);
            if (!part->getPartLocked()) part->remove();
            ServiceProvider::create<Soundscape::SoundService>(workspace)->playSound(SNAP_SOUND);
        }
        frames = 4;
    }
    return this;
}

template<> const Name& Named<MouseCommand, sLaserTool>::getName() const
{
    return NativeToolName<LaserTool>::get();
}
template<> MouseCommand* TToolVerb<LaserTool, RunStateVerb>::newMouseCommand()
{
    return new LaserTool(dataModel->getWorkspace());
}
}
