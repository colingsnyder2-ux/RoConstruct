// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbb30(void*, void*);
extern "C" void run_fn_009cbb30(void);
extern "C" void tail_fn_009cbb30(void*);
extern int g_a_009cbb30;
extern int g_b_009cbb30;
extern int g_c_009cbb30;

void func_009cbb30()
{
    init_fn_009cbb30(&g_a_009cbb30, &g_b_009cbb30);
    run_fn_009cbb30();
    tail_fn_009cbb30(&g_c_009cbb30);
}
