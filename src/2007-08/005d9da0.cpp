// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs v8datamodel/TimeState.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/TimeState.h"

namespace RBX
{
	TimeState::TimeState()
		: totalVirtualTime(0.0f)
	{
	}

	void TimeState::clear()
	{
		totalVirtualTime = 0.0f;
	}
}
