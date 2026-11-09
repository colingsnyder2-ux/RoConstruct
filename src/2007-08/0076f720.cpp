// from server: 100% by colin
extern int g_0076f720_0;
extern int g_0076f720_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0076f720(void*);
struct O_0076f720 { int m(void*, void*, int, int); };
extern O_0076f720 g_obj_0076f720;
extern int g_tail_0076f720;
void func_0076f720()
{
    g_obj_0076f720.m((void*)&g_0076f720_0, (void*)&g_0076f720_1, 252, 5);
    tail_fn_0076f720(&g_tail_0076f720);
}