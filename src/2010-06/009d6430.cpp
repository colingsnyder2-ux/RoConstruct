// from server: 100% by colin
extern int g_009d6430_0;
extern int g_009d6430_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d6430(void*);
struct O_009d6430 { int m(void*, void*, int, int, int); };
extern O_009d6430 g_obj_009d6430;
extern int g_tail_009d6430;
void func_009d6430()
{
    g_obj_009d6430.m((void*)&g_009d6430_0, (void*)&g_009d6430_1, 284, 2, 0);
    tail_fn_009d6430(&g_tail_009d6430);
}