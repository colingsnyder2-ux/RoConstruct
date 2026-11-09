// from server: 22% by atomic.potato
extern "C" int __cdecl sub_523580(int, int);
extern "C" int __cdecl sub_6322e0(int, int, void*);
extern "C" int __cdecl sub_642ee0();
extern "C" int __cdecl sub_6432d0();
extern "C" int __cdecl sub_6aa720();
extern "C" int __cdecl sub_6aa7a0(void*);
extern "C" int __cdecl sub_702890(void*);

struct ServiceProvider
{
    int f(int, int, int, int, int);
};

int ServiceProvider::f(int a, int b, int c, int d, int e)
{
    int v = sub_523580(b, a);
    sub_702890((void*)v);
    *(int*)((char*)this + 0x38) = c;
    *(int*)((char*)this + 0x3c) = d;
    *(int*)this = 0x9ce778;
    sub_6aa720();
    ++*(int*)0xb8ffe0;
    *(int*)((char*)this + 0x14) = sub_642ee0();
    ++*(int*)0xb8fda0;
    int r = sub_6322e0(e, sub_6432d0(), (char*)this + 0x40);
    sub_6aa7a0((void*)r);
    return (int)this;
}
