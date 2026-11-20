#pragma once

#include "tool/SurfaceTool.h"
#include "v8datamodel/Decal.h"

namespace RBX {
extern char sDecalTool[];

class DecalTool : public Named<SurfaceTool, sDecalTool> {
    boost::shared_ptr<Decal> decal;
protected:
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual MouseCommand* onKeyDown(const UIEvent&);
    virtual void onMouseMove(const UIEvent&);
    virtual const std::string getCursorName() const { return "ArrowCursorDecalDrag"; }  // 005a1ac0
public:
    virtual void applyToSurface(Surface*) {}
    DecalTool(Workspace* workspace, Decal* decal) : Named<SurfaceTool, sDecalTool>(workspace)
    {
        this->decal = shared_from(decal);
        capture();
    }
};
typedef char DecalToolSize[sizeof(DecalTool) == 0x50 ? 1 : -1];
}
