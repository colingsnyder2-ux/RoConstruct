// from server: 35% by atomic.potato
struct S_func_007ab230 {
    char pad0[8];
    int m_x;
    int f();
};

struct S {
    char pad0[4];
    int f();
};

int S_func_007ab230::f()
{
    return m_x;
}

extern "C" int __stdcall sub_7ab230();
extern "C" int __stdcall sub_6e9440();
extern "C" int __stdcall sub_503a70();
extern "C" int __stdcall sub_7ab640();

int S::f()
{
    *(int*)this = 0x9ef6d4;
    *(int*)((char*)this + 4) = 0x9ef6cc;
    sub_7ab230();
    sub_6e9440();
    sub_7ab230();
    sub_503a70();
    sub_7ab640();
    return 0;
}
