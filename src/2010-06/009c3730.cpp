// from server: 100% by colin
extern int g_009c3730_0;
extern int g_009c3730_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c3730(void*);
struct O_009c3730 { int m(void*, void*, int, int, int); };
extern O_009c3730 g_obj_009c3730;
extern int g_tail_009c3730;
void func_009c3730()
{
    g_obj_009c3730.m((void*)&g_009c3730_0, (void*)&g_009c3730_1, 180, 15, 0);
    tail_fn_009c3730(&g_tail_009c3730);
}