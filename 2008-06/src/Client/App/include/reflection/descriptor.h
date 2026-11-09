#pragma once
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
				RBXASSERT(!this->name.empty());
			}

			virtual ~Descriptor() 
			{
			}
		};
	}
}
