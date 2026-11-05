// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00892940(void*, void*);
extern "C" void run_fn_00892940(void);
extern "C" void tail_fn_00892940(void*);
extern int g_a_00892940;
extern int g_b_00892940;
extern int g_c_00892940;

void func_00892940()
{
    init_fn_00892940(&g_a_00892940, &g_b_00892940);
    run_fn_00892940();
    tail_fn_00892940(&g_c_00892940);
}
