#include <windows.h>
#include <string>
#include <exception>
#include "util/boost.hpp"
#include "util/standardout.h"

namespace RBX
{
	void set_thread_name(const char* name); // 00596db0 (ReflectionDescriptors.cpp)

	class ThreadPrioritySetter
	{
	private:
		const int old;
		bool success;

	public:
		ThreadPrioritySetter(int priority)
			: old(GetThreadPriority(GetCurrentThread())),
			  success(SetThreadPriority(GetCurrentThread(), priority) == TRUE)
		{
		}
		~ThreadPrioritySetter()
		{
			if (success)
				SetThreadPriority(GetCurrentThread(), old);
		}
	};

	// thread_function:". INFERRED: the 2008 signature adds the thread priority (ebp+0x28, after the by-value name);
	void run_in_background(const boost::function0<void>& threadfunc, std::string name, int priority)
	{
		try
		{
			set_thread_name(name.c_str());

			{
				ThreadPrioritySetter set(priority);
				threadfunc();
			}
		}
		catch (std::exception& ex)
		{
			StandardOut::singleton()->print(MESSAGE_ERROR, "Crashed via C++ exception in thread_function:", ex.what());
		}
	}
}

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

template class boost::function1<void,std::basic_string<char,std::char_traits<char>,std::allocator<char> > *,std::allocator<boost::function_base> >;
