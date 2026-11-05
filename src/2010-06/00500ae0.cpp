// from server: 54% by atomic.potato
// roc 2010-06 00500ae0  unit: Exposer  size: 139 bytes
// library xtp-13.2.1/Source\Controls\XTOutBarCtrl.cpp

extern "C" int __cdecl sub_50FE80(int);

struct Exposer {
    void* field0;
    void* field4;
    void method(int, int, int, int);
};

void Exposer::method(int a, int b, int c, int d)
{
    char buf[0x108];
    void* vtable;
    void* obj;
    int tmp;
    int len;
    char* p;
    unsigned char ch;
    int g1;
    int g2;

    vtable = *(void**)this;
    obj = field4;

    typedef int (__thiscall *Fn1)(void*, int, int, int, int, char*);
    Fn1 f1 = *(Fn1*)(*(int*)obj + 0xbc);
    f1(obj, -1, -1, -1, -1, buf);

    len = sub_50FE80(*(int*)(buf + 0x120));

    p = *(char**)(buf + 0x120);
    ch = (unsigned char)*p;

    g1 = *(int*)0xb94e4c;
    g2 = *(int*)0xb94e50;

    typedef int (__thiscall *Fn2)(void*, int, int, int, int, int, int, int, int, int, char*);
    Fn2 f2 = *(Fn2*)((*(int*)vtable) + 0x30);
    f2(this, ch, g1, g2, 0, 0, 0xa1c958, 0xa1c954, len, 0, buf + 0x10);

    typedef int (__thiscall *Fn3)(void*, char*);
    Fn3 f3 = *(Fn3*)((*(int*)this) + 0x4c);
    f3(this, buf + 0x10);
}
