// from server: 100% by colin
extern int g_009d5570_0;
extern int g_009d5570_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d5570(void*);
struct O_009d5570 { int m(void*, void*, int, int, int); };
extern O_009d5570 g_obj_009d5570;
extern int g_tail_009d5570;
void func_009d5570()
{
    g_obj_009d5570.m((void*)&g_009d5570_0, (void*)&g_009d5570_1, 348, 15, 0);
    tail_fn_009d5570(&g_tail_009d5570);
}