// from server: 100% by colin
extern int g_00a19c20_1;
extern int g_00a19c20_2;
extern int g_00a19c20_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a19c20(void*);
struct O_00a19c20 { int m(int, void*, void*, void*, int); };
extern O_00a19c20 g_obj_00a19c20;
extern int g_tail_00a19c20;
void func_00a19c20()
{
    g_obj_00a19c20.m(7424, (void*)&g_00a19c20_1, (void*)&g_00a19c20_2, (void*)&g_00a19c20_3, 0);
    tail_fn_00a19c20(&g_tail_00a19c20);
}