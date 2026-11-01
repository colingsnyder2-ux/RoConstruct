// from server: 100% by colin
extern int g_009c9420_0;
extern int g_009c9420_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c9420(void*);
struct O_009c9420 { int m(void*, void*, int, int, int); };
extern O_009c9420 g_obj_009c9420;
extern int g_tail_009c9420;
void func_009c9420()
{
    g_obj_009c9420.m((void*)&g_009c9420_0, (void*)&g_009c9420_1, 166, 15, 0);
    tail_fn_009c9420(&g_tail_009c9420);
}