// from server: 100% by colin
extern int g_009d01a0_0;
extern int g_009d01a0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d01a0(void*);
struct O_009d01a0 { int m(void*, void*, int, int, int); };
extern O_009d01a0 g_obj_009d01a0;
extern int g_tail_009d01a0;
void func_009d01a0()
{
    g_obj_009d01a0.m((void*)&g_009d01a0_0, (void*)&g_009d01a0_1, 161, 15, 0);
    tail_fn_009d01a0(&g_tail_009d01a0);
}