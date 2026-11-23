// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native Instance "IsAncestorOf" / "IsDescendantOf" descriptors (inactive). Identity: the static initializers
// 007f2a30 (this 00973d70, "IsAncestorOf" 0082d9b0, "descendent" 0082d9c0) and 007f2a00 (this 00973df8,
// "IsDescendantOf" 0082d994, "ancestor" 0082d9a4) pass 00557640 / 00557890 with a zero adjustor to the
// BoundFuncDesc<Instance, bool(shared_ptr<Instance>), 1> constructor 0055a260; the bodies are the openrbx 2007
// v8tree/Instance.h inline wrappers isAncestorOf2 / isDescendentOf2 (one level of the inline recursive
// isAncestorOf / isDescendentOf, then the out-of-line copies 004c9c50 / 00422ae0).
#include "v8tree/Instance.h"
#include "reflection/reflection.h"

namespace RBX
{
#ifdef INSTANCE_HEADER_DECLARES_TREE_QUERY_WRAPPERS
	// Pending: core v8tree/Instance.h declares isDescendentOf out of line only and has no isAncestorOf,
	// isAncestorOf2 or isDescendentOf2 (proposal: the openrbx inline bodies). Measured once against a scratch copy of
	// Instance.h with those four inline members (batch 43): isDescendentOf2 is byte-identical to 00557890 (144 B) and
	// isAncestorOf2 to the first 144 B of 00557640, whose registry size 151 swallows the next function 005576d0
	// (mov dword ptr [ecx], 0x82d6b0; ret).
	static Reflection::BoundFuncDesc<Instance, bool(boost::shared_ptr<Instance>), 1> func_isDescendentOf(
		&Instance::isDescendentOf2, "IsDescendantOf", "ancestor", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<Instance, bool(boost::shared_ptr<Instance>), 1> func_isAncestorOf(
		&Instance::isAncestorOf2, "IsAncestorOf", "descendent", Reflection::FunctionDescriptor::AnyCaller);
#endif
}
