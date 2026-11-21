// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 2008-06 native RBX::Reflection::EnumDescriptor registry members (flags copied from EnumDescriptorLifetime.cpp, the
// sibling unit holding ~EnumDescriptor 0056c080). The core reflection/enumconverter.h declares the constructor and
// the two private static registries out of line; none of them had a native body.
// Identity: registry ??0EnumDescriptor@Reflection@RBX@@IAE@PBDABVtype_info@@@Z (0056c590);
// ?allEnums@EnumDescriptor@Reflection@RBX@@CAAAV?$vector@PBVEnumDescriptor@... (0056bf90). 0056c520 carries the
// COMDAT-folded registry name ?dictionary@Name@RBX@@ but it is the map accessor the constructor calls before
// map<const Name*, const EnumDescriptor*>::operator[] 005644a0 (static at 00974b34, guard 00974b54).
#include "reflection/enumconverter.h"
#include <map>

namespace RBX
{
	namespace Reflection
	{
		// 0056bf90: function-local static vector 00974b18 (guard 00974b30, vector ctor 004293d0, atexit 007fd1c0).
		std::vector<const EnumDescriptor*>& EnumDescriptor::allEnums()
		{
			static std::vector<const EnumDescriptor*> enums;
			return enums;
		}

		// 0056c520: function-local static map 00974b34 (guard 00974b54, _Tree ctor 00446110, atexit 007fd200).
		std::map<const Name*, const EnumDescriptor*>& EnumDescriptor::allEnumsByName()
		{
			static std::map<const Name*, const EnumDescriptor*> enums;
			return enums;
		}

		// 0056c590 (`ret 8`): Type(typeName, type, "token" 0082f650) 004897a0, vtable 0082f648, allItems / enumCount /
		// enumCountMSB zeroed, then allEnums().push_back (004213a0) and allEnumsByName()[&name] = this (005644a0).
		EnumDescriptor::EnumDescriptor(const char* typeName, const type_info& type)
			: Type(typeName, type, "token"),
			  allItems(),
			  enumCount(0),
			  enumCountMSB(0)
		{
			allEnums().push_back(this);
			allEnumsByName()[&name] = this;
		}
	}
}
