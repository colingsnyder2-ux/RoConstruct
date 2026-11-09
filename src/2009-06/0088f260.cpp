// from server: 100% by colin
extern int g_0088f260_0;
extern int g_0088f260_1;
extern int g_0088f260_2;
extern int g_0088f260_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088f260(void*);
struct O_0088f260 { int m(void*, void*, void*, void*, int); };
extern O_0088f260 g_obj_0088f260;
extern int g_tail_0088f260;
void func_0088f260()
{
    g_obj_0088f260.m((void*)&g_0088f260_0, (void*)&g_0088f260_1, (void*)&g_0088f260_2, (void*)&g_0088f260_3, 7);
    tail_fn_0088f260(&g_tail_0088f260);
}