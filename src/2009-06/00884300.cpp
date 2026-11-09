// from server: 100% by colin
extern int g_00884300_0;
extern int g_00884300_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00884300(void*);
struct O_00884300 { int m(void*, void*, int, int); };
extern O_00884300 g_obj_00884300;
extern int g_tail_00884300;
void func_00884300()
{
    g_obj_00884300.m((void*)&g_00884300_0, (void*)&g_00884300_1, 141, 7);
    tail_fn_00884300(&g_tail_00884300);
}