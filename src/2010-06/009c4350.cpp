// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009c4350(void*, void*);
extern "C" void run_fn_009c4350(void);
extern "C" void tail_fn_009c4350(void*);
extern int g_a_009c4350;
extern int g_b_009c4350;
extern int g_c_009c4350;

void func_009c4350()
{
    init_fn_009c4350(&g_a_009c4350, &g_b_009c4350);
    run_fn_009c4350();
    tail_fn_009c4350(&g_c_009c4350);
}
