// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// RBX::prop_className, the read-only "className" property of Instance (v8tree/Instance.cpp statics). Flags line copied
// from the Instance sibling PropDescriptorInstanceStringCtor.cpp.
// Identity: registry ??__Eprop_className@RBX@@YAXXZ 007f2a60, dynamic initializer of data 00973d18, the descriptor
// just before Instance::propParent 00973d34 (initializer 007f2ad0, InstanceParentDescriptor.cpp). The initializer
// passes "className" 0082d9cc, "Data" 00822490, getter Instance::getClassNameStr 0041f2b0, setter 0 and
// functionality 1 (UI) to the get-only PropDescriptor<Instance, std::string> constructor 005597d0, then registers
// atexit 007fc900 (the descriptor's destructor thunk, COMDAT-folded with prop_SkyRt's).
#include "v8tree/Instance.h"

namespace RBX
{
	// 007f2a60 (dynamic initializer)
	static const Reflection::PropDescriptor<Instance, std::string> prop_className("className", "Data", &Instance::getClassNameStr, NULL, Reflection::PropertyDescriptor::UI);
}
