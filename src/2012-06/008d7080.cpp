// from server: 54% by atomic.potato
struct Inner {
    virtual void f();
};

struct Outer {
    char pad[0x28];
    Inner* inner;
    void func(int, int);
};

extern "C" void* __cdecl sub_6c1bf0();
extern "C" void __cdecl sub_575bc0(void*, void*);

void Outer::func(int a, int b)
{
    void* v;
    Inner* p = inner;
    void** vtbl = *(void***)p;
    void* r = vtbl[2];
    ((void (__thiscall*)(Inner*, int, void**))r)(p, a, &v);
    void* q = sub_6c1bf0();
    *(void**)v = q;
    sub_575bc0((char*)v + 4, (void*)b);
}
