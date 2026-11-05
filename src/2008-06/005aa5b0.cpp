// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_scripterror_1ca97978f1e1d7fa.cpp

// Candidate translation unit (score above; library headers required).

#include <boost/shared_ptr.hpp>

struct Logger {
    void __cdecl reportError(int, const char*, const char*);
};

typedef boost::shared_ptr<Logger> Handle;

extern Handle __cdecl getHandle();
extern const char* __cdecl getText(void*, int, unsigned int*);
extern const char errorFormat[];

int __cdecl callback(void* state)
{
    {
        getHandle()->reportError(3, errorFormat, getText(state, -1, 0));
    }
    int* p = 0;
    p[0] = p[1];
    return 0;
}