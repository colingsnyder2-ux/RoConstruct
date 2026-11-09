// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/reflection/signal.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/signal.h"

#include "reflection/object.h"

#include <cstddef>

namespace RBX {
namespace Reflection {

GenericSlotWrapper::~GenericSlotWrapper()
{
}

// FUNCTION: WEBSERVICE 0x10095790
SignalInstance::~SignalInstance()
{
}

// FUNCTION: WEBSERVICE 0x10095a50
SignalInstance* SignalDescriptor::findSignalInstance(const SignalSource* source) const
{
	if (source == NULL) {
		return NULL;
	}

	if (source->signals.get() == NULL) {
		return NULL;
	}

	SignalSource::SignalMap::const_iterator it = source->signals->find(this);

	if (it == source->signals->end()) {
		return NULL;
	}

	return it->second.get();
}

// FUNCTION: WEBSERVICE 0x10095b90
SignalDescriptor::SignalDescriptor(ClassDescriptor& classDescriptor, const char* name)
	: MemberDescriptor(classDescriptor, name, "Signals"), signalCreatedHook(NULL)
{
	classDescriptor.MemberDescriptorContainer<SignalDescriptor>::declare(this);
}

// STUB: WEBSERVICE 0x10095c50
boost::shared_ptr<SignalInstance> SignalDescriptor::getSignalInstance(SignalSource& source) const
{
	if (source.signals.get() == NULL) {
		source.signals.reset(new SignalSource::SignalMap());
	}

	SignalSource::SignalMap::iterator iter = source.signals->find(this);

	if (iter != source.signals->end()) {
		return iter->second;
	}

	boost::shared_ptr<SignalInstance> si(newSignalInstance(source));

	(*source.signals)[this] = si;

	if (signalCreatedHook != NULL) {
		signalCreatedHook(&source);
	}

	return si;
}

// STUB: WEBSERVICE 0x10095e80
SignalSource::~SignalSource()
{
}

// STUB: WEBSERVICE 0x10095ed0
void SignalSource::disconnect_all_slots()
{
	signals.reset();
}

} // namespace Reflection
} // namespace RBX
