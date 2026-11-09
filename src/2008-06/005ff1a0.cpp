// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

namespace RBX {
struct Instance {
    virtual ~Instance();
    char pad[0x100];
    Instance* next;
};

struct Tool;
struct Action;

struct ServiceProvider : Instance {
    ServiceProvider* finish();
    void attach(Action*);
};

struct Action {
    char storage[0x2c];
    Action(ServiceProvider*, Tool*);
};

struct Tool : Instance {
    char pad108[0xa4];
    ServiceProvider* provider;
    char pad1b0[0x50];
    Action* action;

    void update();
};
}

RBX::Instance* __cdecl func_0049aca0(RBX::Instance*);
RBX::ServiceProvider* __cdecl func_00491e50(RBX::Instance*);

void RBX::Tool::update()
{
    Instance* parent = next;
    if (parent && parent == func_0049aca0(this)) {
        provider = func_00491e50(this);
        action = new Action(provider, this);
        provider->attach(action);
    }
}
