// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_functiondispatch_984dcee79d754a8b.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Shared;
struct Failure {
    char storage[40];
    Failure();
    ~Failure();
};

extern __declspec(noreturn) void __cdecl raiseFailure(const Failure&);

struct Dispatch {
    void* unused;
    void (__cdecl *invoke)(void*, Shared);
};

struct S {
    Dispatch* dispatch;
    unsigned long reserved;
    unsigned char storage[1];
    void f(Shared value);
};

void S::f(Shared value)
{
    if (!dispatch)
        raiseFailure(Failure());
    dispatch->invoke(storage, value);
}
