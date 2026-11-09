// from server: 100% by colin
extern int g_009c7a00_0;
extern int g_009c7a00_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c7a00(void*);
struct O_009c7a00 { int m(void*, void*, int, int, int); };
extern O_009c7a00 g_obj_009c7a00;
extern int g_tail_009c7a00;
void func_009c7a00()
{
    g_obj_009c7a00.m((void*)&g_009c7a00_0, (void*)&g_009c7a00_1, 208, 15, 0);
    tail_fn_009c7a00(&g_tail_009c7a00);
}