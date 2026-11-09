// from server: 100% by colin
extern int g_0088c200_1;
extern int g_0088c200_2;
extern int g_0088c200_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088c200(void*);
struct O_0088c200 { int m(int, void*, void*, void*); };
extern O_0088c200 g_obj_0088c200;
extern int g_tail_0088c200;
void func_0088c200()
{
    g_obj_0088c200.m(736, (void*)&g_0088c200_1, (void*)&g_0088c200_2, (void*)&g_0088c200_3);
    tail_fn_0088c200(&g_tail_0088c200);
}