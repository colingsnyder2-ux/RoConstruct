// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
// RBX::DecalTool vtable-slot bodies. Identity: all three are registry placeholders that sit only in the DecalTool
// INamed vtable 0083387c (slots 0x04 / 0x10 / 0x18), inside the part-tools object range 00619a80..0061a41f next to
// the SurfaceTool bodies of SurfaceToolInteractions.cpp (render3dAdorn 00619c30, onMouseHover 00619e50,
// onMouseDown 00619f00); flags follow that unit.
#include "tool/DecalTool.h"
#include "v8datamodel/Workspace.h"

namespace RBX {
void recordCameraHistory(const char*, const Instance*);

// 00619a80 (INamed slot 0x04): releaseCapture (slot 0x28), then the ChangeHistory waypoint 0058c5c0 named after
// getName() (slot 0) with workspace (+0x18); returns NULL.
MouseCommand* DecalTool::onMouseDown(const UIEvent&)
{
    releaseCapture();
    recordCameraHistory(getName().c_str(), workspace);
    return NULL;
}

// 00619c90 (INamed slot 0x18): MouseCommand::getSurface 00615f10; with a part, a decal, a surface and an unlocked part
// (PartInstance::locked +0x1f0) the decal is parented to the part (Instance::setParent 0055a8f0) and faced to the
// surface's NormalId (Surface +4) via FaceInstance::setFace 005ef770; otherwise the decal is unparented.
void DecalTool::onMouseMove(const UIEvent& event)
{
    PartInstance* part;
    int surfaceId;
    Surface* surface = getSurface(event, part, surfaceId);
    if (part && decal && surface && !part->getPartLocked())
    {
        decal->setParent(part);
        decal->setFace(surface->getNormalId());
    }
    else if (decal)
    {
        decal->setParent(NULL);
    }
}

// 00619d00 (INamed slot 0x10): Delete (0x7f) or Escape (0x1b) cancels the drag: releaseCapture (slot 0x28), the
// decal is unparented and NULL ends the command; any other key keeps this command.
MouseCommand* DecalTool::onKeyDown(const UIEvent& event)
{
    if (event.key == SDLK_DELETE || event.key == SDLK_ESCAPE)
    {
        releaseCapture();
        if (decal)
            decal->setParent(NULL);
        return NULL;
    }
    return this;
}
}
