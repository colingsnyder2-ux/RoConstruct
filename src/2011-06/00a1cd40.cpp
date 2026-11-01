// from server: 100% by colin
extern int g_00a1cd40_0;
extern int g_00a1cd40_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a1cd40(void*);
struct O_00a1cd40 { int m(void*, void*, int, int, int); };
extern O_00a1cd40 g_obj_00a1cd40;
extern int g_tail_00a1cd40;
void func_00a1cd40()
{
    g_obj_00a1cd40.m((void*)&g_00a1cd40_0, (void*)&g_00a1cd40_1, 200, 31, 0);
    tail_fn_00a1cd40(&g_tail_00a1cd40);
}