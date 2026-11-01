// from server: 100% by colin
extern int g_0076eb20_0;
extern int g_0076eb20_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0076eb20(void*);
struct O_0076eb20 { int m(void*, void*, int, int); };
extern O_0076eb20 g_obj_0076eb20;
extern int g_tail_0076eb20;
void func_0076eb20()
{
    g_obj_0076eb20.m((void*)&g_0076eb20_0, (void*)&g_0076eb20_1, 345, 4);
    tail_fn_0076eb20(&g_tail_0076eb20);
}