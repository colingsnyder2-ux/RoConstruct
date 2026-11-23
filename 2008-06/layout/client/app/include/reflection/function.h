// =============================================================================
// function.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/reflection/function.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "reflection/member.h"
#include "reflection/type.h"
#include "util/Utilities.h"

namespace RBX
{
	namespace Reflection
	{
		class Function;
		class __declspec(novtable) FunctionDescriptor : public MemberDescriptor
		{
		public:
			enum Security
			{
				NeedTrustedCaller = 0,
				AnyCaller = 1
			};

		public:
			class __declspec(novtable) Arguments
			{
			public:
				Value returnValue;

			public:
				virtual size_t size() const = 0;
				virtual void get(int, Value&) const = 0;
			};

		public:
			typedef Function Describing;

		public:
			const Security security;

		protected:
			SignatureDescriptor signature;

		protected:
			FunctionDescriptor(ClassDescriptor& classDescriptor, const char* name, Security security);

		public:
			const SignatureDescriptor& getSignature() const { return signature; }
			virtual void execute(DescribedBase* instance, Arguments& arguments) const = 0;
		};

		class Function
		{
		protected:
			const FunctionDescriptor* descriptor;
			const DescribedBase* instance;

		public:
			Function(const Function&);
			Function(const FunctionDescriptor& descriptor, const DescribedBase* instance)
				: descriptor(&descriptor),
				  instance(instance)
			{
			}
			Function& operator=(const Function&);
			const Name& getName() const;
			const FunctionDescriptor* getDescriptor() const
			{
				return descriptor;
			}
			void execute(FunctionDescriptor::Arguments&) const;
		};

		template<typename Class>
		class FuncDesc : public FunctionDescriptor
		{
		protected:
			FuncDesc(const char* name, Security security)
				: FunctionDescriptor(Class::classDescriptor(), name, security)
			{
			}
		};
	}
}
