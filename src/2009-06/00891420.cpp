// from server: 100% by colin
extern int g_00891420_0;
extern int g_00891420_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00891420(void*);
struct O_00891420 { int m(void*, void*, int, int); };
extern O_00891420 g_obj_00891420;
extern int g_tail_00891420;
void func_00891420()
{
    g_obj_00891420.m((void*)&g_00891420_0, (void*)&g_00891420_1, 388, 7);
    tail_fn_00891420(&g_tail_00891420);
}