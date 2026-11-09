// from server: 100% by colin
extern int g_009c2df0_0;
extern int g_009c2df0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c2df0(void*);
struct O_009c2df0 { int m(void*, void*, int, int, int); };
extern O_009c2df0 g_obj_009c2df0;
extern int g_tail_009c2df0;
void func_009c2df0()
{
    g_obj_009c2df0.m((void*)&g_009c2df0_0, (void*)&g_009c2df0_1, 152, 15, 0);
    tail_fn_009c2df0(&g_tail_009c2df0);
}