// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbe90(void*, void*);
extern "C" void run_fn_009cbe90(void);
extern "C" void tail_fn_009cbe90(void*);
extern int g_a_009cbe90;
extern int g_b_009cbe90;
extern int g_c_009cbe90;

void func_009cbe90()
{
    init_fn_009cbe90(&g_a_009cbe90, &g_b_009cbe90);
    run_fn_009cbe90();
    tail_fn_009cbe90(&g_c_009cbe90);
}
