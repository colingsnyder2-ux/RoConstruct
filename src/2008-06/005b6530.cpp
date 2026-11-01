// from server: 100% by king_originala
namespace RBX {
    struct Instance;
    struct ServiceProvider {
        void action(int);
    };
}

struct CastResult {
    char padding[0x1e4];
    int value;
};

struct GlobalState {
    char padding[0x20];
    int value;
    void notify(int);
};

extern "C" CastResult* __stdcall castObject(void*, int, const void*);
RBX::ServiceProvider* __cdecl func_005807b0(RBX::Instance*);

struct S {
    char padding[0x18];
    RBX::Instance* instance;
    int f(void*);
};

int S::f(void* object)
{
    CastResult* result = castObject(object, 0, (const void*)0x97bee0);
    if (result) {
        GlobalState* state = (GlobalState*)0x976fa0;
        int value = result->value;
        if (state->value != value) {
            state->value = value;
            state->notify(value);
        }
        func_005807b0(instance)->action(4);
    }
    return 0;
}
