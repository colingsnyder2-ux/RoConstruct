// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/partchunk-profile /I{headers}/part-embedded /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Original 004db7c0: real Workspace descendant -> native render chunk registration.
#include "RenderLib/ViewNew2008.h"
#include "ViewNew/PartChunk.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Decal.h"
namespace RBX { namespace ViewNew {
void ViewRbxGfx::onWorkspaceDescendentAdded(boost::shared_ptr<Instance> descendent)
{
    if (PartInstance* part=dynamic_cast<PartInstance*>(descendent.get())) {
        new Part(shared_from(part),this);
        return;
    }
    PartInstance* parent=dynamic_cast<PartInstance*>(descendent->getParent());
    if (parent) {
        if (RBX::Texture* texture=dynamic_cast<RBX::Texture*>(descendent.get())) {
            new Texture(texture,parent,this);
            return;
        }
    }
    if (RBX::Decal* decal=dynamic_cast<RBX::Decal*>(descendent.get()))
        new Decal(decal,dynamic_cast<PartInstance*>(decal->getParent()),this);
}
} }
