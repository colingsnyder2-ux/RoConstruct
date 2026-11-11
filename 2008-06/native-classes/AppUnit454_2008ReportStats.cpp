// 2008-06 native ServiceProvider / Creatable template instances for Stats::StatsService in the CRobloxReportView unit
// (application range 00454000..00460000, inactive). Verified by tests/record_native_app_unit454_2008.py. All headers
// are read-only here.
//
// The rows lie in the COMDAT run of the CRobloxReportView unit (vtable 0081888c), whose setDataModel 00458700 calls
// dataModel->create<Stats::StatsService>():
//   * ServiceProvider::doGetClassIndex<StatsService>() 00455ea0 (91 B, `static size_t index = newIndex()`, newIndex
//     00572690) and callDoGetClassIndex<StatsService>() 00456400 (5 B, a tail jump);
//   * ServiceProvider::find<StatsService>() const 00457b60 (320 B): getClassIndex (call_once 00557330 on 00456400),
//     serviceArray (+0x190) resize / lookup, findServiceByClassName(className()) 00572a90, the serviceArray store;
//   * ServiceProvider::create<StatsService>() const 00458610 (228 B): find, else Creatable<Instance>::create, the
//     serviceArray store and setParent(this) 0055a8f0;
//   * Creatable<Instance>::create<StatsService>() 00458590 (120 B: malloc 0x130, StatsService() 00458520) and
//     shared_ptr<StatsService>(StatsService*, Creatable<Instance>::Deleter) 00456f10 (171 B).
// v8tree/Service.h and util/Object.h declare these templates without bodies; the definitions below are the ones
// AppUnit48C_2008Services.cpp uses.
// >>> native-status (generated) -- do not edit >>>
// AppUnit454_2008ReportStats | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 583c7fe6 | roc native-status --write
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "stats/Stats.h"

namespace RBX
{
	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::className() { return Name::declare<N>(); }

	template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
	template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
	template<class Class> size_t ServiceProvider::getClassIndex()
	{
		static boost::once_flag flag = BOOST_ONCE_INIT;
		boost::call_once(&callDoGetClassIndex<Class>, flag);
		return doGetClassIndex<Class>();
	}

	template<class Class> Class* ServiceProvider::find() const
	{
		size_t index = getClassIndex<Class>();
		Class* service;
		if (index + 1 > serviceArray.size())
		{
			serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
			service = NULL;
		}
		else
		{
			service = static_cast<Class*>(serviceArray[index].get());
			if (service != NULL)
				return service;
		}
		boost::shared_ptr<Instance> item = findServiceByClassName(Class::className());
		if (!item)
			return NULL;
		service = static_cast<Class*>(item.get());
		serviceArray[index] = item;
		return service;
	}

	template<class Class> Class* ServiceProvider::create() const
	{
		Class* service = find<Class>();
		if (service == NULL)
		{
			boost::shared_ptr<Class> value = Creatable<Instance>::create<Class>();
			service = value.get();
			size_t index = getClassIndex<Class>();
			serviceArray[index] = value;
			service->setParent(const_cast<ServiceProvider*>(this));
		}
		return service;
	}

	template Stats::StatsService* ServiceProvider::find<Stats::StatsService>() const;
	template Stats::StatsService* ServiceProvider::create<Stats::StatsService>() const;
}

// boost::shared_dynamic_cast<Stats::Item>(const shared_ptr<Instance>&) 00456ee0 (37 B) and the shared_ptr<Stats::Item>
// dynamic_cast_tag constructor 00456360 (142 B: __RTDynamicCast Instance 0092907c -> Stats::Item 009320f4, the
// shared_count copy, and the reset through shared_count::operator= 004025b0 when the cast fails); both callers of
// 00456ee0 are the report view's ChildAdded / ChildRemoved handlers 004582f0 / 004581a0 in this unit.
template boost::shared_ptr<RBX::Stats::Item> boost::shared_dynamic_cast<RBX::Stats::Item, RBX::Instance>(
	const boost::shared_ptr<RBX::Instance>&);

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::Stats::Item>;
template class boost::shared_ptr<RBX::Stats::StatsService>;
