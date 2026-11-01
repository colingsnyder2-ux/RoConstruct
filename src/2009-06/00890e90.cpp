// from server: 100% by colin
extern int g_00890e90_0;
extern int g_00890e90_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00890e90(void*);
struct O_00890e90 { int m(void*, void*, int, int); };
extern O_00890e90 g_obj_00890e90;
extern int g_tail_00890e90;
void func_00890e90()
{
    g_obj_00890e90.m((void*)&g_00890e90_0, (void*)&g_00890e90_1, 300, 7);
    tail_fn_00890e90(&g_tail_00890e90);
}