// from server: 100% by colin
extern int g_0088e110_1;
extern int g_0088e110_2;
extern int g_0088e110_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088e110(void*);
struct O_0088e110 { int m(int, void*, void*, void*); };
extern O_0088e110 g_obj_0088e110;
extern int g_tail_0088e110;
void func_0088e110()
{
    g_obj_0088e110.m(192, (void*)&g_0088e110_1, (void*)&g_0088e110_2, (void*)&g_0088e110_3);
    tail_fn_0088e110(&g_tail_0088e110);
}