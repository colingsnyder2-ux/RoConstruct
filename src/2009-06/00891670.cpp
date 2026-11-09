// from server: 100% by colin
extern int g_00891670_0;
extern int g_00891670_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00891670(void*);
struct O_00891670 { int m(void*, void*, int, int); };
extern O_00891670 g_obj_00891670;
extern int g_tail_00891670;
void func_00891670()
{
    g_obj_00891670.m((void*)&g_00891670_0, (void*)&g_00891670_1, 336, 7);
    tail_fn_00891670(&g_tail_00891670);
}