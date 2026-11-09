// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc490(void*, void*);
extern "C" void run_fn_009cc490(void);
extern "C" void tail_fn_009cc490(void*);
extern int g_a_009cc490;
extern int g_b_009cc490;
extern int g_c_009cc490;

void func_009cc490()
{
    init_fn_009cc490(&g_a_009cc490, &g_b_009cc490);
    run_fn_009cc490();
    tail_fn_009cc490(&g_c_009cc490);
}
