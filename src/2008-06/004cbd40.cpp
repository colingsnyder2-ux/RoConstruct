// from server: 100% by colin
struct VTable {
    char pad[0xb0];
    int (__thiscall *func)(void*, int, int);
};

struct Obj1 {
    char pad[4];
    char* field4;
};

struct Obj2 {
    VTable* vtable;
};

struct Inner {
    char pad[0x144];
    int field144;
};

struct Outer {
    char pad[0x2d54];
    int field2d54;
    int field2d58;
};

struct Sub {
    char pad[0x18];
    int field0;
    void construct(int v);
};

struct Target {
    int field0;
    int field4;
    Obj1* field8;
    Obj2* fieldC;
    char field10;
    char pad11[3];
    int field14;
    Sub sub;
    char pad2c[0xf8];
    int field12c;
    int field130;
    void* init(Obj1* a, Obj2* b);
};

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
extern "C" void* __cdecl getInner();

void* Target::init(Obj1* a, Obj2* b) {
    field0 = 0;
    field4 = 0;
    field8 = a;
    fieldC = b;
    field10 = 0;
    Outer* o = (Outer*)a->field4;
    int r = b->vtable->func(b, o->field2d54, o->field2d58);
    Inner* in = (Inner*)getInner();
    int v = in->field144 + r;
    field14 = v;
    sub.construct(v);
    field12c = 2;
    field130 = 0;

    return this;
}
