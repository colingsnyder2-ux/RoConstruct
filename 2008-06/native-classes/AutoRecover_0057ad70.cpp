// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <intrin.h>

#pragma intrinsic(_InterlockedDecrement)

namespace RBX {

class ServiceProvider;
struct ServiceAdded;

template<class Owner, class Event> class Listener;

// INFERRED: minimal declaration of the Notifier template used for removeListener
template<class Owner, class Event>
class Notifier
{
public:
    void removeListener(Listener<Owner, Event>* listener) const;
};

// INFERRED: minimal declarations for the base-class destructors
class VerbContainer
{
public:
    virtual ~VerbContainer();
};

class ServiceProvider
{
public:
    virtual ~ServiceProvider();
};

} // namespace RBX

// INFERRED: boost::detail::sp_counted_base layout (vtbl: dtor, dispose, destroy; use_count, weak_count)
struct roc_sp_counted_base
{
    virtual ~roc_sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
};

static __forceinline void roc_release(roc_sp_counted_base* pi)
{
    if (pi != 0)
    {
        if (_InterlockedDecrement(&pi->use_count_) == 0)
        {
            pi->dispose();
            if (_InterlockedDecrement(&pi->weak_count_) == 0)
                pi->destroy();
        }
    }
}

// vtables written during destruction
extern "C" void* g_008303cc[];
extern "C" void* g_008303c0[];
extern "C" void* g_008303b8[];
extern "C" void* g_008303b0[];
extern "C" void* g_008303a0[];
extern "C" void* g_00830390[];
extern "C" void* g_00830380[];
extern "C" void* g_00830370[];
extern "C" void* g_00830360[];
extern "C" void* g_00830350[];
extern "C" void* g_00830340[];
extern "C" void* g_00830330[];
extern "C" void* g_00830320[];
extern "C" void* g_00830318[];
extern "C" void* g_0083030c[];
extern "C" void* g_00830304[];
extern "C" void* g_008302f8[];

// INFERRED: DataModel-like object; only offsets used here matter
struct DataModelObj
{
    char raw[0x268];
};

#define AT(T, off) (*(T*)((char*)self + (off)))

extern "C" void __fastcall fn_0057ad70(DataModelObj* self, int unusedEdx)
{
    AT(void*, 0x000) = g_008303cc;
    AT(void*, 0x010) = g_008303c0;
    AT(void*, 0x014) = g_008303b8;
    AT(void*, 0x020) = g_008303b0;
    AT(void*, 0x024) = g_008303a0;
    AT(void*, 0x044) = g_00830390;
    AT(void*, 0x064) = g_00830380;
    AT(void*, 0x084) = g_00830370;
    AT(void*, 0x0a4) = g_00830360;
    AT(void*, 0x0c4) = g_00830350;
    AT(void*, 0x130) = g_00830340;
    AT(void*, 0x150) = g_00830330;
    AT(void*, 0x170) = g_00830320;
    AT(void*, 0x1c8) = g_00830318;
    AT(void*, 0x1f0) = g_0083030c;
    AT(void*, 0x1f4) = g_00830304;
    AT(void*, 0x1f8) = g_008302f8;

    // Listener<ServiceProvider,ServiceAdded> sub-object at +0x1f8: unregister from provider
    char* provider = AT(char*, 0x20c);
    if (provider != 0)
    {
        ((RBX::Notifier<RBX::ServiceProvider, RBX::ServiceAdded>*)(provider + 0x170))
            ->removeListener((RBX::Listener<RBX::ServiceProvider, RBX::ServiceAdded>*)((char*)self + 0x1f8));
    }

    roc_release(AT(roc_sp_counted_base*, 0x260));

    ((std::string*)((char*)self + 0x234))->~basic_string();

    roc_release(AT(roc_sp_counted_base*, 0x228));
    roc_release(AT(roc_sp_counted_base*, 0x220));
    roc_release(AT(roc_sp_counted_base*, 0x218));
    roc_release(AT(roc_sp_counted_base*, 0x210));
    roc_release(AT(roc_sp_counted_base*, 0x208));
    roc_release(AT(roc_sp_counted_base*, 0x200));

    ((RBX::VerbContainer*)((char*)self + 0x1c8))->RBX::VerbContainer::~VerbContainer();
    ((RBX::ServiceProvider*)self)->RBX::ServiceProvider::~ServiceProvider();
}
