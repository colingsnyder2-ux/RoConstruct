// from server: 100% by colin
extern int g_009c9130_0;
extern int g_009c9130_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c9130(void*);
struct O_009c9130 { int m(void*, void*, int, int, int); };
extern O_009c9130 g_obj_009c9130;
extern int g_tail_009c9130;
void func_009c9130()
{
    g_obj_009c9130.m((void*)&g_009c9130_0, (void*)&g_009c9130_1, 152, 15, 0);
    tail_fn_009c9130(&g_tail_009c9130);
}