#pragma once

#include "tool/SurfaceTool.h"

namespace RBX {
extern char sFlatTool[];
class FlatTool : public Named<SurfaceTool, sFlatTool> {
    virtual const std::string getCursorName() const;
    virtual void applyToSurface(Surface*);
public:
    FlatTool(Workspace* workspace) : Named<SurfaceTool, sFlatTool>(workspace) {}
    virtual MouseCommand* isSticky() const;
};
typedef char FlatToolSize[sizeof(FlatTool) == 0x48 ? 1 : -1];
}
