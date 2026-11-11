#pragma once
// >>> native-status (generated) -- do not edit >>>
// FlatTool | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src c7579b94 | roc native-status --write

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
