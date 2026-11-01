// from server: 100% by colin
extern int g_00770720_0;
extern int g_00770720_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00770720(void*);
struct O_00770720 { int m(void*, void*, int, int); };
extern O_00770720 g_obj_00770720;
extern int g_tail_00770720;
void func_00770720()
{
    g_obj_00770720.m((void*)&g_00770720_0, (void*)&g_00770720_1, 272, 5);
    tail_fn_00770720(&g_tail_00770720);
}