// from server: 100% by colin
extern int g_009ceb10_0;
extern int g_009ceb10_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009ceb10(void*);
struct O_009ceb10 { int m(void*, void*, int, int, int); };
extern O_009ceb10 g_obj_009ceb10;
extern int g_tail_009ceb10;
void func_009ceb10()
{
    g_obj_009ceb10.m((void*)&g_009ceb10_0, (void*)&g_009ceb10_1, 376, 2, 0);
    tail_fn_009ceb10(&g_tail_009ceb10);
}