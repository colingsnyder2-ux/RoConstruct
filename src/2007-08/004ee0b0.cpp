// from server: 26% by colin
extern "C" {
    long __stdcall InterlockedIncrement(long volatile*);
    long __stdcall InterlockedDecrement(long volatile*);
}

struct RefCounted {
    void* vtable;
    long refcount;
    void AddRef();
    void Release();
};

void RefCounted::AddRef()
{
    InterlockedIncrement(&refcount);
}

void RefCounted::Release()
{
    if (InterlockedDecrement(&refcount) == 0) {
        void** vt = (void**)vtable;
        ((void (__thiscall*)(RefCounted*, int))vt[0])(this, 1);
    }
}

struct Vec3 {
    float x, y, z;
};

struct Obj {
    void* vtable;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl func_004f6180();
extern "C" void __cdecl func_004dd250();
extern "C" void __cdecl func_00474f70();
extern "C" void __cdecl func_004eb510();
extern "C" void __cdecl func_004eecb0();

struct HeadBuilder {
    void* vtable;
    char pad[8];
    void* vec_begin;
    void* vec_end;
    void* vec_cap;

    void func_004ee0b0(Vec3* a, Vec3* b);
};

void HeadBuilder::func_004ee0b0(Vec3* a, Vec3* b)
{
    func_004f6180();
    vtable = (void*)0x79f4ac;

    Vec3* p = (a->x < b->x) ? a : b;
    float f = p->x * *(double*)0x79f348;

    Obj* o = (Obj*)operator_new(0x1c);
    if (o) {
        o->vtable = (void*)0x797984;
        o->field4 = 0;
        o->field8 = 0;
        o->vtable = (void*)0x79f304;
        o->field10 = 0;
        o->field14 = 0;
        o->fieldc = 0;
        o->field18 = 5;
    } else {
        o = 0;
    }

    RefCounted* rc = 0;
    if (o) {
        rc = (RefCounted*)o;
        rc->AddRef();
    }

    func_004dd250();
    if (rc) {
        rc->Release();
    }

    func_00474f70();
    func_004eb510();
    func_004eecb0();
}
