// from server: 100% by colin
extern int g_00a19680_0;
extern int g_00a19680_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a19680(void*);
struct O_00a19680 { int m(void*, void*, int, int, int); };
extern O_00a19680 g_obj_00a19680;
extern int g_tail_00a19680;
void func_00a19680()
{
    g_obj_00a19680.m((void*)&g_00a19680_0, (void*)&g_00a19680_1, 192, 31, 0);
    tail_fn_00a19680(&g_tail_00a19680);
}