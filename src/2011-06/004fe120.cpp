// from server: 80% by atomic.potato
struct Value { int x; };

extern "C" {
    int __cdecl sub_00401610(int, int);
    int __cdecl sub_00401c90(void*);
    Value& __cdecl sub_004f4600();
    int __cdecl sub_0058d8f0();
    int __cdecl sub_00592ce0();
}

extern int g_00aa5c04;
extern int g_00cb835c;

struct S {
    int f();
};

int S::f()
{
    *(int*)this = 0xa7b6f0;
    if (g_00aa5c04 == 0) {
        sub_00592ce0();
    } else {
        sub_00401610(0xcb8308, 0x4f5730);
        sub_004f4600();
    }
    int* p = (int*)sub_00401c90(&p);
    sub_0058d8f0();
    *p = (int)this;
    g_00cb835c = 0x29a;
    return (int)this;
}
