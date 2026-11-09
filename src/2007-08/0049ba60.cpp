// from server: 43% by colin
struct RefCounted {
    void AddRef();
    void Release();
};

struct ArgValue {
    void* ptr;
    RefCounted* ref;
};

struct ArgList {
    virtual void v0();
    virtual void SetArg(int index, ArgValue* value);
};

struct FuncDescBase {
    char pad0[0x28];
    void (__thiscall *callback)(int);
    char pad1[0x04];
    ArgValue arg0;
    ArgValue arg1;
    ArgValue arg2;
    ArgValue arg3;
};

extern "C" void* __cdecl sub_630D36(void*, void*, void*, int, int);
extern "C" void __cdecl sub_630B9E(void*, void*);
extern "C" void* __cdecl sub_56EFB0(void*);
extern "C" void* __cdecl sub_56F410(void*, void*);
extern "C" void* __cdecl sub_77E710();
extern "C" void* __cdecl sub_77E69C(void*, void*);

struct VClientBoundFuncDesc : FuncDescBase {
    void declareSignature(ArgList* args);
};

void VClientBoundFuncDesc::declareSignature(ArgList* args)
{
    ArgValue a0;
    ArgValue a1;
    ArgValue a2;
    ArgValue a3;

    a0.ptr = arg0.ptr;
    if (arg0.ref) {
        a0.ref = (RefCounted*)((void**)arg0.ref)[2];
    } else {
        a0.ref = 0;
    }
    args->SetArg(1, &a0);

    a1.ptr = arg1.ptr;
    if (arg1.ref) {
        a1.ref = (RefCounted*)((void**)arg1.ref)[2];
    } else {
        a1.ref = 0;
    }
    args->SetArg(2, &a1);

    a2.ptr = arg2.ptr;
    if (arg2.ref) {
        a2.ref = (RefCounted*)((void**)arg2.ref)[2];
    } else {
        a2.ref = 0;
    }
    args->SetArg(3, &a2);

    a3.ptr = arg3.ptr;
    if (arg3.ref) {
        a3.ref = (RefCounted*)((void**)arg3.ref)[2];
    } else {
        a3.ref = 0;
    }
    args->SetArg(4, &a3);

    void* result = sub_630D36(0, (void*)0x88209C, (void*)0x88F968, 0, 0);
    if (!result) {
        void* s = sub_77E710();
        sub_630B9E(s, (void*)0x841E0C);
    }

    void* v1 = sub_56EFB0(&a3);
    void* v2 = sub_56EFB0(&a2);
    void* v3 = sub_56EFB0(&a1);
    void* v4 = sub_56F410(&a0, v3);

    void* tmp = sub_77E69C(v4, 0);

    callback((int)result + (int)tmp);

    if (a3.ref) {
        ((void(__thiscall*)(RefCounted*, int))((void**)a3.ref)[0])(a3.ref, 1);
    }
    if (a2.ref) {
        ((void(__thiscall*)(RefCounted*, int))((void**)a2.ref)[0])(a2.ref, 1);
    }
    if (a1.ref) {
        ((void(__thiscall*)(RefCounted*, int))((void**)a1.ref)[0])(a1.ref, 1);
    }
    if (a0.ref) {
        ((void(__thiscall*)(RefCounted*, int))((void**)a0.ref)[0])(a0.ref, 1);
    }
}
