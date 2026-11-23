// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// RBX::GlobalSettings::mutex: the static recursive_mutex every GlobalSettingsItem<T>::singleton locks (do_lock 0047cb80).
// INFERRED: definition site (the 2008 exe constructs it in a dynamic initializer; no native unit defined it, so the
// donor-free link left it a zero stub and the first singleton() crashed in EnterCriticalSection).
#include "v8datamodel/GlobalSettings.h"

namespace RBX
{
	boost::recursive_mutex GlobalSettings::mutex;
}
