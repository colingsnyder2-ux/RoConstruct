// from server: 26% by colin
struct RefCounted {
    void AddRef();
    void Release();
};

struct ArgHolder {
    void* ptr;
    RefCounted* ref;
};

struct FuncDescBase {
    char pad[0x30];
    ArgHolder a;
    ArgHolder b;
};

struct BoundFuncDesc : FuncDescBase {
    void callHelper(void*, void*, void*, void*);
    void invoke(void* args, int count);
};

extern "C" void* __cdecl sub_630D36(void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_630B9E(void*, void*);
extern "C" void (__stdcall *off_77E710)(void*);

void BoundFuncDesc::invoke(void* args, int count)
{
    ArgHolder h1;
    ArgHolder h2;

    h1.ptr = this->a.ptr;
    if (this->a.ref) {
        h1.ref = this->a.ref;
        h1.ref->AddRef();
    } else {
        h1.ref = 0;
    }

    void** vt = *(void***)args;
    void (*fn)(void*, void*, int) = (void (*)(void*, void*, int))vt[1];
    fn(args, &h1, 1);

    h2.ptr = this->b.ptr;
    if (this->b.ref) {
        h2.ref = this->b.ref;
        h2.ref->AddRef();
    } else {
        h2.ref = 0;
    }

    void** vt2 = *(void***)args;
    void (*fn2)(void*, void*, int) = (void (*)(void*, void*, int))vt2[1];
    fn2(args, &h2, 2);

    void* result = sub_630D36((void*)0x88209C, (void*)0x882E78, (void*)0, (void*)0, (void*)0);
    if (result == 0) {
        void* tmp;
        off_77E710(&tmp);
        sub_630B9E(&tmp, (void*)0x841E0C);
    }

    this->callHelper(result, &h1, &h2, (char*)args + 4);
}
