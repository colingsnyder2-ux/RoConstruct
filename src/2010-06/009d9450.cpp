// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009d9450(void*, void*);
extern "C" void run_fn_009d9450(void);
extern "C" void tail_fn_009d9450(void*);
extern int g_a_009d9450;
extern int g_b_009d9450;
extern int g_c_009d9450;

void func_009d9450()
{
    init_fn_009d9450(&g_a_009d9450, &g_b_009d9450);
    run_fn_009d9450();
    tail_fn_009d9450(&g_c_009d9450);
}
