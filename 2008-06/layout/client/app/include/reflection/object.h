// =============================================================================
// object.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/reflection/object.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <boost/shared_ptr.hpp>
#include <vector>
#include "reflection/descriptor.h"
#include "reflection/member.h"
#include "reflection/signal.h"
#include "reflection/property.h"
#include "reflection/function.h"
#include "util/Name.h"
#include "util/Object.h"

namespace RBX
{
	namespace Reflection
	{
		typedef MemberDescriptorContainer<PropertyDescriptor> PropertyContainer;
		typedef MemberDescriptorContainer<PropertyDescriptor>::Iterator PropertyIterator;
		typedef MemberDescriptorContainer<PropertyDescriptor>::ConstIterator ConstPropertyIterator;

		typedef MemberDescriptorContainer<FunctionDescriptor> FunctionContainer;
		typedef MemberDescriptorContainer<FunctionDescriptor>::ConstIterator FunctionIterator;

		typedef MemberDescriptorContainer<SignalDescriptor> SignalContainer;
		typedef MemberDescriptorContainer<SignalDescriptor>::Iterator SignalIterator;
		typedef MemberDescriptorContainer<SignalDescriptor>::ConstIterator ConstSignalIterator;

		class ClassDescriptor : public Descriptor,
								public MemberDescriptorContainer<PropertyDescriptor>,
								public MemberDescriptorContainer<SignalDescriptor>,
								public MemberDescriptorContainer<FunctionDescriptor>
		{
		private:
			std::vector<ClassDescriptor*> derivedClasses;
			ClassDescriptor* base;

		public:
			static bool lockedDown;

		public:
			ClassDescriptor(ClassDescriptor& base, const char* name);

		private:
			ClassDescriptor();

		public:
			const ClassDescriptor* getBase() const
			{
				return base;
			}
			bool isBaseOf(const char*) const;
			bool isBaseOf(const ClassDescriptor& base) const;
			bool isA(const char*) const;
			bool isA(const ClassDescriptor&) const;
			std::vector<ClassDescriptor*>::const_iterator derivedClasses_begin() const
			{
				return derivedClasses.begin();
			}
			std::vector<ClassDescriptor*>::const_iterator derivedClasses_end() const
			{
				return derivedClasses.end();
			}
			bool operator==(const ClassDescriptor& other) const;
			bool operator!=(const ClassDescriptor& other) const;

		public:
			static ClassDescriptor& rootDescriptor()
			{
				static ClassDescriptor root;
				return root;
			}
		};

		class __declspec(novtable) DescribedBase : public SignalSource
		{
		protected:
			const ClassDescriptor* descriptor;

		public:
			DescribedBase()
			{
				ClassDescriptor::lockedDown = true;
				descriptor = &ClassDescriptor::rootDescriptor();
			}

		public:
			const ClassDescriptor& getDescriptor() const
			{
				return *descriptor;
			}

			// TODO: find iterators don't fully match when inlined (see LuaInstanceBridge.cpp)
			ConstPropertyIterator findProperty(const Name& name) const
			{
				return getDescriptor().PropertyContainer::findConstMember(name, this);
			}
			PropertyIterator findProperty(const Name& name)
			{
				return getDescriptor().PropertyContainer::findMember(name, this);
			}
			PropertyIterator properties_begin()
			{
				return getDescriptor().PropertyContainer::members_begin(this);
			}
			ConstPropertyIterator properties_begin() const
			{
				return getDescriptor().PropertyContainer::members_begin(this);
			}
			PropertyIterator properties_end()
			{
				return getDescriptor().PropertyContainer::members_end(this);
			}
			ConstPropertyIterator properties_end() const
			{
				return getDescriptor().PropertyContainer::members_end(this);
			}

			FunctionIterator findFunction(const Name& name) const
			{
				return getDescriptor().FunctionContainer::findConstMember(name, this);
			}
			FunctionIterator functions_begin() const
			{
				return getDescriptor().FunctionContainer::members_begin(this);
			}
			FunctionIterator functions_end() const
			{
				return getDescriptor().FunctionContainer::members_end(this);
			}

			ConstSignalIterator findSignal(const Name& name) const
			{
				return getDescriptor().SignalContainer::findConstMember(name, this);
			}
			SignalIterator findSignal(const Name& name)
			{
				return getDescriptor().SignalContainer::findMember(name, this);
			}
			SignalIterator signals_begin()
			{
				return getDescriptor().SignalContainer::members_begin(this);
			}
			ConstSignalIterator signals_begin() const
			{
				return getDescriptor().SignalContainer::members_begin(this);
			}
			SignalIterator signals_end()
			{
				return getDescriptor().SignalContainer::members_end(this);
			}
			ConstSignalIterator signals_end() const
			{
				return getDescriptor().SignalContainer::members_end(this);
			}

		public:
			static ClassDescriptor& classDescriptor()
			{
				return ClassDescriptor::rootDescriptor();
			}
		};
	}
}
