// from server: 100% by colin
extern int g_009c76a0_1;
extern int g_009c76a0_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c76a0(void*);
struct O_009c76a0 { int m(int, void*, void*, int, int); };
extern O_009c76a0 g_obj_009c76a0;
extern int g_tail_009c76a0;
void func_009c76a0()
{
    g_obj_009c76a0.m(328, (void*)&g_009c76a0_1, (void*)&g_009c76a0_2, 0, 1);
    tail_fn_009c76a0(&g_tail_009c76a0);
}