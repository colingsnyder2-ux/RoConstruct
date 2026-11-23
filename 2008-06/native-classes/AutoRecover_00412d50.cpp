// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8tree/Instance.h"
#include "v8datamodel/GlobalSettings.h"
#include "v8datamodel/GlobalSettingsItem.h"   // INFERRED: header declaring GlobalSettingsItem<T, name>
#include "CRenderSettings.h"                  // INFERRED: header declaring CRenderSettings
#include <boost/shared_ptr.hpp>

extern char* sRenderSettings;

namespace RBX {

// INFERRED: the global mutex object at 0x974aa0 is a GuidRegistryMutex instance
extern GuidRegistryMutex gSettingsMutex;

namespace {
struct SettingsLock {
    GuidRegistryMutex& m;
    explicit SettingsLock(GuidRegistryMutex& mm) : m(mm) { m.lock(); }
    ~SettingsLock() { m.unlock(); }
};
}

template<>
CRenderSettings& GlobalSettingsItem<CRenderSettings, sRenderSettings>::singleton()
{
    SettingsLock lock(gSettingsMutex);
    // INFERRED: static instance pointer at 0x96cbec, filled in by the CRenderSettings
    // constructor / registration, not by this function
    if (!sInstance)
    {
        boost::shared_ptr<CRenderSettings> s = Creatable<Instance>::create<CRenderSettings>();
        s->setParent(GlobalSettings::singleton().get());
    }
    return *sInstance;
}

}
