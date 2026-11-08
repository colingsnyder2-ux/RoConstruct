#include "v8datamodel/ToolsPart.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "StandardVerbs.h"
namespace RBX {
template<> MouseCommand* TToolVerb<FillTool, RunStateVerb>::newMouseCommand() { return new FillTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<DropperTool, RunStateVerb>::newMouseCommand() { return new DropperTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<ModelSetPrimaryPartTool, RunStateVerb>::newMouseCommand() { return new ModelSetPrimaryPartTool(dataModel->getWorkspace()); }
void forceDestroy(FillTool* p) { delete p; }
void forceDestroy(DropperTool* p) { delete p; }
void forceDestroy(ModelSetPrimaryPartTool* p) { delete p; }
}
