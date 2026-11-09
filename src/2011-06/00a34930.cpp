// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a34930;
extern "C" int init_fn_00a34930(void*);
extern void* g_target_00a34930;
extern int g_value_00a34930;

void func_00a34930()
{
    if (g_ptr_00a34930)
        init_fn_00a34930(g_ptr_00a34930);
    g_target_00a34930 = &g_value_00a34930;
}
