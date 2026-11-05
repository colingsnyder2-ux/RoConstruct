// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00885310(void*, void*);
extern "C" void run_fn_00885310(void);
extern "C" void tail_fn_00885310(void*);
extern int g_a_00885310;
extern int g_b_00885310;
extern int g_c_00885310;

void func_00885310()
{
    init_fn_00885310(&g_a_00885310, &g_b_00885310);
    run_fn_00885310();
    tail_fn_00885310(&g_c_00885310);
}
