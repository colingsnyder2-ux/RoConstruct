// from server: 20% by atomic.potato
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl func_0098211a();

struct Inner {
    char pad0[4];
    Inner* next;
    Inner* prev;
    char pad1[4];
    char flag;
};

struct Outer {
    void* vtbl;
    int field4;
    int field8;
    int fieldC;
    Inner* field10;
    int field14;
};

struct S {
    int f(int, int);
};

extern "C" void* __cdecl sub_98211a(unsigned int);
extern "C" void* __cdecl sub_923a90(void*, int, int);
extern "C" void* __cdecl sub_877f70();

int S::f(int a, int b)
{
    Outer* self = (Outer*)this;
    void* mem = sub_98211a(0x148);
    void* obj = 0;
    if (mem) {
        obj = sub_923a90(mem, (int)self, b);
    }
    self->field4 = a;
    self->field8 = (int)obj;
    self->fieldC = b;
    Inner* inner = (Inner*)((char*)self + 0x10);
    self->vtbl = (void*)0xc0726c;
    Inner* n = (Inner*)sub_877f70();
    inner->next = n;
    n->flag = 1;
    n->next = n;
    n->prev = n;
    inner->prev = n;
    inner->pad1[0] = 0;
    return (int)self;
}
