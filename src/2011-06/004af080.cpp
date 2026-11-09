// from server: 93% by atomic.potato
struct Value { int x; };

extern "C" {
    int __cdecl sub_00401610(const char*, const char*);
    void* __cdecl sub_00401c90(void*);
    Value& __cdecl sub_004a3df0();
    void* __cdecl sub_0058d8f0(void*);
    void* __cdecl sub_00592ce0();
}

extern int g_00aa0258;
extern int g_00cb5544;

struct S {
    int f();
};

int S::f()
{
    *(int*)this = 0xa77164;
    void* p;
    if (g_00aa0258 == 0) {
        p = sub_00592ce0();
    } else {
        sub_00401610((const char*)0x4a58d0, (const char*)0xcb53dc);
        p = &sub_004a3df0();
    }
    void* q = sub_00401c90(&p);
    void* r = sub_0058d8f0(q);
    *(int*)r = (int)this;
    g_00cb5544 = 0x29a;
    return (int)this;
}
