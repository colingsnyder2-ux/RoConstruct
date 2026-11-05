// from server: 100% by colin
extern int g_0076f690_0;
extern int g_0076f690_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0076f690(void*);
struct O_0076f690 { int m(void*, void*, int, int); };
extern O_0076f690 g_obj_0076f690;
extern int g_tail_0076f690;
void func_0076f690()
{
    g_obj_0076f690.m((void*)&g_0076f690_0, (void*)&g_0076f690_1, 264, 5);
    tail_fn_0076f690(&g_tail_0076f690);
}