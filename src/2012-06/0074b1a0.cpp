// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_md5invoke_bd64ebdf9f4b7b5c.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Shared;
struct Error {
    char storage[40];

    Error();
    ~Error();
};

__declspec(noreturn) void __cdecl raise_error(const Error&);

struct Dispatch {
    void (__cdecl *reserved)();
    void (__cdecl *invoke)(void*, int, Shared);
};

struct S {
    Dispatch* dispatch;
    unsigned long padding;
    char storage[1];

    void f(int, Shared);
};

void S::f(int value, Shared argument)
{
    if (!dispatch)
        raise_error(Error());

    dispatch->invoke(storage, value, argument);
}
