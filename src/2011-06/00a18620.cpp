// from server: 100% by colin
extern int g_00a18620_1;
extern int g_00a18620_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a18620(void*);
struct O_00a18620 { int m(int, void*, void*, int); };
extern O_00a18620 g_obj_00a18620;
extern int g_tail_00a18620;
void func_00a18620()
{
    g_obj_00a18620.m(528, (void*)&g_00a18620_1, (void*)&g_00a18620_2, 2);
    tail_fn_00a18620(&g_tail_00a18620);
}