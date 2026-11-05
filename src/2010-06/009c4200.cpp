// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009c4200(void*, void*);
extern "C" void run_fn_009c4200(void);
extern "C" void tail_fn_009c4200(void*);
extern int g_a_009c4200;
extern int g_b_009c4200;
extern int g_c_009c4200;

void func_009c4200()
{
    init_fn_009c4200(&g_a_009c4200, &g_b_009c4200);
    run_fn_009c4200();
    tail_fn_009c4200(&g_c_009c4200);
}
