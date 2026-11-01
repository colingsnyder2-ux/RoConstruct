// from server: 100% by colin
extern int g_009d8050_1;
extern int g_009d8050_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d8050(void*);
struct O_009d8050 { int m(int, void*, void*, int, int); };
extern O_009d8050 g_obj_009d8050;
extern int g_tail_009d8050;
void func_009d8050()
{
    g_obj_009d8050.m(236, (void*)&g_009d8050_1, (void*)&g_009d8050_2, 0, 1);
    tail_fn_009d8050(&g_tail_009d8050);
}