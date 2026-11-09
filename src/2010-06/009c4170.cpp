// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009c4170(void*, void*);
extern "C" void run_fn_009c4170(void);
extern "C" void tail_fn_009c4170(void*);
extern int g_a_009c4170;
extern int g_b_009c4170;
extern int g_c_009c4170;

void func_009c4170()
{
    init_fn_009c4170(&g_a_009c4170, &g_b_009c4170);
    run_fn_009c4170();
    tail_fn_009c4170(&g_c_009c4170);
}
