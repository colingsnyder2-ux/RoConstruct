// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc280(void*, void*);
extern "C" void run_fn_009cc280(void);
extern "C" void tail_fn_009cc280(void*);
extern int g_a_009cc280;
extern int g_b_009cc280;
extern int g_c_009cc280;

void func_009cc280()
{
    init_fn_009cc280(&g_a_009cc280, &g_b_009cc280);
    run_fn_009cc280();
    tail_fn_009cc280(&g_c_009cc280);
}
