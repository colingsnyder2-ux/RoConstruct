// from server: 100% by colin
extern int g_00a19a50_1;
extern int g_00a19a50_2;
extern int g_00a19a50_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a19a50(void*);
struct O_00a19a50 { int m(int, void*, void*, void*, int); };
extern O_00a19a50 g_obj_00a19a50;
extern int g_tail_00a19a50;
void func_00a19a50()
{
    g_obj_00a19a50.m(352, (void*)&g_00a19a50_1, (void*)&g_00a19a50_2, (void*)&g_00a19a50_3, 0);
    tail_fn_00a19a50(&g_tail_00a19a50);
}