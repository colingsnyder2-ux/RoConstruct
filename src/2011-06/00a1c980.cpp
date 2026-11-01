// from server: 100% by colin
extern int g_00a1c980_1;
extern int g_00a1c980_2;
extern int g_00a1c980_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a1c980(void*);
struct O_00a1c980 { int m(int, void*, void*, void*, int); };
extern O_00a1c980 g_obj_00a1c980;
extern int g_tail_00a1c980;
void func_00a1c980()
{
    g_obj_00a1c980.m(212, (void*)&g_00a1c980_1, (void*)&g_00a1c980_2, (void*)&g_00a1c980_3, 0);
    tail_fn_00a1c980(&g_tail_00a1c980);
}