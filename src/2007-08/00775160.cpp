// from server: 100% by colin
extern int g_00775160_0;
extern int g_00775160_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775160(void*);
struct O_00775160 { int m(void*, void*, int, int); };
extern O_00775160 g_obj_00775160;
extern int g_tail_00775160;
void func_00775160()
{
    g_obj_00775160.m((void*)&g_00775160_0, (void*)&g_00775160_1, 272, 5);
    tail_fn_00775160(&g_tail_00775160);
}