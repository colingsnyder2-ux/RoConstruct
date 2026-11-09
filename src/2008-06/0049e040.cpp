// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_abuseworkerimplicit11e5489400ca45c4.cpp

// Candidate translation unit (score above; library headers required).
// from server: 89% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

#include <string>
typedef std::string String;

struct Storage {
    unsigned char data[40];
    Storage();
    ~Storage();
};

struct Control {
    void* vtable;
    volatile long strong;
    volatile long weak;
};

struct Count {
    Control* pointer;
    Count(Storage*);
    ~Count();
};

void __cdecl func_0047d410(Count*, Storage*, Storage*) throw();

struct Shared {
    Storage* pointer;
    Count count;
    Shared(Storage*);
    Shared(const Shared&);
};

Shared::Shared(Storage* p) : pointer(p), count(p)
{
    func_0047d410(&count, p, p);
}

Shared::Shared(const Shared& other)
    : pointer(other.pointer), count(other.count)
{
    if (count.pointer) {
        volatile long* counter = &count.pointer->strong;
        _InterlockedExchangeAdd(counter, 1);
    }
}

typedef void (__cdecl *Callback)(Shared, String);
void __cdecl callback(Shared, String);

struct Bound {
    Callback callback;
    Shared object;
    String text;
    void operator()() const;
};

Bound __cdecl bind(Callback, Shared, String);

#include <boost/function.hpp>
typedef boost::function0<void> Function;
struct Thread {
    unsigned char data[20];
    Thread(const Function&, const char*);
    ~Thread();
};

extern const char threadName[];

struct ThreadOwner {
    Thread* pointer;
    ThreadOwner();
    ~ThreadOwner();
    void reset(Thread*);
};

ThreadOwner::ThreadOwner() : pointer(0)
{
}

ThreadOwner::~ThreadOwner()
{
    delete pointer;
}

void ThreadOwner::reset(Thread* p)
{
    Thread* old = pointer;
    pointer = p;
    delete old;
}

struct S {
    Shared object;
    ThreadOwner thread;
    S(String);
};

S::S(String text) : object(new Storage), thread()
{
    thread.reset(new Thread(
        bind(callback, object, text),
        "rbx_abusereporter"));
}
