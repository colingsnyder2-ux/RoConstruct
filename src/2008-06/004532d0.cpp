// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_reportabuse_e2f4d50f5856115c.cpp

// Candidate translation unit (score above; library headers required).
// from server: 96% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Prompt
{
    int f();
};

struct Object
{
    Prompt* getPrompt();
};

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<Object> Result;
inline const Result& ref(const Result& value) { return value; }

struct Source
{
    Result get();
};

struct Guard
{
    unsigned char storage[12];

    Guard(Result);
    ~Guard();
};

struct ReportAbuseVerb
{
    unsigned char padding[12];
    Source* source;

    char f();
};

char ReportAbuseVerb::f()
{
    Guard guard(ref(source->get()));
    return (char)source->get().get()->getPrompt()->f();
}
