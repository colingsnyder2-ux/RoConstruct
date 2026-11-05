// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00885370(void*, void*);
extern "C" void run_fn_00885370(void);
extern "C" void tail_fn_00885370(void*);
extern int g_a_00885370;
extern int g_b_00885370;
extern int g_c_00885370;

void func_00885370()
{
    init_fn_00885370(&g_a_00885370, &g_b_00885370);
    run_fn_00885370();
    tail_fn_00885370(&g_c_00885370);
}
