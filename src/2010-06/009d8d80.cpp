// from server: 100% by colin
extern int g_009d8d80_1;
extern int g_009d8d80_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d8d80(void*);
struct O_009d8d80 { int m(int, void*, void*, int, int); };
extern O_009d8d80 g_obj_009d8d80;
extern int g_tail_009d8d80;
void func_009d8d80()
{
    g_obj_009d8d80.m(180, (void*)&g_009d8d80_1, (void*)&g_009d8d80_2, 0, 1);
    tail_fn_009d8d80(&g_tail_009d8d80);
}