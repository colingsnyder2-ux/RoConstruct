// from server: 100% by colin
extern int g_00a19120_0;
extern int g_00a19120_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a19120(void*);
struct O_00a19120 { int m(void*, void*, int, int, int); };
extern O_00a19120 g_obj_00a19120;
extern int g_tail_00a19120;
void func_00a19120()
{
    g_obj_00a19120.m((void*)&g_00a19120_0, (void*)&g_00a19120_1, 288, 31, 0);
    tail_fn_00a19120(&g_tail_00a19120);
}