// from server: 100% by colin
extern int g_008870a0_0;
extern int g_008870a0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_008870a0(void*);
struct O_008870a0 { int m(void*, void*, int, int); };
extern O_008870a0 g_obj_008870a0;
extern int g_tail_008870a0;
void func_008870a0()
{
    g_obj_008870a0.m((void*)&g_008870a0_0, (void*)&g_008870a0_1, 204, 2);
    tail_fn_008870a0(&g_tail_008870a0);
}