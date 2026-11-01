// from server: 100% by colin
extern int g_009d47e0_0;
extern int g_009d47e0_1;
extern int g_009d47e0_2;
extern int g_009d47e0_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d47e0(void*);
struct O_009d47e0 { int m(void*, void*, void*, void*, int); };
extern O_009d47e0 g_obj_009d47e0;
extern int g_tail_009d47e0;
void func_009d47e0()
{
    g_obj_009d47e0.m((void*)&g_009d47e0_0, (void*)&g_009d47e0_1, (void*)&g_009d47e0_2, (void*)&g_009d47e0_3, 15);
    tail_fn_009d47e0(&g_tail_009d47e0);
}