// from server: 100% by colin
// RBX::Network::Client  0049f210  ?f@S@@QAEXUString@@H0@Z
#include <string>

struct Error {
    char storage[40];
    Error();
    ~Error();
};

__declspec(noreturn) void __cdecl raiseError(const Error&);

typedef void (__cdecl *Callback)(void*, std::string, int, std::string);

struct CallbackTable {
    Callback unused;
    Callback invoke;
};

struct S {
    CallbackTable *table;
    unsigned int reserved;
    char context;

    void f(std::string first, int value, std::string second);
};

void S::f(std::string first, int value, std::string second) {
    if (!table)
        raiseError(Error());

    table->invoke(&context, first, value, second);
}