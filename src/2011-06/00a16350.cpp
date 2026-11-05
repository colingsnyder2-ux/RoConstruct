// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a16350(void*, void*);
extern "C" void run_fn_00a16350(void);
extern "C" void tail_fn_00a16350(void*);
extern int g_a_00a16350;
extern int g_b_00a16350;
extern int g_c_00a16350;

void func_00a16350()
{
    init_fn_00a16350(&g_a_00a16350, &g_b_00a16350);
    run_fn_00a16350();
    tail_fn_00a16350(&g_c_00a16350);
}
