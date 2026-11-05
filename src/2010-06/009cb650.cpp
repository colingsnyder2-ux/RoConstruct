// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cb650(void*, void*);
extern "C" void run_fn_009cb650(void);
extern "C" void tail_fn_009cb650(void*);
extern int g_a_009cb650;
extern int g_b_009cb650;
extern int g_c_009cb650;

void func_009cb650()
{
    init_fn_009cb650(&g_a_009cb650, &g_b_009cb650);
    run_fn_009cb650();
    tail_fn_009cb650(&g_c_009cb650);
}
