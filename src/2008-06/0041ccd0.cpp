// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" {
}







struct Service;

struct Shared {
    void* object;
    void* control;
    Shared(const Shared&);
};

Shared __cdecl getShared(Service*);

struct Callback {
    void (__cdecl *function)();
    int adjustment;
};

void __cdecl callback();

struct Bind {
    unsigned char data[48];
    Bind(const Bind&);
};

Bind __cdecl makeBind(Callback, Shared, std::string);

struct FunctionTable {
    void (__cdecl *manager)(void*, void*, int);
};

struct Function {
    FunctionTable* table;
    unsigned int reserved;
    unsigned int storage[6];
    Function(const Function&);
    Function(Bind, int);
};

struct Queue {
    void append(Function);
};

extern Queue* queue;

struct Service {
    void submit(std::string);
};

void Service::submit(std::string text)
{
    Callback target = { callback, 0 };
    queue->append(Function(makeBind(target, getShared(this), text), 0));
}
