// from server: 100% by colin
extern int g_009cf300_0;
extern int g_009cf300_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009cf300(void*);
struct O_009cf300 { int m(void*, void*, int, int, int); };
extern O_009cf300 g_obj_009cf300;
extern int g_tail_009cf300;
void func_009cf300()
{
    g_obj_009cf300.m((void*)&g_009cf300_0, (void*)&g_009cf300_1, 296, 9, 2);
    tail_fn_009cf300(&g_tail_009cf300);
}