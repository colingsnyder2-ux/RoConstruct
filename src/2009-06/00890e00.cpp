// from server: 100% by colin
extern int g_00890e00_0;
extern int g_00890e00_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00890e00(void*);
struct O_00890e00 { int m(void*, void*, int, int); };
extern O_00890e00 g_obj_00890e00;
extern int g_tail_00890e00;
void func_00890e00()
{
    g_obj_00890e00.m((void*)&g_00890e00_0, (void*)&g_00890e00_1, 204, 7);
    tail_fn_00890e00(&g_tail_00890e00);
}