// from server: 100% by colin
extern int g_00772d40_0;
extern int g_00772d40_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00772d40(void*);
struct O_00772d40 { int m(void*, void*, int, int); };
extern O_00772d40 g_obj_00772d40;
extern int g_tail_00772d40;
void func_00772d40()
{
    g_obj_00772d40.m((void*)&g_00772d40_0, (void*)&g_00772d40_1, 284, 5);
    tail_fn_00772d40(&g_tail_00772d40);
}