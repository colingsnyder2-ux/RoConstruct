// from server: 100% by colin
extern int g_00a19570_0;
extern int g_00a19570_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a19570(void*);
struct O_00a19570 { int m(void*, void*, int, int, int); };
extern O_00a19570 g_obj_00a19570;
extern int g_tail_00a19570;
void func_00a19570()
{
    g_obj_00a19570.m((void*)&g_00a19570_0, (void*)&g_00a19570_1, 150, 31, 0);
    tail_fn_00a19570(&g_tail_00a19570);
}