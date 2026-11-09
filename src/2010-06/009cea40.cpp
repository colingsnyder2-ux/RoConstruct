// from server: 100% by colin
extern int g_009cea40_1;
extern int g_009cea40_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009cea40(void*);
struct O_009cea40 { int m(int, void*, void*, int, int); };
extern O_009cea40 g_obj_009cea40;
extern int g_tail_009cea40;
void func_009cea40()
{
    g_obj_009cea40.m(360, (void*)&g_009cea40_1, (void*)&g_009cea40_2, 0, 1);
    tail_fn_009cea40(&g_tail_009cea40);
}