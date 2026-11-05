// from server: 100% by colin
extern int g_00a15a40_0;
extern int g_00a15a40_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a15a40(void*);
struct O_00a15a40 { int m(void*, void*, int, int, int); };
extern O_00a15a40 g_obj_00a15a40;
extern int g_tail_00a15a40;
void func_00a15a40()
{
    g_obj_00a15a40.m((void*)&g_00a15a40_0, (void*)&g_00a15a40_1, 152, 31, 0);
    tail_fn_00a15a40(&g_tail_00a15a40);
}