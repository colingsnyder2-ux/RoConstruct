// from server: 100% by colin
extern int g_00890dd0_0;
extern int g_00890dd0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00890dd0(void*);
struct O_00890dd0 { int m(void*, void*, int, int); };
extern O_00890dd0 g_obj_00890dd0;
extern int g_tail_00890dd0;
void func_00890dd0()
{
    g_obj_00890dd0.m((void*)&g_00890dd0_0, (void*)&g_00890dd0_1, 172, 7);
    tail_fn_00890dd0(&g_tail_00890dd0);
}