// from server: 42% by atomic.potato
struct Slot {
    void* vtbl;
    int val;
};

struct Inner {
    char pad[8];
};

struct Outer {
    void* vtbl;
    void (__thiscall *fn)(void*, Slot*);
};

extern "C" void __cdecl _invalid_parameter_noinfo();
extern "C" void* __cdecl sub_7a79a0(int);
extern "C" void __cdecl sub_4ab810(void*, int);
extern "C" void __cdecl sub_4ab4b0(void*);

void __cdecl sub_6b01a0(Outer* self, Slot* arg)
{
    Inner inner;
    sub_4ab810(&inner, 1);

    int count = (*(int*)((char*)&inner + 8) - *(int*)((char*)&inner + 4)) >> 2;
    if (count <= 0) {
        _invalid_parameter_noinfo();
    }

    Slot* src = *(Slot**)((char*)&inner + 4);
    Slot* tmp = 0;
    Slot* alloc = (Slot*)sub_7a79a0(8);
    if (alloc) {
        alloc->vtbl = (void*)0xa17ecc;
        alloc->val = *(int*)((char*)&inner + 0x20);
        tmp = alloc;
    } else {
        tmp = 0;
    }

    Slot* old = src;
    if (&tmp != &src) {
        old = src;
        src = tmp;
    }

    if (old) {
        void** vt = (void**)old->vtbl;
        void (*dtor)(void*, int) = (void (*)(void*, int))vt[0];
        dtor(old, 1);
    }

    void** vt2 = (void**)self->vtbl;
    void (*fn)(void*, Slot*) = (void (*)(void*, Slot*))vt2[1];
    fn(self, src);

    sub_4ab4b0(&inner);
}
