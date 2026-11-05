// from server: 100% by colin
extern int g_00a19510_0;
extern int g_00a19510_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a19510(void*);
struct O_00a19510 { int m(void*, void*, int, int, int); };
extern O_00a19510 g_obj_00a19510;
extern int g_tail_00a19510;
void func_00a19510()
{
    g_obj_00a19510.m((void*)&g_00a19510_0, (void*)&g_00a19510_1, 154, 31, 0);
    tail_fn_00a19510(&g_tail_00a19510);
}