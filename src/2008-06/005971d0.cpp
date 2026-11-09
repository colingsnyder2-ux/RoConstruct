// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_unit_bd7bc73f4a540e0e.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/boost.hpp", "roc_unit_778baff4773a3157.cpp")
#include "util/boost.hpp"
#include "util/standardout.h"
#include "util/Debug.h"
#include <boost/bind.hpp>
#include <windows.h>
#include <boost/thread/tss.hpp>
#include <boost/thread/once.hpp>

namespace RBX {
	worker_thread::worker_thread(const boost::function0<enum work_result>& work_function, const char* name)
		: _data(new data()),
		  thread(background_function(boost::bind(&threadProc, _data, work_function), name))
	{
	}

}
