// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_camerastatevirtual_594bbcc27dbeb602.cpp

// Candidate translation unit (score above; library headers required).

namespace RBX {
    class Instance;
    class ModelInstance;
    class ServiceProvider;
}

RBX::ModelInstance* func_0049aca0(RBX::Instance*);
RBX::ServiceProvider* func_005a32e0(RBX::Instance*);

struct State {
    bool a, b, c, d, e, f, g, h, i;
    bool func_005a0190();
};

struct Receiver {
    void func_005ce960(State*);
};

struct Result {
    void func_005ce6e0(State*,int);
};

struct CameraOwner { virtual void slot0(); virtual Result* get()const; };
struct Base {
    void func_00614cc0();
};

struct S {
    char pad0[0x2c];
    void* object;
    char pad30[4];
    int tag;
    char pad38[0x10];
    int count;

    void method(int, int, int);
};

void S::method(int, int, int) {
    ((Base*)((char*)this - 0x70))->func_00614cc0();

    if (tag == 7) {
        void** table = *(void***)object;
        ((void (__thiscall*)(void*, int*))table[2])(object, &tag);
    }

    RBX::Instance* instance = (RBX::Instance*)((char*)this - 0x384);
    if (func_0049aca0(instance))
        return;

    RBX::ServiceProvider* provider = func_005a32e0(instance);
    if (!provider)
        return;

    Receiver* receiver = *(Receiver**)((char*)provider + 0x130);
    if (!receiver)
        return;

    State state;
    state.a = false;
    state.b = false;
    state.c = false;
    state.d = false;
    state.e = false;
    state.f = false;
    state.g = false;
    state.h = false;
    state.i = false;
    receiver->func_005ce960(&state);

    if (state.func_005a0190()) {
        CameraOwner* base = reinterpret_cast<CameraOwner*>((char*)this - 0xfc);
        int oldCount = count;
        count = oldCount + 1;
        base->get()->func_005ce6e0(&state,oldCount);
    } else {
        count = 0;
    }
}