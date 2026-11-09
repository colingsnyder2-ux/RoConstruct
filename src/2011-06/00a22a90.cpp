// from server: 100% by colin
extern int g_00a22a90_0;
extern int g_00a22a90_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a22a90(void*);
struct O_00a22a90 { int m(void*, void*, int, int, int); };
extern O_00a22a90 g_obj_00a22a90;
extern int g_tail_00a22a90;
void func_00a22a90()
{
    g_obj_00a22a90.m((void*)&g_00a22a90_0, (void*)&g_00a22a90_1, 288, 21, 3);
    tail_fn_00a22a90(&g_tail_00a22a90);
}