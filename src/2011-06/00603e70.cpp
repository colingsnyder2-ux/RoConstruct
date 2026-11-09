// from server: 73% by atomic.potato
extern "C" void __cdecl CallTarget(int, const char *, const char *, int, int, int, int);

static char g_flag;
static const char g_arg1[] = ".?AV?$Named@VMouseCommand@RBX@@$E?sBoxSelectCommand@2@3QBDB@RBX@@";
static const char g_arg2[] = ".\\V8DataModel\\Commands.cpp";

struct S {
    void f(int);
};

void S::f(int)
{
    if (!g_flag)
        CallTarget(3, g_arg1, g_arg2, 0x4ff, 0, 0, 0);
    g_flag = 1;
}
