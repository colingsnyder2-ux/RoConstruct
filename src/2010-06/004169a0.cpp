// from server: 41% by atomic.potato
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/GlobalSettings.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/GlobalSettings.h"

#include "util/Name.h"

namespace RBX {

const char sGlobalSettings[] = "GlobalSettings";

boost::recursive_mutex GlobalSettings::mutex;

// FUNCTION: WEBSERVICE 0x100b7370
GlobalSettings::GlobalSettings()
{
	setName("Global Settings");
}

// FUNCTION: WEBSERVICE 0x100b74f0
boost::shared_ptr<GlobalSettings> GlobalSettings::singleton()
{
	boost::recursive_mutex::scoped_lock lock(mutex);

	static boost::shared_ptr<GlobalSettings> sing = Creatable<Instance>::create<GlobalSettings>();

	return sing;
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sGlobalSettings>();
template void RBX::Name::callDoDeclare<RBX::sGlobalSettings>();
