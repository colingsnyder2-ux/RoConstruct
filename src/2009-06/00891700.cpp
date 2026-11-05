// from server: 100% by colin
extern int g_00891700_0;
extern int g_00891700_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00891700(void*);
struct O_00891700 { int m(void*, void*, int, int); };
extern O_00891700 g_obj_00891700;
extern int g_tail_00891700;
void func_00891700()
{
    g_obj_00891700.m((void*)&g_00891700_0, (void*)&g_00891700_1, 356, 7);
    tail_fn_00891700(&g_tail_00891700);
}