// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2008-06 util/boost.cpp: RBX::ThreadPrioritySetter (a class local to boost.cpp in the donor rbxgs util/boost.cpp) and
// its only user run_in_background 00596ea0 (inactive). The other util/boost.cpp bodies (SetThreadName 00595a80,
// worker_thread, set_thread_name 00596db0) live in ReflectionDescriptors.cpp (another owner); flags line copied from it.
// ??1ThreadPrioritySetter 00595ae0 is out of line only for the EH unwind funclet 007d2319 (lea ecx,[ebp-0x1c]; jmp),
// run_in_background inlines it on the normal path (00596f17..00596f21), so it needs this parent in the same unit.
#include <windows.h>
#include <string>
#include <exception>
#include "util/boost.hpp"
#include "util/standardout.h"

namespace RBX
{
	void set_thread_name(const char* name); // 00596db0 (ReflectionDescriptors.cpp)

	// Donor rbxgs util/boost.cpp shape: old priority +0x0, success flag +0x4 (00596ef6 / 00596f07).
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
		// 00595ae0 ??1ThreadPrioritySetter@RBX@@QAE@XZ (registry)
		~ThreadPrioritySetter()
		{
			if (success)
				SetThreadPriority(GetCurrentThread(), old);
		}
	};

	// 00596ea0: identity from its neighbours (set_thread_name 00596db0, background_function 00597110 binds it), the
	// GetThreadPriority / SetThreadPriority pair and the catch string 00832320 "Crashed via C++ exception in
	// thread_function:". INFERRED: the 2008 signature adds the thread priority (ebp+0x28, after the by-value name);
	// ReflectionDescriptors.cpp declares the matching background_function(threadfunc, name, priority).
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
