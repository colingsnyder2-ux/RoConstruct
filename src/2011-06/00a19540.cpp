// from server: 100% by colin
extern int g_00a19540_0;
extern int g_00a19540_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a19540(void*);
struct O_00a19540 { int m(void*, void*, int, int, int); };
extern O_00a19540 g_obj_00a19540;
extern int g_tail_00a19540;
void func_00a19540()
{
    g_obj_00a19540.m((void*)&g_00a19540_0, (void*)&g_00a19540_1, 149, 31, 0);
    tail_fn_00a19540(&g_tail_00a19540);
}