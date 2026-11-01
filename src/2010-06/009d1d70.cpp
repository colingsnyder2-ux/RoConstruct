// from server: 100% by colin
extern int g_009d1d70_0;
extern int g_009d1d70_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d1d70(void*);
struct O_009d1d70 { int m(void*, void*, int, int, int); };
extern O_009d1d70 g_obj_009d1d70;
extern int g_tail_009d1d70;
void func_009d1d70()
{
    g_obj_009d1d70.m((void*)&g_009d1d70_0, (void*)&g_009d1d70_1, 788, 2, 0);
    tail_fn_009d1d70(&g_tail_009d1d70);
}