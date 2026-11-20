// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/partchunk-profile /I{headers}/part-embedded /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Original 004db7c0: real Workspace descendant -> native render chunk registration.
#include "RenderLib/ViewNew2008.h"
#include "ViewG3D2008/ViewG3D2008.h"
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

// 004db7c0: ViewG3D vtable 00826e04 slot 8. The identity registry names the folded (ICF) body
// ?onWorkspaceDescendentAdded@ViewG3D@ViewNew@RBX@@EAEXV?$shared_ptr@VInstance@RBX@@@boost@@@Z; the ViewRbxGfx copy above
// is the byte-identical sibling in vtable 00826c70 slot 8 (same `ret 8`, new 0xf0 Part 004ebcc0 / Texture 004eafd0 /
// Decal 004eae10 with `this` as the ViewBase*).
// NEAR MISS (parked after 3 trials): this shape compiles to 548 B against 541 B. The target gives the Part branch its own
// epilogue (inlined ~shared_ptr of the shared_from temporary and of `descendent`, `ret 8` at 004db8e3) while the Texture
// branch `jmp`s to the shared tail 004db9b8 (out-of-line ~shared_ptr 00600660); this spelling puts the private epilogue on
// the Texture branch instead. Rejected: if/else nesting with no returns (513 B, all branches share the tail); early Part
// return followed by an `if (parent && texture) .. else if (decal)` chain (513 B).
namespace RBX { namespace ViewNew {
void ViewG3D::onWorkspaceDescendentAdded(boost::shared_ptr<Instance> descendent)
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
