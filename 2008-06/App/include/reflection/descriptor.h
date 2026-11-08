// 2008-06 override of Source/App/include/reflection/descriptor.h: the 2008 Descriptor(const char*)
// constructor has no RBXASSERT (inlined copies in Type 004897a0 and EnumDesc::addPair 0064d530 are
// just the vtable store and Name::declare(name, -1)).
#pragma once
// >>> native-status (generated) -- do not edit >>>
// descriptor | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src d2516c9b | roc native-status --write
#include <boost/noncopyable.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include "util/Name.h"
#include "util/Debug.h"

namespace RBX
{
	namespace Reflection
	{
		// There are two different copies of this function due to it being static.
		// They appear in both the reflection_function and reflection_object object files.
		static boost::recursive_mutex& sync()
		{
			static boost::recursive_mutex s;
			return s;
		}

		class Descriptor : public boost::noncopyable
		{
		public:
			const Name& name;
	  
		public:
			Descriptor(const Name&);

			Descriptor(const char* name)
				: name(Name::declare(name, -1))
			{
			}

			virtual ~Descriptor() 
			{
			}
		};
	}
}
