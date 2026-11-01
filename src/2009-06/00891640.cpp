// from server: 100% by colin
extern int g_00891640_0;
extern int g_00891640_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00891640(void*);
struct O_00891640 { int m(void*, void*, int, int); };
extern O_00891640 g_obj_00891640;
extern int g_tail_00891640;
void func_00891640()
{
    g_obj_00891640.m((void*)&g_00891640_0, (void*)&g_00891640_1, 356, 7);
    tail_fn_00891640(&g_tail_00891640);
}