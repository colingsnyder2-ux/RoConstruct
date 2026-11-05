// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00887ab0(void*, void*);
extern "C" void run_fn_00887ab0(void);
extern "C" void tail_fn_00887ab0(void*);
extern int g_a_00887ab0;
extern int g_b_00887ab0;
extern int g_c_00887ab0;

void func_00887ab0()
{
    init_fn_00887ab0(&g_a_00887ab0, &g_b_00887ab0);
    run_fn_00887ab0();
    tail_fn_00887ab0(&g_c_00887ab0);
}
