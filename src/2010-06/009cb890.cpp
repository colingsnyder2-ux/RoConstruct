// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cb890(void*, void*);
extern "C" void run_fn_009cb890(void);
extern "C" void tail_fn_009cb890(void*);
extern int g_a_009cb890;
extern int g_b_009cb890;
extern int g_c_009cb890;

void func_009cb890()
{
    init_fn_009cb890(&g_a_009cb890, &g_b_009cb890);
    run_fn_009cb890();
    tail_fn_009cb890(&g_c_009cb890);
}
