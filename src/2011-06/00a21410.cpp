// from server: 100% by colin
extern int g_00a21410_1;
extern int g_00a21410_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a21410(void*);
struct O_00a21410 { int m(int, void*, void*, int); };
extern O_00a21410 g_obj_00a21410;
extern int g_tail_00a21410;
void func_00a21410()
{
    g_obj_00a21410.m(184, (void*)&g_00a21410_1, (void*)&g_00a21410_2, 0);
    tail_fn_00a21410(&g_tail_00a21410);
}