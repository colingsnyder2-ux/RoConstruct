// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_outputview_0d78b0022183b427.cpp

// Candidate translation unit (score above; library headers required).
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

void* __cdecl operator new(unsigned int);

struct Mutex {
    void* handle;
    bool owned;
    Mutex();
    ~Mutex();
    void lock();
    void unlock();
};

struct __declspec(novtable) Listener {
    virtual void notify() = 0;
};

struct Service {
    char pad[0x28];
    Mutex mutex;
    void attach(Listener*);
};

#include <boost/shared_ptr.hpp>
struct Shared : boost::shared_ptr<Service> {
    void attach(Listener* listener) { if (get()) get()->attach(listener); }
};

Shared __cdecl getService();

struct Lock {
    Mutex* mutex;
    bool locked;
    Lock(Mutex&);
    ~Lock();
};

inline Lock::Lock(Mutex& m) : mutex(&m), locked(false)
{
    mutex->lock();
    locked = true;
}

inline Lock::~Lock()
{
    if (locked)
        mutex->unlock();
}

struct VCSecureHtmlView {
    char pad[0xf0];
    char field_f4;
    VCSecureHtmlView();
    virtual ~VCSecureHtmlView();
};

struct COutputView : VCSecureHtmlView {
    char remainder[0x28];
    COutputView();
    virtual ~COutputView();
};

struct Data {
    Data** proxy;
    char pad[12];
    unsigned long field_10;
    unsigned long field_14;
    unsigned long field_18;
    unsigned long field_1c;
    Data();
    ~Data();
};

inline Data::Data()
{
    Data** p = static_cast<Data**>(operator new(4));
    if (p)
        *p = this;
    else
        p = 0;
    proxy = p;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_1c = 0;
}

struct CStandardOutputView : COutputView, Listener {
    Data data;
    Mutex mutex;
    CStandardOutputView();
    virtual ~CStandardOutputView();
    virtual void notify();
};

CStandardOutputView::CStandardOutputView()
{
    field_f4 = true;
    Lock lock(getService().get()->mutex);
    getService().attach(static_cast<Listener*>(this));
}