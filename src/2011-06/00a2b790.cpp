// from server: 100% by colin
extern int g_00a2b790_0;
extern int g_00a2b790_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2b790(void*);
struct O_00a2b790 { int m(void*, void*, int, int, int); };
extern O_00a2b790 g_obj_00a2b790;
extern int g_tail_00a2b790;
void func_00a2b790()
{
    g_obj_00a2b790.m((void*)&g_00a2b790_0, (void*)&g_00a2b790_1, 384, 31, 0);
    tail_fn_00a2b790(&g_tail_00a2b790);
}