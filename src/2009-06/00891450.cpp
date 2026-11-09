// from server: 100% by colin
extern int g_00891450_0;
extern int g_00891450_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00891450(void*);
struct O_00891450 { int m(void*, void*, int, int); };
extern O_00891450 g_obj_00891450;
extern int g_tail_00891450;
void func_00891450()
{
    g_obj_00891450.m((void*)&g_00891450_0, (void*)&g_00891450_1, 396, 7);
    tail_fn_00891450(&g_tail_00891450);
}