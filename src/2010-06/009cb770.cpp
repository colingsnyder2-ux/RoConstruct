// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cb770(void*, void*);
extern "C" void run_fn_009cb770(void);
extern "C" void tail_fn_009cb770(void*);
extern int g_a_009cb770;
extern int g_b_009cb770;
extern int g_c_009cb770;

void func_009cb770()
{
    init_fn_009cb770(&g_a_009cb770, &g_b_009cb770);
    run_fn_009cb770();
    tail_fn_009cb770(&g_c_009cb770);
}
