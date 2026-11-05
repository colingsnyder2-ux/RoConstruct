// from server: 99% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs v8datamodel/GlobalSettings.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/GlobalSettings.h"

namespace RBX
{
	boost::shared_ptr<GlobalSettings> GlobalSettings::singleton()
	{
		boost::recursive_mutex::scoped_lock lock(mutex);

		static boost::shared_ptr<GlobalSettings> sing = Creatable::create<GlobalSettings>();

		return sing;
	}
}
