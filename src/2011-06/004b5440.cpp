// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004b5440(void*);
extern int g_a_004b5440;
extern int g_b_004b5440;
extern int g_arg_004b5440;
struct Reg_004b5440 { Reg_004b5440() { g_a_004b5440 = 0; g_b_004b5440 = 0; seh_fn_004b5440(&g_arg_004b5440); } };
void func_004b5440()
{
    static Reg_004b5440 reg;
}
