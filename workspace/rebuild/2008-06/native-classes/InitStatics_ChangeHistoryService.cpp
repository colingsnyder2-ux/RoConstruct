// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 ChangeHistoryService reflection statics: dynamic initializers 007f3ff0, 007f4020, 007f4050, 007f4080
// (name strings, member functions and security 1 read from the initializers; constructors by RTTI).
// INFERRED: object names (not in the binary).
#include "v8datamodel/ChangeHistoryService.h"
#include "reflection/reflection.h"
namespace RBX {
	static Reflection::BoundFuncDesc<ChangeHistoryService, void(bool), 1> desc_SetEnabled(&ChangeHistoryService::setEnabled, "SetEnabled", "state", Reflection::FunctionDescriptor::AnyCaller);   // 00975a40
	static Reflection::BoundFuncDesc<ChangeHistoryService, void(std::string), 1> desc_SetWaypoint(&ChangeHistoryService::sub_0058c540, "SetWaypoint", "name", Reflection::FunctionDescriptor::AnyCaller);   // 009759f8
	static Reflection::BoundFuncDesc<ChangeHistoryService, void(), 0> desc_Redo(&ChangeHistoryService::play, "Redo", Reflection::FunctionDescriptor::AnyCaller);   // 00975b48
	static Reflection::BoundFuncDesc<ChangeHistoryService, void(), 0> desc_Undo(&ChangeHistoryService::unplay, "Undo", Reflection::FunctionDescriptor::AnyCaller);   // 00975ac8
}
