// from server: 100% by colin
extern int g_00a1c820_1;
extern int g_00a1c820_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a1c820(void*);
struct O_00a1c820 { int m(int, void*, void*, int); };
extern O_00a1c820 g_obj_00a1c820;
extern int g_tail_00a1c820;
void func_00a1c820()
{
    g_obj_00a1c820.m(116, (void*)&g_00a1c820_1, (void*)&g_00a1c820_2, 0);
    tail_fn_00a1c820(&g_tail_00a1c820);
}