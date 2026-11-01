// from server: 100% by colin
extern int g_0088f140_0;
extern int g_0088f140_1;
extern int g_0088f140_2;
extern int g_0088f140_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088f140(void*);
struct O_0088f140 { int m(void*, void*, void*, void*, int); };
extern O_0088f140 g_obj_0088f140;
extern int g_tail_0088f140;
void func_0088f140()
{
    g_obj_0088f140.m((void*)&g_0088f140_0, (void*)&g_0088f140_1, (void*)&g_0088f140_2, (void*)&g_0088f140_3, 7);
    tail_fn_0088f140(&g_tail_0088f140);
}