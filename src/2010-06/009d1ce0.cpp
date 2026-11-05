// from server: 100% by colin
extern int g_009d1ce0_0;
extern int g_009d1ce0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d1ce0(void*);
struct O_009d1ce0 { int m(void*, void*, int, int, int); };
extern O_009d1ce0 g_obj_009d1ce0;
extern int g_tail_009d1ce0;
void func_009d1ce0()
{
    g_obj_009d1ce0.m((void*)&g_009d1ce0_0, (void*)&g_009d1ce0_1, 668, 2, 0);
    tail_fn_009d1ce0(&g_tail_009d1ce0);
}