// from server: 100% by colin
extern int g_00a28120_1;
extern int g_00a28120_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a28120(void*);
struct O_00a28120 { int m(int, void*, void*, int); };
extern O_00a28120 g_obj_00a28120;
extern int g_tail_00a28120;
void func_00a28120()
{
    g_obj_00a28120.m(152, (void*)&g_00a28120_1, (void*)&g_00a28120_2, 0);
    tail_fn_00a28120(&g_tail_00a28120);
}