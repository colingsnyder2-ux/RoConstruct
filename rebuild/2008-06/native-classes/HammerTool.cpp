// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// HammerTool | 2008-06 | draft (no current byte proof)
// 0/5 mapped addresses byte-exact | 5 unproved | no mapped strings | by king_originala (+2) (mixed 2)
// <<< native-status | src 497a016e | roc native-status --write
#include "tool/BasicMouseTools.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Explosion.h"
#include "util/Sound.h"
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"

namespace RBX {
char sHammerTool[] = "Hammer";
void HammerTool::onMouseIdle(const UIEvent& input)
{
    partInstance = shared_from(getUnlockedPartByLocalCharacter(input));
}

void HammerTool::render3dAdorn(Adorn* adorn)
{
    if (partInstance) partInstance->render3dSelect(adorn, static_cast<SelectState>(1));
}

const std::string HammerTool::getCursorName() const
{
    return partInstance ? "HammerOverCursor" : "HammerCursor";
}

MouseCommand* HammerTool::isSticky() const { return new HammerTool(workspace); }

MouseCommand* HammerTool::onMouseDown(const UIEvent&)
{
    if (partInstance) {
        boost::shared_ptr<Explosion> explosion = Creatable<Instance>::create<Explosion>();
        Explosion::propPosition.setValue(explosion.get(), partInstance->getCoordinateFrame().translation);
        Explosion::propBlastPressure.setValue(explosion.get(), 0.0f);
        explosion->setParent(workspace);
        partInstance->setParent(NULL);
        ServiceProvider::create<Soundscape::SoundService>(workspace)->playSound(BOMB_SOUND);
    }
    return NULL;
}

template<> const Name& Named<MouseCommand, sHammerTool>::getName() const
{
    return NativeToolName<HammerTool>::get();
}
template<> MouseCommand* TToolVerb<HammerTool, RunStateVerb>::newMouseCommand()
{
    return new HammerTool(dataModel->getWorkspace());
}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>;
template class RBX::Reflection::TypedPropertyDescriptor<float>;
template class boost::shared_ptr<RBX::Explosion>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>::GetSet>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<float>::GetSet>;
