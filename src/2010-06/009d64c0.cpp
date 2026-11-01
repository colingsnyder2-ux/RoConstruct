// from server: 100% by colin
extern int g_009d64c0_0;
extern int g_009d64c0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d64c0(void*);
struct O_009d64c0 { int m(void*, void*, int, int, int); };
extern O_009d64c0 g_obj_009d64c0;
extern int g_tail_009d64c0;
void func_009d64c0()
{
    g_obj_009d64c0.m((void*)&g_009d64c0_0, (void*)&g_009d64c0_1, 404, 2, 0);
    tail_fn_009d64c0(&g_tail_009d64c0);
}