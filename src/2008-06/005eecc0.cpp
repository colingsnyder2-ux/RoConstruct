// from server: 100% by king_originala
struct S_func_00598de0 {
    char pad0[500];
    int m_x;
    int* f();
};

struct S_func_005f17a0 {
    int f(int a2, int a3);
};

int __stdcall func_005eecc0(char* a1, int a2, int a3)
{
    S_func_00598de0* p =
        a1 ? reinterpret_cast<S_func_00598de0*>(a1 - 20) : 0;
    int* result = p->f();
    return reinterpret_cast<S_func_005f17a0*>(result)->f(a2, a3);
}
