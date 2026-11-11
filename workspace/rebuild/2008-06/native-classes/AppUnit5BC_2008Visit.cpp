// 2008-06 native RBX::Visit unit rows (v8datamodel/Visit.cpp, 005c4400..005c52ff of the application range
// 005bc000..005c8000), inactive. Verified by tests/record_native_app_unit5bc_2008.py against the committed read-only
// native v8datamodel/Visit.h (sizeof 0x150: uploadUrl +0x130, pingThread +0x14c, read from the constructor 005c5220,
// the destructor 005c4790 and setPing 005c4bb0).
// Evidence:
//   * dynamic initializers 007f5ba0 (SetUploadUrl, "url"), 007f5bd0 (GetUploadUrl) and the SetPing descriptor
//     ("pingUrl", "interval"), BoundFuncDesc vtables 00838ed0 / 00838edc / 00838ee8;
//   * Visit() 005c5220: DescribedCreatable<Visit>() 005c4d10, uploadUrl("NoVisit") (literal 00817f00), pingThread = 0,
//     setName("Visit");
//   * setPing 005c4bb0: url != "" (operator!= import 008023cc), new worker_thread(boost::bind(&Visit::ping, url, interval),
//     "rbx_visit") (0x14 bytes, ctor 005971d0), else pingThread.reset().
// >>> native-status (generated) -- do not edit >>>
// AppUnit5BC_2008Visit | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 8e752ad7 | roc native-status --write
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
			// 005c4692: the 2008 handler is an empty catch(...) that resumes at 005c464b (no failure message)
		}

		boost::xtime xt;
		boost::xtime_get(&xt, boost::TIME_UTC);

		xt.sec += interval;

		boost::thread::sleep(xt);

		return worker_thread::more;
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Reflection::BoundFuncDesc<RBX::Visit,void __cdecl(std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int),2>;
template class boost::function0<enum RBX::worker_thread::work_result,std::allocator<boost::function_base> >;
template class boost::scoped_ptr<RBX::worker_thread>;
