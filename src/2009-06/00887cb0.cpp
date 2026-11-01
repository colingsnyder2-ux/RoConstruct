// from server: 100% by colin
extern int g_00887cb0_1;
extern int g_00887cb0_2;
extern int g_00887cb0_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00887cb0(void*);
struct O_00887cb0 { int m(int, void*, void*, void*); };
extern O_00887cb0 g_obj_00887cb0;
extern int g_tail_00887cb0;
void func_00887cb0()
{
    g_obj_00887cb0.m(308, (void*)&g_00887cb0_1, (void*)&g_00887cb0_2, (void*)&g_00887cb0_3);
    tail_fn_00887cb0(&g_tail_00887cb0);
}