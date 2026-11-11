// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// SurfaceToolFactories | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 7e096f69 | roc native-status --write
#undef _RELEASEASSERT
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/SurfaceTools.h"
#include "StandardVerbs.h"

namespace RBX {
#define RBX_SURFACE_FACTORY(T) \
template<> MouseCommand* TToolVerb<T, RunStateVerb>::newMouseCommand() { return new T(dataModel->getWorkspace()); } \
template<> const Name& Named<SurfaceTool, s##T>::getName() const { return NativeToolName<T>::get(); }
RBX_SURFACE_FACTORY(GlueTool)
RBX_SURFACE_FACTORY(WeldTool)
RBX_SURFACE_FACTORY(StudsTool)
RBX_SURFACE_FACTORY(InletTool)
RBX_SURFACE_FACTORY(HingeTool)
RBX_SURFACE_FACTORY(RightMotorTool)
RBX_SURFACE_FACTORY(LeftMotorTool)
RBX_SURFACE_FACTORY(OscillateMotorTool)
#undef RBX_SURFACE_FACTORY
}
