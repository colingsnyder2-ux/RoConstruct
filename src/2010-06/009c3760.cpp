// from server: 100% by colin
extern int g_009c3760_0;
extern int g_009c3760_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c3760(void*);
struct O_009c3760 { int m(void*, void*, int, int, int); };
extern O_009c3760 g_obj_009c3760;
extern int g_tail_009c3760;
void func_009c3760()
{
    g_obj_009c3760.m((void*)&g_009c3760_0, (void*)&g_009c3760_1, 184, 15, 0);
    tail_fn_009c3760(&g_tail_009c3760);
}