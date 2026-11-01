// from server: 100% by colin
extern int g_009d5020_1;
extern int g_009d5020_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d5020(void*);
struct O_009d5020 { int m(int, void*, void*, int, int); };
extern O_009d5020 g_obj_009d5020;
extern int g_tail_009d5020;
void func_009d5020()
{
    g_obj_009d5020.m(152, (void*)&g_009d5020_1, (void*)&g_009d5020_2, 0, 1);
    tail_fn_009d5020(&g_tail_009d5020);
}