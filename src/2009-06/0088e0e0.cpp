// from server: 100% by colin
extern int g_0088e0e0_0;
extern int g_0088e0e0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088e0e0(void*);
struct O_0088e0e0 { int m(void*, void*, int, int); };
extern O_0088e0e0 g_obj_0088e0e0;
extern int g_tail_0088e0e0;
void func_0088e0e0()
{
    g_obj_0088e0e0.m((void*)&g_0088e0e0_0, (void*)&g_0088e0e0_1, 172, 7);
    tail_fn_0088e0e0(&g_tail_0088e0e0);
}