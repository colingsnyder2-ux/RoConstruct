// from server: 100% by colin
extern int g_00888030_0;
extern int g_00888030_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00888030(void*);
struct O_00888030 { int m(void*, void*, int, int); };
extern O_00888030 g_obj_00888030;
extern int g_tail_00888030;
void func_00888030()
{
    g_obj_00888030.m((void*)&g_00888030_0, (void*)&g_00888030_1, 160, 7);
    tail_fn_00888030(&g_tail_00888030);
}