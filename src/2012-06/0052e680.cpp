// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_invoke_115c5a0e7fd036c9.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct Error {
    char storage[40];
    Error();
    ~Error();
};

__declspec(noreturn) void __cdecl raiseError(const Error&);

typedef boost::shared_ptr<void> Shared;

struct Table {
    void* unused;
    void (__cdecl *invoke)(void*, Shared, int);
};

struct S {
    Table* table;
    unsigned int reserved;
    char context[1];

    void f(Shared value, int argument);
};

void S::f(Shared value, int argument) {
    if (!table)
        raiseError(Error());
    table->invoke(context, value, argument);
}
