// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Donor-derived TU (rbxgs v8datamodel/GlobalSettings.cpp) on the native headers with the 2008 compiler; exact functions verified by
// check_native_class.py (inactive range evidence, not identity/layout gated).
#include "v8datamodel/GlobalSettings.h"

namespace RBX
{
	char sGlobalSettings[] = "GlobalSettings";

	boost::recursive_mutex GlobalSettings::mutex;

	boost::shared_ptr<GlobalSettings> GlobalSettings::singleton()
	{
		boost::recursive_mutex::scoped_lock lock(mutex);

		static boost::shared_ptr<GlobalSettings> sing = Creatable::create<GlobalSettings>();
		return sing;
	}
}
