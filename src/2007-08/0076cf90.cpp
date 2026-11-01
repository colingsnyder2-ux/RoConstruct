// from server: 100% by colin
extern int g_0076cf90_0;
extern int g_0076cf90_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0076cf90(void*);
struct O_0076cf90 { int m(void*, void*, int, int); };
extern O_0076cf90 g_obj_0076cf90;
extern int g_tail_0076cf90;
void func_0076cf90()
{
    g_obj_0076cf90.m((void*)&g_0076cf90_0, (void*)&g_0076cf90_1, 236, 5);
    tail_fn_0076cf90(&g_tail_0076cf90);
}