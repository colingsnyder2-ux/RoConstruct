// from server: 100% by colin
extern int g_009d6680_0;
extern int g_009d6680_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d6680(void*);
struct O_009d6680 { int m(void*, void*, int, int, int); };
extern O_009d6680 g_obj_009d6680;
extern int g_tail_009d6680;
void func_009d6680()
{
    g_obj_009d6680.m((void*)&g_009d6680_0, (void*)&g_009d6680_1, 244, 2, 0);
    tail_fn_009d6680(&g_tail_009d6680);
}