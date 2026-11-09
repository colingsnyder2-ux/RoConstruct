// from server: 100% by colin
extern int g_008897d0_0;
extern int g_008897d0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_008897d0(void*);
struct O_008897d0 { int m(void*, void*, int, int); };
extern O_008897d0 g_obj_008897d0;
extern int g_tail_008897d0;
void func_008897d0()
{
    g_obj_008897d0.m((void*)&g_008897d0_0, (void*)&g_008897d0_1, 152, 7);
    tail_fn_008897d0(&g_tail_008897d0);
}