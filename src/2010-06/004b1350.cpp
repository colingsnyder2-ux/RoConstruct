// from server: 54% by atomic.potato
extern "C" void __stdcall func_004add20();

struct Inner {
    char pad[0x10];
    void (__thiscall *fn)(void *, void *);
};

struct Outer {
    char pad[0x1c];
    Inner *inner;
    void method(void *a, void *b);
};

void Outer::method(void *a, void *b)
{
    Inner *p = inner;
    void *v = p->fn;
    func_004add20();
    ((void (__thiscall *)(Inner *, void *, void *))v)(p, a, &a);
}
