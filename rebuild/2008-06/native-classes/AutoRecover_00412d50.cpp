// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the headers v8datamodel/GlobalSettingsItem.h and CRenderSettings.h do not
// exist, so everything this function needs is declared locally.

extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)

namespace boost {
namespace detail {
// INFERRED: vtable layout +0 dtor, +4 dispose, +8 destroy; use count at +4, weak count at +8
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count_;
    long weak_count_;
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0)
                destroy();
        }
    }
};
}

template<class T>
class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    ~shared_ptr()
    {
        if (pn)
            pn->release();
    }
    T* get() const { return px; }
    T* operator->() const { return px; }
};
}

class CRenderSettings;

namespace RBX {

class GuidRegistryMutex {
public:
    void lock();
    void unlock();
};

class Instance {
public:
    void setParent(Instance* parent);
};

class GlobalSettings : public Instance {
public:
    static boost::shared_ptr<GlobalSettings> singleton();
};

template<class T>
class Creatable {
public:
    template<class U>
    static boost::shared_ptr<U> create();
};

}

class CRenderSettings : public RBX::Instance {
};

extern char* sRenderSettings;

namespace RBX {

template<class T, char*& name>
class GlobalSettingsItem {
public:
    static T& singleton();
};

// INFERRED: global mutex object at 0x974aa0
extern GuidRegistryMutex gGlobalSettingsMutex;
// INFERRED: static instance pointer at 0x96cbec
extern CRenderSettings* gRenderSettingsInstance;

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
    SettingsLock lock(gGlobalSettingsMutex);
    if (!gRenderSettingsInstance)
    {
        boost::shared_ptr<CRenderSettings> s = Creatable<Instance>::create<CRenderSettings>();
        s->setParent(GlobalSettings::singleton().get());
    }
    return *gRenderSettingsInstance;
}

}
