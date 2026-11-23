// =============================================================================
// SecurityContext.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/security/SecurityContext.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <boost/thread/tss.hpp>
#include <G3D/format.h>

namespace RBX
{
	namespace Security
	{
		enum Identities
		{
			Anonymous,
			LocalGUI,
			GameScript,
			CmdLine,
			TrustedCOM,
			TrustedWebService,
			Replicator
		};

		enum Permissions
		{
			None,
			Administrator
		};

		class Context
		{
			friend class Impersonator;

		private:
			const Identities identity;
		public:
			void requirePermission(Permissions permission, const char* operation) const
			{
				if (!isInRole(identity, permission))
				{
					if (operation)
						throw std::runtime_error(G3D::format("The current security context cannot %s", operation));
					else
						throw std::runtime_error(G3D::format("The current security context cannot perform the requested operation"));
				}
			}

			bool hasPermission(Permissions permission)
			{
				return isInRole(identity, permission);
			}
		private:
			Context(Identities identity)
				: identity(identity)
			{
			}

		public:
			static Context& current()
			{
				Context* context = ptr().get();
				if (!context)
				{
					context = new Context(Anonymous);
					ptr().reset(context);
				}

				return *context;
			}
			static __declspec(noinline) bool isInRole(Identities identity, Permissions permission);
		private:
			static boost::thread_specific_ptr<Context>& ptr()
			{
				static boost::thread_specific_ptr<Context> value;
				return value;
			}
		};

		class Impersonator
		{
		private:
			Context* previous;
		public:
			Impersonator(Identities identity)
			{
				Context* newContext = new Context(identity);
				previous = Context::ptr().release();
				Context::ptr().reset(newContext);
			}

			~Impersonator()
			{
				Context::ptr().reset(previous);
			}
		};
	}
}
