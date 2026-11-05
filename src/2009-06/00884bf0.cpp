// from server: 100% by colin
extern int g_00884bf0_0;
extern int g_00884bf0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00884bf0(void*);
struct O_00884bf0 { int m(void*, void*, int, int); };
extern O_00884bf0 g_obj_00884bf0;
extern int g_tail_00884bf0;
void func_00884bf0()
{
    g_obj_00884bf0.m((void*)&g_00884bf0_0, (void*)&g_00884bf0_1, 142, 7);
    tail_fn_00884bf0(&g_tail_00884bf0);
}