// from server: 100% by colin
extern int g_008915e0_0;
extern int g_008915e0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_008915e0(void*);
struct O_008915e0 { int m(void*, void*, int, int); };
extern O_008915e0 g_obj_008915e0;
extern int g_tail_008915e0;
void func_008915e0()
{
    g_obj_008915e0.m((void*)&g_008915e0_0, (void*)&g_008915e0_1, 340, 7);
    tail_fn_008915e0(&g_tail_008915e0);
}