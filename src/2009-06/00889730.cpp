// from server: 100% by colin
extern int g_00889730_0;
extern int g_00889730_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00889730(void*);
struct O_00889730 { int m(void*, void*, int, int); };
extern O_00889730 g_obj_00889730;
extern int g_tail_00889730;
void func_00889730()
{
    g_obj_00889730.m((void*)&g_00889730_0, (void*)&g_00889730_1, 153, 7);
    tail_fn_00889730(&g_tail_00889730);
}