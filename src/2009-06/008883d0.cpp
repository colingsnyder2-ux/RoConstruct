// from server: 100% by colin
extern int g_008883d0_1;
extern int g_008883d0_2;
extern int g_008883d0_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_008883d0(void*);
struct O_008883d0 { int m(int, void*, void*, void*); };
extern O_008883d0 g_obj_008883d0;
extern int g_tail_008883d0;
void func_008883d0()
{
    g_obj_008883d0.m(12032, (void*)&g_008883d0_1, (void*)&g_008883d0_2, (void*)&g_008883d0_3);
    tail_fn_008883d0(&g_tail_008883d0);
}