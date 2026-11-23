// =============================================================================
// descriptor.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/reflection/descriptor.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
			}

			virtual ~Descriptor()
			{
			}
		};
	}
}
