// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-function-pod-vtable
// Thread-name storage of RBX util/boost.cpp (2008-06 client): foo 00975c90, once_init_foo 00975c94, init_foo 00596d50.
// Flags: the previous default flags plus the boost-function-pod-vtable profile that FunctorInst_00596bd0.cpp proves for
// thread_specific_ptr<std::string>::thread_specific_ptr() 00596bd0 and function1<void, void*>(tss_adapter) 00596b30,
// which init_foo's static constructs here.
#include <string>
#include <boost/thread/once.hpp>
#include <boost/thread/tss.hpp>

namespace RBX { namespace boost_detail {
boost::thread_specific_ptr<std::string>* foo;
boost::once_flag once_init_foo = BOOST_ONCE_INIT;

void init_foo()
{
    static boost::thread_specific_ptr<std::string> value;
    foo = &value;
}
} }

namespace RBX
{
	// 00596e60 (registry placeholder func_00596e60): RBX::get_thread_name (declared by AppFramework.cpp,
	// AppDocumentStartup.cpp, MainLogManagerState.cpp; ThreadLogManager's constructor calls it, caller 0042a4f0).
	// Body: call_once(init_foo 00596d50, once_init_foo 00975c94), foo 00975c90 ->get() 005a7570, then name->c_str()
	// or the function-local static 00949c60 ("rbx_thread" 00832314). Shape: openrbx Client/App/util/boost.cpp
	// get_thread_name (threadName() inline helper; `static const char* none`), placed after set_thread_name 00596db0.
	const char* get_thread_name()
	{
		static const char* none = "rbx_thread";

		boost::call_once(&boost_detail::init_foo, boost_detail::once_init_foo);
		std::string* name = boost_detail::foo->get();
		return name ? name->c_str() : none;
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::function1<void,std::basic_string<char,std::char_traits<char>,std::allocator<char> > *,std::allocator<boost::function_base> >;
