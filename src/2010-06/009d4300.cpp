// from server: 100% by colin
extern int g_009d4300_0;
extern int g_009d4300_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d4300(void*);
struct O_009d4300 { int m(void*, void*, int, int, int); };
extern O_009d4300 g_obj_009d4300;
extern int g_tail_009d4300;
void func_009d4300()
{
    g_obj_009d4300.m((void*)&g_009d4300_0, (void*)&g_009d4300_1, 340, 15, 0);
    tail_fn_009d4300(&g_tail_009d4300);
}