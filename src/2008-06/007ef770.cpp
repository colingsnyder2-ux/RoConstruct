// from server: 100% by colin
extern int g_007ef770_0;
extern int g_007ef770_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007ef770(void*);
struct O_007ef770 { int m(void*, void*, int, int); };
extern O_007ef770 g_obj_007ef770;
extern int g_tail_007ef770;
void func_007ef770()
{
    g_obj_007ef770.m((void*)&g_007ef770_0, (void*)&g_007ef770_1, 340, 5);
    tail_fn_007ef770(&g_tail_007ef770);
}