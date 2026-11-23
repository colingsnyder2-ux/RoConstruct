// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: native-headers has no ServiceProvider.h at v8datamodel/, so the minimal
// types needed for this one template are declared locally; names/namespaces match the mangled symbols.

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count_;
    long weak_count_;
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count& operator=(const shared_count& r);
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    ~shared_ptr()
    {
        detail::sp_counted_base* p = pn.pi_;
        if (p && _InterlockedDecrement(&p->use_count_) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak_count_) == 0)
                p->destroy();
        }
    }
    T* get() const { return px; }
};
void call_once(void (*f)(), long& flag);
}

extern "C" long _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

namespace RBX {

class Instance {
public:
    void setParent(Instance* p);
};
class RunService : public Instance {};

template<class T> class Creatable {
public:
    template<class U> static boost::shared_ptr<U> create();
};

class ServiceProvider : public Instance {
public:
    struct Entry {
        RunService* ptr;
        boost::detail::shared_count count;
    };
    char pad[0x19c - 4]; // INFERRED: Instance base size placeholder; only +0x19c/+0x1a0 are touched
    Entry* servicesBegin;
    Entry* servicesEnd;

    static long classIndexFlag;
    static void initClassIndex();
    template<class T> static unsigned doGetClassIndex();
    template<class T> T* create() const;
};

} // namespace RBX

extern "C" int __fastcall fn_00452c80(const RBX::ServiceProvider* self, int unusedEdx);

namespace RBX {

template<>
RunService* ServiceProvider::create<RunService>() const
{
    if (RunService* existing = (RunService*)fn_00452c80(this, 0))
        return existing;

    boost::shared_ptr<RunService> service = Creatable<Instance>::create<RunService>();
    boost::call_once(&ServiceProvider::initClassIndex, ServiceProvider::classIndexFlag);
    unsigned idx = doGetClassIndex<RunService>();
    ServiceProvider* self = const_cast<ServiceProvider*>(this);
    Entry& e = self->servicesBegin[idx];
    e.ptr = service.px;
    e.count = service.pn;
    service.px->setParent(self);
    return service.px;
}

}
