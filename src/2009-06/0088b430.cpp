// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_0088b430(void*, void*);
extern "C" void run_fn_0088b430(void);
extern "C" void tail_fn_0088b430(void*);
extern int g_a_0088b430;
extern int g_b_0088b430;
extern int g_c_0088b430;

void func_0088b430()
{
    init_fn_0088b430(&g_a_0088b430, &g_b_0088b430);
    run_fn_0088b430();
    tail_fn_0088b430(&g_c_0088b430);
}
