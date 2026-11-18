#include "v8datamodel/DebrisService.h"
#include "v8datamodel/TimerService.h"
#include "util/standardout.h"
#include <boost/bind.hpp>

namespace RBX
{
	char sDebrisService[] = "Debris"; // 009611f0 (.data; doDeclare 005bfe20, classDescriptor 005c06a0)

	// Template members the shared headers only declare (same definitions as TimerService.cpp).
	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	template<typename Arg0Type>
	DescribedCreatable<C, D, N>::DescribedCreatable(Arg0Type arg0)   // 0063bdb0
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >(arg0) {}
}

using namespace RBX;

static Reflection::PropDescriptor<DebrisService, int> prop_MaxItems("MaxItems", "Data", &DebrisService::getMaxItems, &DebrisService::setMaxItems, Reflection::PropertyDescriptor::STANDARD);
static Reflection::BoundFuncDesc<DebrisService, void(boost::shared_ptr<Instance>, double), 2> func_AddItem(&DebrisService::addItem, "AddItem", "item", "lifetime", 10.0, Reflection::FunctionDescriptor::NeedTrustedCaller);

static void cleanup(boost::weak_ptr<Instance> item)
{
	try
	{
		boost::shared_ptr<Instance> i = item.lock();
		if (i)
			i->setParent(NULL);
	}
	catch (std::exception& e)
	{
		StandardOut::singleton()->print(MESSAGE_WARNING, e);
	}
}

namespace RBX
{
	DebrisService::DebrisService()
		: Base(static_cast<const char*>(sDebrisService)),
		  maxItems(300),
		  timer(NULL)
	{
	}

	void DebrisService::setMaxItems(int value)
	{
		if (value != maxItems)
		{
			if (value < 0)
				throw std::runtime_error("DebrisService MaxItems must be greater than 0");

			maxItems = value;
			raisePropertyChanged(prop_MaxItems);
			DebrisService::cleanup();
		}
	}

	void DebrisService::addItem(boost::shared_ptr<Instance> item, double lifetime)
	{
		if (timer)
			timer->delay(boost::bind(&::cleanup, item), lifetime);

		queue.push(item);
		DebrisService::cleanup();
	}

	void DebrisService::cleanup()
	{
		while ((int)queue.size() > maxItems)
		{
			::cleanup(queue.front());
			queue.pop();
		}
	}

	void DebrisService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		while ((int)queue.size() > 0)
		{
			::cleanup(queue.front());
			queue.pop();
		}

		timer = ServiceProvider::create<TimerService>(newProvider);
	}
}

template class boost::_bi::list1<boost::_bi::value<boost::shared_ptr<RBX::Instance> > >;
template class boost::_bi::value<boost::shared_ptr<RBX::Instance> >;
template class std::_Container_base_aux_alloc_real<std::allocator<boost::weak_ptr<RBX::Instance> > >;
template class std::_Deque_const_iterator<boost::weak_ptr<RBX::Instance>,std::allocator<boost::weak_ptr<RBX::Instance> >,1>;
template class std::_Deque_iterator<boost::weak_ptr<RBX::Instance>,std::allocator<boost::weak_ptr<RBX::Instance> >,1>;
template class std::deque<boost::weak_ptr<RBX::Instance>,std::allocator<boost::weak_ptr<RBX::Instance> > >;

template void RBX::Name::callDoDeclare<RBX::sDebrisService>();
