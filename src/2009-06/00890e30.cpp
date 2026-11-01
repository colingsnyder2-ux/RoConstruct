// from server: 100% by colin
extern int g_00890e30_0;
extern int g_00890e30_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00890e30(void*);
struct O_00890e30 { int m(void*, void*, int, int); };
extern O_00890e30 g_obj_00890e30;
extern int g_tail_00890e30;
void func_00890e30()
{
    g_obj_00890e30.m((void*)&g_00890e30_0, (void*)&g_00890e30_1, 236, 7);
    tail_fn_00890e30(&g_tail_00890e30);
}