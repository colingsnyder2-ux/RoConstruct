// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "reflection/reflection.h"
#include "reflection/object.h"
#include <vector>
#include <algorithm>

// INFERRED: 0x0056b500 is the ClassDescriptor* ordering predicate used for derivedClasses (by name).
extern "C" bool fn_0056b500(const RBX::Reflection::ClassDescriptor* a, const RBX::Reflection::ClassDescriptor* b);
// INFERRED: 0x0056fef0 returns the global (call_once-guarded static) list of all class descriptors.
extern "C" std::vector<RBX::Reflection::ClassDescriptor*>& fn_0056fef0();

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
			boost::recursive_mutex::scoped_lock lock(sync());

			// sorted insertion into base's derived class list
			{
				std::vector<ClassDescriptor*>::iterator it =
					std::lower_bound(base.derivedClasses.begin(), base.derivedClasses.end(), this, fn_0056b500);
				base.derivedClasses.insert(it, this);
			}

			// INFERRED: sorted insertion into the global list of all classes, ordered by name
			std::vector<ClassDescriptor*>::iterator iter = fn_0056fef0().begin();
			while (iter != fn_0056fef0().end())
			{
				if (Name::compare(const_cast<Name&>(this->name), const_cast<Name&>((*iter)->name)) < 0)
					break;
				++iter;
			}
			fn_0056fef0().insert(iter, this);
		}
	}
}
