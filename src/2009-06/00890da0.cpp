// from server: 100% by colin
extern int g_00890da0_0;
extern int g_00890da0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00890da0(void*);
struct O_00890da0 { int m(void*, void*, int, int); };
extern O_00890da0 g_obj_00890da0;
extern int g_tail_00890da0;
void func_00890da0()
{
    g_obj_00890da0.m((void*)&g_00890da0_0, (void*)&g_00890da0_1, 140, 7);
    tail_fn_00890da0(&g_tail_00890da0);
}