// from server: 42% by colin
struct DescribedBase {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
};

struct FunctionDescriptor {
    char pad0[0x28];
    void* field28;
    void* field2c;
    void* field30;
    void* field34;
    void* field38;
    void* field3c;
};

struct Arg {
    void* ptr;
};

struct Arguments {
    virtual void unknown0();
    virtual void addArg(int index, Arg* arg);
};

struct BoundFuncDesc : FunctionDescriptor {
    void invoke(Arguments* args);
};

extern "C" void* __cdecl sub_630D36(void* a, void* b, void* c, void* d, void* e);
extern "C" void __cdecl sub_630B9E(void* a, void* b);
extern "C" void* __stdcall sub_56EFB0(void* p);
extern "C" void* __stdcall sub_77E710(void* p);

void BoundFuncDesc::invoke(Arguments* args)
{
    Arg a1;
    Arg a2;

    a1.ptr = field30;
    if (field34) {
        void** vt = *(void***)field34;
        typedef void* (__thiscall *Fn)(void*);
        a1.ptr = ((Fn)vt[2])(field34);
    } else {
        a1.ptr = 0;
    }

    void** vt = *(void***)args;
    typedef void (__thiscall *AddFn)(void*, int, Arg*);
    ((AddFn)vt[1])(args, 1, &a1);

    a2.ptr = field38;
    if (field3c) {
        void** vt2 = *(void***)field3c;
        typedef void* (__thiscall *Fn2)(void*);
        a2.ptr = ((Fn2)vt2[2])(field3c);
    } else {
        a2.ptr = 0;
    }

    void** vt3 = *(void***)args;
    ((AddFn)vt3[1])(args, 2, &a2);

    void* result = sub_630D36(field2c, 0, (void*)0x88209C, (void*)0x8904BC, 0);
    if (!result) {
        sub_77E710((void*)0x786E04);
        sub_630B9E((void*)0x841E0C, 0);
    }

    void* p1 = sub_56EFB0(&a2);
    void* p2 = sub_56EFB0(&a1);

    void* v1 = *(void**)p1;
    void* v2 = *(void**)p2;
    void* fn = field28;
    void* self = field2c;
    typedef void (__thiscall *CallFn)(void*, void*, void*);
    ((CallFn)fn)(self, v2, v1);

    if (a2.ptr) {
        void** v = *(void***)a2.ptr;
        typedef void (__thiscall *ReleaseFn)(void*, int);
        ((ReleaseFn)v[0])(a2.ptr, 1);
    }
    if (a1.ptr) {
        void** v = *(void***)a1.ptr;
        typedef void (__thiscall *ReleaseFn)(void*, int);
        ((ReleaseFn)v[0])(a1.ptr, 1);
    }
}
