// =============================================================================
// signal.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/reflection/signal.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "reflection/signal.h"
#include "reflection/object.h"
namespace RBX
{
	namespace Reflection
	{
		SignalDescriptor::SignalDescriptor(ClassDescriptor& classDescriptor, const char* name)
			: MemberDescriptor(classDescriptor, name, "Signals"),
			  signalCreatedHook(NULL),
			  signature()
		{
			classDescriptor.SignalContainer::declare(this);
		}

		SignalInstance* SignalDescriptor::findSignalInstance(const SignalSource* source) const
		{
			if (!source)
				return NULL;
			if (!source->signals)
				return NULL;
			std::map<const SignalDescriptor*, boost::shared_ptr<SignalInstance> >::const_iterator iter = source->signals->find(this);
			if (iter == source->signals->end())
				return NULL;
			return iter->second.get();
		}

		boost::shared_ptr<SignalInstance> SignalDescriptor::getSignalInstance(SignalSource& source) const
		{
			if (!source.signals)
			{
				source.signals.reset(new std::map<const SignalDescriptor*, boost::shared_ptr<SignalInstance> >);
			}
			else
			{
				std::map<const SignalDescriptor*, boost::shared_ptr<SignalInstance> >::iterator iter = source.signals->find(this);
				if (iter != source.signals->end())
					return iter->second;
			}
			boost::shared_ptr<SignalInstance> signalInstance(newSignalInstance(source));
			(*source.signals)[this] = signalInstance;
			if (signalCreatedHook)
				signalCreatedHook(&source);
			return signalInstance;
		}

		boost::shared_ptr<SignalInstance> Signal::getSignalInstance() const
		{
			return descriptor->getSignalInstance(*instance);
		}

		SignalInstance::~SignalInstance() {}

		SignalSource::~SignalSource() {}

		void SignalSource::disconnect_all_slots()
		{
			signals.reset();
		}
	}
}
