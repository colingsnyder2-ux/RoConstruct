// from server: 100% by colin
extern int g_009d3b20_1;
extern int g_009d3b20_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d3b20(void*);
struct O_009d3b20 { int m(int, void*, void*, int, int); };
extern O_009d3b20 g_obj_009d3b20;
extern int g_tail_009d3b20;
void func_009d3b20()
{
    g_obj_009d3b20.m(572, (void*)&g_009d3b20_1, (void*)&g_009d3b20_2, 0, 1);
    tail_fn_009d3b20(&g_tail_009d3b20);
}