// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-client-dll App/v8datamodel/DebrisService.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/DebrisService.h"

#include "reflection/property.h"
#include "reflection/reflection.h"
#include "util/standardout.h"
#include "v8datamodel/TimerService.h"

#include <boost/bind.hpp>
#include <stdexcept>

namespace RBX {

char sDebrisService[] = "Debris";

static Reflection::PropDescriptor<DebrisService, int> prop_MaxItems(
	"MaxItems", "Data", &DebrisService::getMaxItems, &DebrisService::setMaxItems
);

static Reflection::BoundFuncDesc<DebrisService, void(boost::shared_ptr<Instance>, double), 2> func_AddItem(
	&DebrisService::addItem, "AddItem", "item", "lifetime", 10.0, Reflection::FunctionDescriptor::AnyCaller
);

// FUNCTION: WEBSERVICE 0x100fa130
// FUNCTION: ROBLOX 0x006370d0
static void cleanup(boost::weak_ptr<Instance> item)
{
	try {
		boost::shared_ptr<Instance> i = item.lock();
		if (i) {
			i->setParent(NULL);
		}
	}
	catch (std::exception& e) {
		StandardOut::singleton()->print(MESSAGE_WARNING, e);
	}
}

// FUNCTION: WEBSERVICE 0x100fa780
// FUNCTION: ROBLOX 0x006376c0
void DebrisService::cleanup()
{
	while ((int) queue.size() > maxItems) {
		RBX::cleanup(queue.front());
		queue.pop();
	}
}

// FUNCTION: WEBSERVICE 0x100fae30
// FUNCTION: ROBLOX 0x00637d60
DebrisService::DebrisService()
	: DescribedCreatable<DebrisService, Instance, sDebrisService>(sDebrisService), maxItems(300), timer(NULL)
{
}

// FUNCTION: WEBSERVICE 0x100fb270
// FUNCTION: ROBLOX 0x006381a0
void DebrisService::addItem(boost::shared_ptr<Instance> item, double lifetime)
{
	if (timer) {
		timer->delay(boost::bind(&RBX::cleanup, item), lifetime);
	}

	queue.push(item);
	cleanup();
}

// FUNCTION: WEBSERVICE 0x100fb3a0
// FUNCTION: ROBLOX 0x006382d0
void DebrisService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	while ((int) queue.size() > 0) {
		RBX::cleanup(queue.front());
		queue.pop();
	}

	DescribedCreatable<DebrisService, Instance, sDebrisService>::onServiceProvider(oldProvider, newProvider);

	timer = newProvider ? newProvider->create<TimerService>() : NULL;
}

// FUNCTION: WEBSERVICE 0x100fb4f0
// FUNCTION: ROBLOX 0x00638420
void DebrisService::setMaxItems(int value)
{
	if (value != maxItems) {
		if (value < 0) {
			throw std::runtime_error("DebrisService MaxItems must be greater than 0");
		}

		maxItems = value;
		raisePropertyChanged(prop_MaxItems);
		cleanup();
	}
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::DebrisService, RBX::Instance, RBX::sDebrisService>;
template class RBX::Reflection::Described<
	RBX::DebrisService,
	RBX::sDebrisService,
	RBX::FactoryProduct<RBX::DebrisService, RBX::Instance, RBX::sDebrisService> >;
template class RBX::DescribedCreatable<RBX::DebrisService, RBX::Instance, RBX::sDebrisService>;
