// from server: 100% by colin
extern int g_009d8b70_0;
extern int g_009d8b70_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d8b70(void*);
struct O_009d8b70 { int m(void*, void*, int, int, int); };
extern O_009d8b70 g_obj_009d8b70;
extern int g_tail_009d8b70;
void func_009d8b70()
{
    g_obj_009d8b70.m((void*)&g_009d8b70_0, (void*)&g_009d8b70_1, 580, 2, 0);
    tail_fn_009d8b70(&g_tail_009d8b70);
}