// from server: 100% by colin
extern int g_009d4d40_1;
extern int g_009d4d40_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d4d40(void*);
struct O_009d4d40 { int m(int, void*, void*, int, int); };
extern O_009d4d40 g_obj_009d4d40;
extern int g_tail_009d4d40;
void func_009d4d40()
{
    g_obj_009d4d40.m(176, (void*)&g_009d4d40_1, (void*)&g_009d4d40_2, 0, 1);
    tail_fn_009d4d40(&g_tail_009d4d40);
}