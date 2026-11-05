// from server: 58% by atomic.potato
struct Inner {
    char pad0[0x0c];
    void (__stdcall *fn)(void*, void*);
};

struct Outer {
    char pad0[0x1c];
    Inner* inner;
};

struct Target {
    char pad0[0x10];
    char pad1[4];
    int field4;
    int field8;
};

extern "C" void __stdcall sub_676f40(void*);

void __stdcall func(Outer* self, void* a, void* b)
{
    Inner* inner = self->inner;
    void (__stdcall *fn)(void*, void*) = inner->fn;
    Target* t = 0;
    fn(a, &t);
    Target* p = (Target*)((char*)t + 0x10);
    sub_676f40(p);
    p->field8 = (int)b;
    p->field4 = 5;
}
