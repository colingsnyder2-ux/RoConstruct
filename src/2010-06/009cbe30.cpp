// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbe30(void*, void*);
extern "C" void run_fn_009cbe30(void);
extern "C" void tail_fn_009cbe30(void*);
extern int g_a_009cbe30;
extern int g_b_009cbe30;
extern int g_c_009cbe30;

void func_009cbe30()
{
    init_fn_009cbe30(&g_a_009cbe30, &g_b_009cbe30);
    run_fn_009cbe30();
    tail_fn_009cbe30(&g_c_009cbe30);
}
