// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_reflection_14c60d025fb48cf3.cpp

// Candidate translation unit (score above; library headers required).

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


#include <boost/shared_ptr.hpp>
struct Value {
    void* first;
    boost::shared_ptr<void> second;
};

struct ExceptionObject
{
    unsigned long words[10];

    ExceptionObject();
    ~ExceptionObject();
};

__declspec(noreturn) void __cdecl raise_exception(const void *);

struct Operations
{
    void *unused;
    bool (__cdecl *invoke)(void *, Value, Value);
};

struct S
{
    Operations *operations;
    unsigned long reserved;
    unsigned char storage[1];

    bool invoke(Value first, Value second);
};

bool S::invoke(Value first, Value second)
{
    if (!operations)
        raise_exception(&ExceptionObject());

    return operations->invoke(storage, first, second);
}