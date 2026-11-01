// from server: 100% by colin
extern int g_007f5450_0;
extern int g_007f5450_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f5450(void*);
struct O_007f5450 { int m(void*, void*, int, int); };
extern O_007f5450 g_obj_007f5450;
extern int g_tail_007f5450;
void func_007f5450()
{
    g_obj_007f5450.m((void*)&g_007f5450_0, (void*)&g_007f5450_1, 356, 5);
    tail_fn_007f5450(&g_tail_007f5450);
}