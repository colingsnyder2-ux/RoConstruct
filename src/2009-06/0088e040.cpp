// from server: 100% by colin
extern int g_0088e040_0;
extern int g_0088e040_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088e040(void*);
struct O_0088e040 { int m(void*, void*, int, int); };
extern O_0088e040 g_obj_0088e040;
extern int g_tail_0088e040;
void func_0088e040()
{
    g_obj_0088e040.m((void*)&g_0088e040_0, (void*)&g_0088e040_1, 149, 7);
    tail_fn_0088e040(&g_tail_0088e040);
}