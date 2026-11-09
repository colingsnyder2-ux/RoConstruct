// from server: 100% by colin
// roc-cl: 50727
// roc-lang: cpp
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll v8datamodel/SafeChat.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/SafeChat.h"

namespace RBX
{
	static void inlinedDelete(ChatOption* c)
	{
		delete c;
	}

	ChatOption::~ChatOption()
	{
		std::for_each(children.begin(), children.end(), &inlinedDelete);
	}
}
