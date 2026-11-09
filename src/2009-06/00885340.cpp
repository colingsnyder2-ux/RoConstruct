// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00885340(void*, void*);
extern "C" void run_fn_00885340(void);
extern "C" void tail_fn_00885340(void*);
extern int g_a_00885340;
extern int g_b_00885340;
extern int g_c_00885340;

void func_00885340()
{
    init_fn_00885340(&g_a_00885340, &g_b_00885340);
    run_fn_00885340();
    tail_fn_00885340(&g_c_00885340);
}
