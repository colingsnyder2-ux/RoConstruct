// =============================================================================
// Visit.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/Visit.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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

namespace RBX { namespace Reflection {
	// N=2 ctor #1 (reflection.h declares it, no shared header defines it; same body as AppLeaves2008DHTMLWindow.cpp).
	template<typename Class, typename Function>
	BoundFuncDesc<Class, Function, 2>::BoundFuncDesc(
		typename BoundFuncDesc<Class, Function, 2>::FunctionSig function,
		const char* name, const char* arg1Name, const char* arg2Name, Security security)
		: FuncDesc<Class>(name, security), function(function), default1(), default2()
	{
		declareSignature(arg1Name, arg2Name);
	}
} }

// INFERRED: security value 4 is pushed by the initializers 007f5ba0 / 007f5bd0 / 007f5c00; function.h names only 0 and 1.
static RBX::Reflection::BoundFuncDesc<RBX::Visit, void(std::string), 1> UploadUrlFunction(
	&RBX::Visit::setUploadUrl,
	"SetUploadUrl",
	"url",
	(RBX::Reflection::FunctionDescriptor::Security)4);
static RBX::Reflection::BoundFuncDesc<RBX::Visit, std::string(void), 0> getUploadUrl(
	&RBX::Visit::getUploadUrl,
	"GetUploadUrl",
	(RBX::Reflection::FunctionDescriptor::Security)4);
static RBX::Reflection::BoundFuncDesc<RBX::Visit, void(std::string, int), 2> desc_setPing(
	&RBX::Visit::setPing,
	"SetPing",
	"pingUrl",
	"interval",
	(RBX::Reflection::FunctionDescriptor::Security)4);

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
