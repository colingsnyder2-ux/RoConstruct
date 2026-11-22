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
// Batch 36: follows the 2007 client's shape (openrbx RenderLibNew/View.cpp View::onWorkspaceDescendentAdded 0050b7e0:
// `if (part) .. else { .. Texture: return; .. Decal: return; }`, 2008 moves the Decal test out of the parent branch and
// passes pointers), 536 B against 541 B. The Part branch (inlined ~shared_ptr, private `ret 8`) now matches. Remaining:
// the shared out-of-line ~shared_ptr tail (00600660) is laid out after the Texture branch (target: after the Decal ctor
// call, 004db9b8, with Texture `jmp`ing forward) and the Decal-null test jumps to the inline Part-path exit (target: to the
// out-of-line tail). Rejected batch 36: the same shape without the Decal `return` (548 B, the original layout) and with a
// trailing `return;` at the end of the else block (548 B).
// Earlier NEAR MISS (parked after 3 trials): the previous shape compiled to 548 B against 541 B. The target gives the Part branch its own
// epilogue (inlined ~shared_ptr of the shared_from temporary and of `descendent`, `ret 8` at 004db8e3) while the Texture
// branch `jmp`s to the shared tail 004db9b8 (out-of-line ~shared_ptr 00600660); this spelling puts the private epilogue on
// the Texture branch instead. Rejected: if/else nesting with no returns (513 B, all branches share the tail); early Part
// return followed by an `if (parent && texture) .. else if (decal)` chain (513 B).
namespace RBX { namespace ViewNew {
void ViewG3D::onWorkspaceDescendentAdded(boost::shared_ptr<Instance> descendent)
{
    PartInstance* part=dynamic_cast<PartInstance*>(descendent.get());
    if (part) {
        new Part(shared_from(part),this);
    }
    else {
        if (PartInstance* parentPart=dynamic_cast<PartInstance*>(descendent->getParent())) {
            RBX::Texture* texture=dynamic_cast<RBX::Texture*>(descendent.get());
            if (texture) {
                new Texture(texture,parentPart,this);
                return;
            }
        }
        RBX::Decal* decal=dynamic_cast<RBX::Decal*>(descendent.get());
        if (decal) {
            new Decal(decal,dynamic_cast<PartInstance*>(decal->getParent()),this);
            return;
        }
    }
}
} }
