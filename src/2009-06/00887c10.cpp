// from server: 100% by colin
extern int g_00887c10_0;
extern int g_00887c10_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00887c10(void*);
struct O_00887c10 { int m(void*, void*, int, int); };
extern O_00887c10 g_obj_00887c10;
extern int g_tail_00887c10;
void func_00887c10()
{
    g_obj_00887c10.m((void*)&g_00887c10_0, (void*)&g_00887c10_1, 280, 7);
    tail_fn_00887c10(&g_tail_00887c10);
}