// from server: 100% by colin
extern int g_0088d180_0;
extern int g_0088d180_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088d180(void*);
struct O_0088d180 { int m(void*, void*, int, int); };
extern O_0088d180 g_obj_0088d180;
extern int g_tail_0088d180;
void func_0088d180()
{
    g_obj_0088d180.m((void*)&g_0088d180_0, (void*)&g_0088d180_1, 344, 7);
    tail_fn_0088d180(&g_tail_0088d180);
}