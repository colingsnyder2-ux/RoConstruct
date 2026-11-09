// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll util/Debug.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Debug.h"
#include <typeinfo>

bool doCrash = true;

namespace RBX
{
	Debugable::AssertAction Debugable::assertAction = IgnoreAssert;

	void Debugable::dump(std::ostream& stream)
	{
		const std::type_info& type = typeid(*this);
		stream << type.name();
	}

	void Debugable::doCrash()
	{
		if (::doCrash)
			RBXCRASH();
	}
}
