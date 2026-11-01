// from server: 100% by colin
extern int g_0088da30_0;
extern int g_0088da30_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088da30(void*);
struct O_0088da30 { int m(void*, void*, int, int); };
extern O_0088da30 g_obj_0088da30;
extern int g_tail_0088da30;
void func_0088da30()
{
    g_obj_0088da30.m((void*)&g_0088da30_0, (void*)&g_0088da30_1, 196, 7);
    tail_fn_0088da30(&g_tail_0088da30);
}