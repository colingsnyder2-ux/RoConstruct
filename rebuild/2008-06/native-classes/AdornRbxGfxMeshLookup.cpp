// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// RBX::AdornRbxGfx mesh-cache lookup as compiled into the June 2008 client (inactive native recovery).
// Same original unit as AdornRbxGfx.cpp (image block 0066f900..006743eb). Declarations: RbxGraphics/AdornRbxGfx2008.h.
#include "RbxGraphics/AdornRbxGfx2008.h"

// Declaration: RbxGraphics/AdornRbxGfx2008.h (private, after releaseSubEntities; added in batch 37, so the former
// ADORNRBXGFX_HEADER_DECLARES_GETMESH guard is gone). Measured in batch 35 against a scratch header: 006712e0 and its
// __ehhandler 007dc8e3 compile byte-identical.
namespace RBX
{
    // 006712e0 (thiscall, ret 0x20 = hidden MeshPtr return + std::string by value): called by box 00671fd0,
    // sphere 00672ba0 and ray 006735a0 right after they build a mesh name with _snprintf; meshes (+0x78)
    // find 006710e0, MeshPtr copy ctor (rgmain import) on node +0x28 (value of pair<const string, MeshPtr>) when
    // found, MeshPtr() otherwise, then ~basic_string on the by-value name. EH: __ehhandler 007dc8e3, unwind
    // funclets 007dc8c0 / 007dc8c9.
    // INFERRED: the method name (registry placeholder func_006712e0); the signature is from the call sites.
    // The declare-then-assign iterator (not copy-initialisation) is what reads the find result through eax
    // as the original does (copy-initialisation reads the RVO slot and is 194 bytes).
    Ogre::MeshPtr AdornRbxGfx::getMesh(std::string name)
    {
        std::map<std::string, Ogre::MeshPtr>::iterator it;
        it = meshes.find(name);
        if (it != meshes.end())
            return it->second;
        return Ogre::MeshPtr();
    }
}
