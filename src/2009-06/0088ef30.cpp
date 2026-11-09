// from server: 100% by colin
extern int g_0088ef30_0;
extern int g_0088ef30_1;
extern int g_0088ef30_2;
extern int g_0088ef30_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088ef30(void*);
struct O_0088ef30 { int m(void*, void*, void*, void*, int); };
extern O_0088ef30 g_obj_0088ef30;
extern int g_tail_0088ef30;
void func_0088ef30()
{
    g_obj_0088ef30.m((void*)&g_0088ef30_0, (void*)&g_0088ef30_1, (void*)&g_0088ef30_2, (void*)&g_0088ef30_3, 7);
    tail_fn_0088ef30(&g_tail_0088ef30);
}