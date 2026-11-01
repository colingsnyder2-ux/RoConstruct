// from server: 100% by colin
extern int g_00891610_0;
extern int g_00891610_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00891610(void*);
struct O_00891610 { int m(void*, void*, int, int); };
extern O_00891610 g_obj_00891610;
extern int g_tail_00891610;
void func_00891610()
{
    g_obj_00891610.m((void*)&g_00891610_0, (void*)&g_00891610_1, 344, 7);
    tail_fn_00891610(&g_tail_00891610);
}