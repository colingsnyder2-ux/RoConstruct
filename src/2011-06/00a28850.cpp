// from server: 100% by colin
extern int g_00a28850_0;
extern int g_00a28850_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a28850(void*);
struct O_00a28850 { int m(void*, void*, int, int, int); };
extern O_00a28850 g_obj_00a28850;
extern int g_tail_00a28850;
void func_00a28850()
{
    g_obj_00a28850.m((void*)&g_00a28850_0, (void*)&g_00a28850_1, 300, 2, 0);
    tail_fn_00a28850(&g_tail_00a28850);
}