// from server: 100% by colin
extern int g_0076cf60_0;
extern int g_0076cf60_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0076cf60(void*);
struct O_0076cf60 { int m(void*, void*, int, int); };
extern O_0076cf60 g_obj_0076cf60;
extern int g_tail_0076cf60;
void func_0076cf60()
{
    g_obj_0076cf60.m((void*)&g_0076cf60_0, (void*)&g_0076cf60_1, 234, 5);
    tail_fn_0076cf60(&g_tail_0076cf60);
}