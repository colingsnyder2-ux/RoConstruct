// from server: 100% by colin
extern int g_00892000_0;
extern int g_00892000_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00892000(void*);
struct O_00892000 { int m(void*, void*, int, int); };
extern O_00892000 g_obj_00892000;
extern int g_tail_00892000;
void func_00892000()
{
    g_obj_00892000.m((void*)&g_00892000_0, (void*)&g_00892000_1, 164, 7);
    tail_fn_00892000(&g_tail_00892000);
}