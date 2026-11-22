// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 DataModel "get" / "GetObjects" function descriptors of the v8datamodel/DataModel.cpp object (inactive).
// Flags copied from 007f3530_httpgetinit.cpp (the HttpGet descriptor of the same object; 007f3530 follows these two).
//
// 007f3470 ??__EgetContentFunctionOld@RBX@@YAXXZ (43 B) and 007f34a0 ??__EgetContentFunction@RBX@@YAXXZ (43 B):
//   push 1 (AnyCaller) / push "url" 0080f08c / push "get" 00830448 (resp. "GetObjects" 0083044c) / push 0, push 00579f70
//   (8-byte member pointer: DataModel has multiple bases) / mov ecx, 009750c8 (resp. 00974f38) / call 00578fa0
//   (BoundFuncDesc<DataModel, shared_ptr<const Instances>(ContentId), 1> ctor; vtable 0083005c per
//   BoundFuncDescRecovery_00559cb0.cpp; the registry names the COMDAT-folded body after Lighting) /
//   atexit(007fd550 resp. 007fd4c0).
// Donor tools/rbxgs/Client/App/v8datamodel/DataModel.cpp lines 19-20 declare both statics with &DataModel::get,
// "url" and FunctionDescriptor::AnyCaller; 00579f70 is DataModel::get(ContentId) (donor DataModel.h line 69).
//
// BLOCKED: the core native v8datamodel/DataModel.h does not declare DataModel::get (proposal, after save):
//   boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > get(ContentId contentId); // 00579f70
// Measured against a scratch DataModel.h with only that line added: 007f3470, 007f34a0, their atexit thunks
// 007fd4c0 / 007fd550 and the 00578fa0 constructor are exact.
// Define DATAMODEL_HEADER_DECLARES_GET (or drop the guard) once the core header declares it.
#ifdef DATAMODEL_HEADER_DECLARES_GET
#include "v8datamodel/DataModel.h"
#include "util/ContentProvider.h"
#include "reflection/reflection.h"

namespace RBX {
	// 007f3470
	static Reflection::BoundFuncDesc<DataModel, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >(ContentId), 1> getContentFunctionOld(&DataModel::get, "get", "url", Reflection::FunctionDescriptor::AnyCaller);
	// 007f34a0
	static Reflection::BoundFuncDesc<DataModel, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >(ContentId), 1> getContentFunction(&DataModel::get, "GetObjects", "url", Reflection::FunctionDescriptor::AnyCaller);
}
#endif
