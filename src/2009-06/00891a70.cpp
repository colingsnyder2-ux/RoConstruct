// from server: 100% by colin
extern int g_00891a70_0;
extern int g_00891a70_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00891a70(void*);
struct O_00891a70 { int m(void*, void*, int, int); };
extern O_00891a70 g_obj_00891a70;
extern int g_tail_00891a70;
void func_00891a70()
{
    g_obj_00891a70.m((void*)&g_00891a70_0, (void*)&g_00891a70_1, 160, 7);
    tail_fn_00891a70(&g_tail_00891a70);
}