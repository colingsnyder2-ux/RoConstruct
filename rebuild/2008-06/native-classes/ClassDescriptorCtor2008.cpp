// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 2008-06 native Reflection::ClassDescriptor(ClassDescriptor& base, const char* name) + operator==/!= (inactive).
// Linking the donor-free exe showed every classDescriptor<T>() reaching this constructor with no definition
// (work/donorfree-route/make_stubs.py, first stub hit at boot). Body follows the donor reflection_object.cpp shape;
// ROOT ctor 00570820 is in AppUnit570_2008Reflection.cpp. INFERRED: no address recorded yet for these three.
#include "reflection/reflection.h"
#include "reflection/object.h"

namespace RBX
{
	namespace Reflection
	{
		ClassDescriptor::ClassDescriptor(ClassDescriptor& base, const char* name)
			: Descriptor(name),
			  PropertyContainer(&base),
			  SignalContainer(&base),
			  FunctionContainer(&base),
			  derivedClasses(),
			  base(&base)
		{
			{
				boost::recursive_mutex::scoped_lock lock(sync());
				base.derivedClasses.push_back(this);
			}
		}

		bool ClassDescriptor::operator==(const ClassDescriptor& other) const
		{
			return this == &other;
		}

		bool ClassDescriptor::operator!=(const ClassDescriptor& other) const
		{
			return this != &other;
		}
	}
}
