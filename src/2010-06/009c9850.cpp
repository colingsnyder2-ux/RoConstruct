// from server: 100% by colin
extern int g_009c9850_1;
extern int g_009c9850_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c9850(void*);
struct O_009c9850 { int m(int, void*, void*, int, int); };
extern O_009c9850 g_obj_009c9850;
extern int g_tail_009c9850;
void func_009c9850()
{
    g_obj_009c9850.m(120, (void*)&g_009c9850_1, (void*)&g_009c9850_2, 0, 1);
    tail_fn_009c9850(&g_tail_009c9850);
}