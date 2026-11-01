// from server: 100% by colin
extern int g_009d6740_0;
extern int g_009d6740_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d6740(void*);
struct O_009d6740 { int m(void*, void*, int, int, int); };
extern O_009d6740 g_obj_009d6740;
extern int g_tail_009d6740;
void func_009d6740()
{
    g_obj_009d6740.m((void*)&g_009d6740_0, (void*)&g_009d6740_1, 404, 2, 0);
    tail_fn_009d6740(&g_tail_009d6740);
}