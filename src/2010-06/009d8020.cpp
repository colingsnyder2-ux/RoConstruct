// from server: 100% by colin
extern int g_009d8020_1;
extern int g_009d8020_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d8020(void*);
struct O_009d8020 { int m(int, void*, void*, int, int); };
extern O_009d8020 g_obj_009d8020;
extern int g_tail_009d8020;
void func_009d8020()
{
    g_obj_009d8020.m(228, (void*)&g_009d8020_1, (void*)&g_009d8020_2, 0, 1);
    tail_fn_009d8020(&g_tail_009d8020);
}