// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00885280(void*, void*);
extern "C" void run_fn_00885280(void);
extern "C" void tail_fn_00885280(void*);
extern int g_a_00885280;
extern int g_b_00885280;
extern int g_c_00885280;

void func_00885280()
{
    init_fn_00885280(&g_a_00885280, &g_b_00885280);
    run_fn_00885280();
    tail_fn_00885280(&g_c_00885280);
}
