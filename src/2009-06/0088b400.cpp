// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_0088b400(void*, void*);
extern "C" void run_fn_0088b400(void);
extern "C" void tail_fn_0088b400(void*);
extern int g_a_0088b400;
extern int g_b_0088b400;
extern int g_c_0088b400;

void func_0088b400()
{
    init_fn_0088b400(&g_a_0088b400, &g_b_0088b400);
    run_fn_0088b400();
    tail_fn_0088b400(&g_c_0088b400);
}
