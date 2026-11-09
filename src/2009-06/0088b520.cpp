// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_0088b520(void*, void*);
extern "C" void run_fn_0088b520(void);
extern "C" void tail_fn_0088b520(void*);
extern int g_a_0088b520;
extern int g_b_0088b520;
extern int g_c_0088b520;

void func_0088b520()
{
    init_fn_0088b520(&g_a_0088b520, &g_b_0088b520);
    run_fn_0088b520();
    tail_fn_0088b520(&g_c_0088b520);
}
