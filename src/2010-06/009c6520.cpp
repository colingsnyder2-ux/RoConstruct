// from server: 100% by colin
extern int g_009c6520_1;
extern int g_009c6520_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c6520(void*);
struct O_009c6520 { int m(int, void*, void*, int, int); };
extern O_009c6520 g_obj_009c6520;
extern int g_tail_009c6520;
void func_009c6520()
{
    g_obj_009c6520.m(300, (void*)&g_009c6520_1, (void*)&g_009c6520_2, 0, 1);
    tail_fn_009c6520(&g_tail_009c6520);
}