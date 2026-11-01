// from server: 100% by colin
extern int g_00890f00_0;
extern int g_00890f00_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00890f00(void*);
struct O_00890f00 { int m(void*, void*, int, int); };
extern O_00890f00 g_obj_00890f00;
extern int g_tail_00890f00;
void func_00890f00()
{
    g_obj_00890f00.m((void*)&g_00890f00_0, (void*)&g_00890f00_1, 332, 7);
    tail_fn_00890f00(&g_tail_00890f00);
}