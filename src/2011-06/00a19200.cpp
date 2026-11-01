// from server: 100% by colin
extern int g_00a19200_1;
extern int g_00a19200_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a19200(void*);
struct O_00a19200 { int m(int, void*, void*, int); };
extern O_00a19200 g_obj_00a19200;
extern int g_tail_00a19200;
void func_00a19200()
{
    g_obj_00a19200.m(328, (void*)&g_00a19200_1, (void*)&g_00a19200_2, 0);
    tail_fn_00a19200(&g_tail_00a19200);
}