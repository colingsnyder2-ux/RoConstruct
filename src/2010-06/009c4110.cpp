// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009c4110(void*, void*);
extern "C" void run_fn_009c4110(void);
extern "C" void tail_fn_009c4110(void*);
extern int g_a_009c4110;
extern int g_b_009c4110;
extern int g_c_009c4110;

void func_009c4110()
{
    init_fn_009c4110(&g_a_009c4110, &g_b_009c4110);
    run_fn_009c4110();
    tail_fn_009c4110(&g_c_009c4110);
}
