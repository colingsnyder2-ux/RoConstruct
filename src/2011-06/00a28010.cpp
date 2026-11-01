// from server: 100% by colin
extern int g_00a28010_0;
extern int g_00a28010_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a28010(void*);
struct O_00a28010 { int m(void*, void*, int, int, int); };
extern O_00a28010 g_obj_00a28010;
extern int g_tail_00a28010;
void func_00a28010()
{
    g_obj_00a28010.m((void*)&g_00a28010_0, (void*)&g_00a28010_1, 152, 31, 0);
    tail_fn_00a28010(&g_tail_00a28010);
}