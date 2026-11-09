// from server: 100% by colin
extern int g_00891880_0;
extern int g_00891880_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00891880(void*);
struct O_00891880 { int m(void*, void*, int, int); };
extern O_00891880 g_obj_00891880;
extern int g_tail_00891880;
void func_00891880()
{
    g_obj_00891880.m((void*)&g_00891880_0, (void*)&g_00891880_1, 336, 7);
    tail_fn_00891880(&g_tail_00891880);
}