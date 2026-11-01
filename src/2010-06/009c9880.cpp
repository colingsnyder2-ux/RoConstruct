// from server: 100% by colin
extern int g_009c9880_1;
extern int g_009c9880_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c9880(void*);
struct O_009c9880 { int m(int, void*, void*, int, int); };
extern O_009c9880 g_obj_009c9880;
extern int g_tail_009c9880;
void func_009c9880()
{
    g_obj_009c9880.m(124, (void*)&g_009c9880_1, (void*)&g_009c9880_2, 0, 1);
    tail_fn_009c9880(&g_tail_009c9880);
}