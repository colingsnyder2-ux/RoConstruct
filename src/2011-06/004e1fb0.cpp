// from server: 59% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs util/boost.cpp

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

	void run_in_background(const boost::function0<void>& threadfunc, std::string name)
	{
		try
		{
			set_thread_name(name.c_str());

			{
				ThreadPrioritySetter set(THREAD_PRIORITY_BELOW_NORMAL);
				threadfunc();
			}
		}
		catch (std::exception& ex)
		{
			StandardOut::singleton()->print(MESSAGE_ERROR, "Crashed via C++ exception in run_in_background:", ex.what());
			RBXASSERT(false);
		}
	}

	boost::function0<void> background_function(const boost::function0<void>& threadfunc, const char* name)
	{
		return boost::bind(&run_in_background, threadfunc, std::string(name));
	}

	worker_thread::worker_thread(const boost::function0<enum work_result>& work_function, const char* name)
		: _data(new data()),
		  thread(background_function(boost::bind(&threadProc, _data, work_function), name))
	{
	}

	worker_thread::~worker_thread()
	{
		boost::mutex::scoped_lock scoped_lock(_data->sync);
		_data->endRequest = true;
		_data->wakeCondition.notify_all();
	}

	void worker_thread::join()
	{
		{
			boost::mutex::scoped_lock scoped_lock(_data->sync);
			_data->endRequest = true;
			_data->wakeCondition.notify_all();
		}

		thread.join();
	}

	void worker_thread::wake()
	{
		boost::mutex::scoped_lock scoped_lock(_data->sync);
		_data->wakeCondition.notify_all();
	}

	void worker_thread::threadProc(boost::shared_ptr<data> data, const boost::function0<enum work_result>& work_function)
	{
		while (!data->endRequest)
		{
			if (work_function() != more)
			{
				boost::mutex::scoped_lock scoped_lock(data->sync);
				data->wakeCondition.wait(scoped_lock);	
			}
		}
	}
}
