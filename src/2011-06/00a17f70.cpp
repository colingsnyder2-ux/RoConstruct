// from server: 100% by colin
extern int g_00a17f70_1;
extern int g_00a17f70_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a17f70(void*);
struct O_00a17f70 { int m(int, void*, void*, int); };
extern O_00a17f70 g_obj_00a17f70;
extern int g_tail_00a17f70;
void func_00a17f70()
{
    g_obj_00a17f70.m(340, (void*)&g_00a17f70_1, (void*)&g_00a17f70_2, 0);
    tail_fn_00a17f70(&g_tail_00a17f70);
}