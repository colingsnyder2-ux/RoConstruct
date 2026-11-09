// from server: 100% by colin
extern int g_009d1160_1;
extern int g_009d1160_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d1160(void*);
struct O_009d1160 { int m(int, void*, void*, int, int); };
extern O_009d1160 g_obj_009d1160;
extern int g_tail_009d1160;
void func_009d1160()
{
    g_obj_009d1160.m(236, (void*)&g_009d1160_1, (void*)&g_009d1160_2, 0, 1);
    tail_fn_009d1160(&g_tail_009d1160);
}