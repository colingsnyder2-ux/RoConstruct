// from server: 100% by king_originala
struct Context;

struct ContextVTable {
    void *unused[38];
    void (__thiscall *activate)(Context *);
};

struct Context {
    ContextVTable *vtable;
};

struct Service {
    void *get();
    void perform(unsigned int);
};

extern Context *currentContext;
extern void *activeObject;

struct CRobloxWnd {
    char reserved0[0x70];
    Service *service;
    char reserved1[0x30];
    Context *context;
    char reserved2[0x0C];
    unsigned int argument;

    void f();
};

void CRobloxWnd::f()
{
    Context *selected = context;
    if (currentContext != selected) {
        selected->vtable->activate(selected);
        currentContext = selected;
    }

    void *result;
    if (service)
        result = service->get();
    else
        result = 0;

    activeObject = result;
    service->perform(argument);
    activeObject = 0;
}
