// from server: 100% by colin
extern int g_009c3670_0;
extern int g_009c3670_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c3670(void*);
struct O_009c3670 { int m(void*, void*, int, int, int); };
extern O_009c3670 g_obj_009c3670;
extern int g_tail_009c3670;
void func_009c3670()
{
    g_obj_009c3670.m((void*)&g_009c3670_0, (void*)&g_009c3670_1, 148, 15, 0);
    tail_fn_009c3670(&g_tail_009c3670);
}