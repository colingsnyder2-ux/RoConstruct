// from server: 100% by colin
extern int g_00891790_0;
extern int g_00891790_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00891790(void*);
struct O_00891790 { int m(void*, void*, int, int); };
extern O_00891790 g_obj_00891790;
extern int g_tail_00891790;
void func_00891790()
{
    g_obj_00891790.m((void*)&g_00891790_0, (void*)&g_00891790_1, 336, 7);
    tail_fn_00891790(&g_tail_00891790);
}