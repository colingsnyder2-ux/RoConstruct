// from server: 100% by colin
extern int g_00887d10_1;
extern int g_00887d10_2;
extern int g_00887d10_3;
extern int g_00887d10_4;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00887d10(void*);
struct O_00887d10 { int m(int, void*, void*, void*, void*); };
extern O_00887d10 g_obj_00887d10;
extern int g_tail_00887d10;
void func_00887d10()
{
    g_obj_00887d10.m(312, (void*)&g_00887d10_1, (void*)&g_00887d10_2, (void*)&g_00887d10_3, (void*)&g_00887d10_4);
    tail_fn_00887d10(&g_tail_00887d10);
}