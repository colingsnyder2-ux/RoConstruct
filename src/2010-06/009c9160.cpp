// from server: 100% by colin
extern int g_009c9160_0;
extern int g_009c9160_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c9160(void*);
struct O_009c9160 { int m(void*, void*, int, int, int); };
extern O_009c9160 g_obj_009c9160;
extern int g_tail_009c9160;
void func_009c9160()
{
    g_obj_009c9160.m((void*)&g_009c9160_0, (void*)&g_009c9160_1, 164, 15, 0);
    tail_fn_009c9160(&g_tail_009c9160);
}