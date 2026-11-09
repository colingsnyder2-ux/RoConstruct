// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_0088b220(void*, void*);
extern "C" void run_fn_0088b220(void);
extern "C" void tail_fn_0088b220(void*);
extern int g_a_0088b220;
extern int g_b_0088b220;
extern int g_c_0088b220;

void func_0088b220()
{
    init_fn_0088b220(&g_a_0088b220, &g_b_0088b220);
    run_fn_0088b220();
    tail_fn_0088b220(&g_c_0088b220);
}
