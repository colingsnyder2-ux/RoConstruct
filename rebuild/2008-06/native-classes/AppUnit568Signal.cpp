// 2008-06 native rows of the reflection/signal.cpp translation unit 0056a590..0056bd8f of the application range
// 00568000..0056c000 (inactive). Verified by tests/record_native_app_unit568.py; the unit map is in its receipt.
//
// The unit defines the SignalDescriptor / Signal / SignalSource members (evidence names):
//   SignalDescriptor(ClassDescriptor&, const char*) 0056bab0 (MemberDescriptor 0056b480 with category "Signals"
//   0082f624, SignatureDescriptor() 00594bf0, MemberDescriptorContainer<SignalDescriptor>::declare 0056b700 on the
//   container at ClassDescriptor+0x3c), findSignalInstance 0056b620, getSignalInstance 0056bb20,
//   Signal::getSignalInstance 0056bd10, ~SignalSource 0056bd40 and disconnect_all_slots 0056bd60.
// It is also the first unit to emit the header-inline MemberDescriptor(ClassDescriptor&, const char*, const char*)
// 0056b480 and MemberDescriptorContainer<SignalDescriptor>::compare 0056b500 (identical-code folded: the same body
// is pushed by the property / class containers 0056c1cc, 0057004c, 005709fa). The boost::signals named_slot_map /
// signal_base instances 0056a590..0056b480 are library code and are not recovered.
// Headers are read-only here (reflection/signal.h, reflection/object.h).
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
