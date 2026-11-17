#include "v8datamodel/Visit.h"
#include "util/Http.h"
#include <boost/thread.hpp>

namespace RBX
{
	// Template members the shared headers only declare (same definitions as ClickDetector.cpp / Team.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}
}

static RBX::Reflection::BoundFuncDesc<RBX::Visit, void(std::string), 1> UploadUrlFunction(&RBX::Visit::setUploadUrl, "SetUploadUrl", "url", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
static RBX::Reflection::BoundFuncDesc<RBX::Visit, std::string(void), 0> getUploadUrl(&RBX::Visit::getUploadUrl, "GetUploadUrl", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
static RBX::Reflection::BoundFuncDesc<RBX::Visit, void(std::string, int), 2> desc_setPing(&RBX::Visit::setPing, "SetPing", "pingUrl", "interval", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);

namespace RBX
{
	Visit::Visit()
		: uploadUrl("NoVisit")
	{
		setName("Visit");
	}

	Visit::~Visit() {}

	void Visit::setPing(std::string url, int interval)
	{
		if (url != "")
		{
			pingThread.reset(new worker_thread(boost::bind(&Visit::ping, url, interval), "rbx_visit"));
		}
		else
		{
			pingThread.reset();
		}
	}

	worker_thread::work_result Visit::ping(std::string url, int interval)
	{
		try
		{
			std::string message;
			Http(url).get(message);
		}
		catch (...)
		{
		}

		boost::xtime xt;
		boost::xtime_get(&xt, boost::TIME_UTC);

		xt.sec += interval;

		boost::thread::sleep(xt);

		return worker_thread::more;
	}
}

template class RBX::Reflection::BoundFuncDesc<RBX::Visit,void __cdecl(std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int),2>;
template class boost::function0<enum RBX::worker_thread::work_result,std::allocator<boost::function_base> >;
template class boost::scoped_ptr<RBX::worker_thread>;
