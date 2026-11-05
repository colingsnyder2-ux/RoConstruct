// from server: 100% by colin
extern int g_007ef310_0;
extern int g_007ef310_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007ef310(void*);
struct O_007ef310 { int m(void*, void*, int, int); };
extern O_007ef310 g_obj_007ef310;
extern int g_tail_007ef310;
void func_007ef310()
{
    g_obj_007ef310.m((void*)&g_007ef310_0, (void*)&g_007ef310_1, 304, 5);
    tail_fn_007ef310(&g_tail_007ef310);
}