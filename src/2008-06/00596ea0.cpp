// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_a7ba09e28ae2b551.cpp

// Candidate translation unit (score above; library headers required).
#include "util/boost.hpp"
#include "util/standardout.h"
#include "util/Debug.h"
#include <boost/bind.hpp>
#include <windows.h>
#include <boost/thread/tss.hpp>
#include <boost/thread/once.hpp>

namespace RBX
{
	namespace boost_detail
	{
		boost::thread_specific_ptr<std::string>* foo;
		
		boost::once_flag once_init_foo = BOOST_ONCE_INIT;
		void init_foo()
		{
			static boost::thread_specific_ptr<std::string> value;
			foo = &value;
		}

		void set_foo(std::string* value)
		{
			boost::call_once(&boost_detail::init_foo, boost_detail::once_init_foo);
			boost_detail::foo->reset(value);
		}
	}

	// Thread name stuff based on https://docs.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-2008/xcb2z8hs(v=vs.90)
	static bool nameThreads = true;

	typedef struct tagTHREADNAME_INFO
	{
		DWORD dwType;
		LPCSTR szName;
		DWORD dwThreadID;
		DWORD dwFlags;
	} THREADNAME_INFO;

	void SetThreadName(DWORD dwThreadID, LPCSTR szThreadName)
	{
		THREADNAME_INFO info;
		info.dwType = 0x1000;
		info.szName = szThreadName;
		info.dwThreadID = dwThreadID;
		info.dwFlags = 0;

		__try
		{
			if (nameThreads)
				RaiseException(0x406D1388, 0, sizeof(info)/sizeof(ULONG_PTR), (ULONG_PTR*)&info);
		}
		__except (EXCEPTION_CONTINUE_EXECUTION)
		{
		}
	}

	void set_thread_name(const char* name)
	{
		boost_detail::set_foo(new std::string(name));
		SetThreadName(GetCurrentThreadId(), name);
	}

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
