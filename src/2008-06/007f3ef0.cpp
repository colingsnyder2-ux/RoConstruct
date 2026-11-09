// from server: 100% by atomic.potato
struct A_func_007f3ef0 { int a; int b; int c; };
struct T_func_007f3ef0 { void m(A_func_007f3ef0 st, int p1, int p2, int p3); };
extern "C" int __cdecl func_6a17af(void (__cdecl*)(void));
extern T_func_007f3ef0 G_func_007f3ef0_obj;

static void __cdecl dtor_func_007f3ef0(void) {}

void func_007f3ef0(void)
{
    A_func_007f3ef0 st;
    st.a = 0x608960;
    st.b = 0;
    st.c = 0;
    G_func_007f3ef0_obj.m(st, 0x831048, 0x83103c, 0);
    func_6a17af(&dtor_func_007f3ef0);
}
