// from server: 84% by atomic.potato
struct Value { int x; };

extern "C" {
    void* __stdcall sub_00401610(void*, void*);
    void* __stdcall sub_00401c90(void*);
    Value& __cdecl sub_004f4750();
    void* __stdcall sub_0058d8f0(void*);
    void* __stdcall sub_00592ce0();
}

extern int g_00aa5c14;
extern int g_00cb8314;
extern int g_00cb8368;

struct S {
    void* field0;
    void* f();
};

void* S::f()
{
    field0 = (void*)0xa7b744;
    void* v;
    if (g_00aa5c14 == 0) {
        v = sub_00592ce0();
    } else {
        sub_00401610((void*)0x4f5760, (void*)0xcb8314);
        v = (void*)&sub_004f4750();
    }
    void* p = v;
    void* q = sub_00401c90(&p);
    void* r = sub_0058d8f0(q);
    *(void**)r = this;
    g_00cb8368 = 0x29a;
    return this;
}
