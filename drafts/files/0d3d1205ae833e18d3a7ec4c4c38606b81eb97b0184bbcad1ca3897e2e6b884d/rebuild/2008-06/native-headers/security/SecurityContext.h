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

		public:
			// INFERRED access: public. The 2008 ScriptContext reads it directly after current() 00493760
			// (printidentity 005add30, resume 005ae0d0 and onHook 005adbf0: mov ecx,[eax]; cmp ecx,2).
			const Identities identity;

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
