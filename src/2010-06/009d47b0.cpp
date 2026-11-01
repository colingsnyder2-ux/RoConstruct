// from server: 100% by colin
extern int g_009d47b0_0;
extern int g_009d47b0_1;
extern int g_009d47b0_2;
extern int g_009d47b0_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d47b0(void*);
struct O_009d47b0 { int m(void*, void*, void*, void*, int); };
extern O_009d47b0 g_obj_009d47b0;
extern int g_tail_009d47b0;
void func_009d47b0()
{
    g_obj_009d47b0.m((void*)&g_009d47b0_0, (void*)&g_009d47b0_1, (void*)&g_009d47b0_2, (void*)&g_009d47b0_3, 15);
    tail_fn_009d47b0(&g_tail_009d47b0);
}