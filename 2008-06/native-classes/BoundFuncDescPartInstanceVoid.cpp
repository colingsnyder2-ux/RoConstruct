// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native Reflection::BoundFuncDesc<PartInstance, void(void), 0> explicit instance (inactive); flags and includes
// copied from BoundFuncDescTemplates2008.cpp, which already instantiates the PartInstance float(void) sibling.
// Identity: the constructor at 0059cee0 stores vftable 00832f58, whose RTTI complete-object locator 0089a9dc names
// .?AV?$BoundFuncDesc@VPartInstance@RBX@@$$A6AXXZ$0A@@Reflection@RBX@@ (the registry gives 0059cee0 and the float(void)
// constructor 0059cfd0, vftable 00832f64, the ModelInstance void(void) constructor name; registry proposal). It pushes
// Described<PartInstance>::classDescriptor (0059c7f0), FunctionDescriptor(ClassDescriptor&, const char*, Security)
// 00595790, keeps a 12-byte member-function pointer at +0x38..+0x40 and sets resultType = Type::singleton<void>()
// 00594a50 (+0x14), ret 0x14.
#include "v8datamodel/PartInstance.h"
#include "reflection/reflection.h"

using namespace RBX;
using namespace RBX::Reflection;

// 0059cee0 constructor (and the execute / call members of the same instance)
template class BoundFuncDesc<PartInstance, void(void), 0>;
