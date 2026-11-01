// from server: 100% by colin
extern int g_00887d90_0;
extern int g_00887d90_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00887d90(void*);
struct O_00887d90 { int m(void*, void*, int, int); };
extern O_00887d90 g_obj_00887d90;
extern int g_tail_00887d90;
void func_00887d90()
{
    g_obj_00887d90.m((void*)&g_00887d90_0, (void*)&g_00887d90_1, 164, 7);
    tail_fn_00887d90(&g_tail_00887d90);
}