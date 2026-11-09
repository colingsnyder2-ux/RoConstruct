// from server: 100% by colin
extern int g_00775340_0;
extern int g_00775340_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00775340(void*);
struct O_00775340 { int m(void*, void*, int, int); };
extern O_00775340 g_obj_00775340;
extern int g_tail_00775340;
void func_00775340()
{
    g_obj_00775340.m((void*)&g_00775340_0, (void*)&g_00775340_1, 284, 5);
    tail_fn_00775340(&g_tail_00775340);
}