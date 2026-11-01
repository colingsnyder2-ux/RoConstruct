// from server: 100% by colin
extern int g_00a17c90_0;
extern int g_00a17c90_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a17c90(void*);
struct O_00a17c90 { int m(void*, void*, int, int, int); };
extern O_00a17c90 g_obj_00a17c90;
extern int g_tail_00a17c90;
void func_00a17c90()
{
    g_obj_00a17c90.m((void*)&g_00a17c90_0, (void*)&g_00a17c90_1, 212, 2, 0);
    tail_fn_00a17c90(&g_tail_00a17c90);
}