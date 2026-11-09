// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc160(void*, void*);
extern "C" void run_fn_009cc160(void);
extern "C" void tail_fn_009cc160(void*);
extern int g_a_009cc160;
extern int g_b_009cc160;
extern int g_c_009cc160;

void func_009cc160()
{
    init_fn_009cc160(&g_a_009cc160, &g_b_009cc160);
    run_fn_009cc160();
    tail_fn_009cc160(&g_c_009cc160);
}
