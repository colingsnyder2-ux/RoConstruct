// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00887a50(void*, void*);
extern "C" void run_fn_00887a50(void);
extern "C" void tail_fn_00887a50(void*);
extern int g_a_00887a50;
extern int g_b_00887a50;
extern int g_c_00887a50;

void func_00887a50()
{
    init_fn_00887a50(&g_a_00887a50, &g_b_00887a50);
    run_fn_00887a50();
    tail_fn_00887a50(&g_c_00887a50);
}
