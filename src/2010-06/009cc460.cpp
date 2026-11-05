// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc460(void*, void*);
extern "C" void run_fn_009cc460(void);
extern "C" void tail_fn_009cc460(void*);
extern int g_a_009cc460;
extern int g_b_009cc460;
extern int g_c_009cc460;

void func_009cc460()
{
    init_fn_009cc460(&g_a_009cc460, &g_b_009cc460);
    run_fn_009cc460();
    tail_fn_009cc460(&g_c_009cc460);
}
