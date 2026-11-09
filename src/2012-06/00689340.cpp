// from server: 84% by atomic.potato
struct Inner {
    virtual void f();
};

struct Outer {
    char pad[0x28];
    Inner* p;
};

struct S {
    char pad[4];
    int f(int a, int b);
};

extern "C" int __stdcall sub_753310();
extern "C" void __stdcall sub_577260(int);

int S::f(int a, int b)
{
    Inner* inner = *(Inner**)((char*)this + 0x28);
    void** vtbl = *(void***)inner;
    void (*fn)(void*, int*, int) = (void (*)(void*, int*, int))vtbl[2];
    char buf[0x30];
    int result = ((int (__stdcall*)(void*, int*, int))fn)(inner, (int*)buf, a);
    int* out = (int*)b;
    *out = sub_753310();
    sub_577260((int)(out + 1));
    return result;
}
