// from server: 100% by colin
struct A { char pad[0x140]; };
struct B { int x; };
struct Joint : A, B {
    void f(bool);
};

struct S_func_006cb020 {
    char pad0[32];
    int m_x;
    B* f();
};

void __stdcall func(void*, S_func_006cb020* p)
{
    B* b = p->f();
    if (b)
        static_cast<Joint*>(b)->f(false);
}
