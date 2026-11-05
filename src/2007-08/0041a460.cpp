// from server: 14% by colin
struct DescribedBase {
    void* vtable;
};

struct RefCounted {
    void* vtable;
    void AddRef();
    void Release();
};

struct Arguments {
    void* vtable;
    void getArg(int index, void* out);
};

struct BoundFuncDesc {
    char pad[0x28];
    void* func;
    int argCount;
    RefCounted* arg0;
    RefCounted* arg1;
    void invoke(Arguments* args);
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl std_bad_cast(const char* msg);
extern "C" void __cdecl std_string_ctor(void* self, const char* str);
extern "C" void __cdecl std_string_dtor(void* self);
extern "C" void __cdecl std_throw_bad_cast(void* info);

void BoundFuncDesc::invoke(Arguments* args) {
    void* a0 = 0;
    void* a1 = 0;
    if (arg0) {
        a0 = arg0;
        arg0->AddRef();
    }
    args->getArg(1, &a0);
    if (arg1) {
        a1 = arg1;
        arg1->AddRef();
    }
    args->getArg(2, &a1);
    void* result = operator_new(0);
    if (!result) {
        std_bad_cast("bad cast");
    }
    void* v0 = 0;
    void* v1 = 0;
    if (a0) {
        v0 = *(void**)a0;
    }
    if (a1) {
        v1 = *(void**)a1;
    }
    ((void (__thiscall*)(void*, void*, void*))func)(this, v0, v1);
    if (a1) {
        ((RefCounted*)a1)->Release();
    }
    if (a0) {
        ((RefCounted*)a0)->Release();
    }
}
