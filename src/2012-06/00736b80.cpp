// from server: 48% by atomic.potato
struct Inner {
    void* f;
};

struct Outer {
    char pad[0x28];
    Inner* inner;

    void f(void* a, void* b);
};

extern "C" void* __cdecl sub_6c1d00();
extern "C" void __cdecl sub_5771b0(void*);

void Outer::f(void* a, void* b)
{
    void* tmp;
    Inner* p = inner;
    void* r = ((void* (__thiscall*)(Inner*, void**, void*))p->f)(p, &tmp, a);
    void* v = sub_6c1d00();
    *(void**)b = v;
    sub_5771b0((char*)b + 4);
}
