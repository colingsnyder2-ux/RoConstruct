// from server: 100% by colin
extern int g_0088ef60_0;
extern int g_0088ef60_1;
extern int g_0088ef60_2;
extern int g_0088ef60_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088ef60(void*);
struct O_0088ef60 { int m(void*, void*, void*, void*, int); };
extern O_0088ef60 g_obj_0088ef60;
extern int g_tail_0088ef60;
void func_0088ef60()
{
    g_obj_0088ef60.m((void*)&g_0088ef60_0, (void*)&g_0088ef60_1, (void*)&g_0088ef60_2, (void*)&g_0088ef60_3, 7);
    tail_fn_0088ef60(&g_tail_0088ef60);
}