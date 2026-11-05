// from server: 100% by colin
extern int g_00775640_0;
extern int g_00775640_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775640(void*);
struct O_00775640 { int m(void*, void*, int, int); };
extern O_00775640 g_obj_00775640;
extern int g_tail_00775640;
void func_00775640()
{
    g_obj_00775640.m((void*)&g_00775640_0, (void*)&g_00775640_1, 260, 5);
    tail_fn_00775640(&g_tail_00775640);
}