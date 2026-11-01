// from server: 100% by colin
extern int g_009d6710_0;
extern int g_009d6710_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d6710(void*);
struct O_009d6710 { int m(void*, void*, int, int, int); };
extern O_009d6710 g_obj_009d6710;
extern int g_tail_009d6710;
void func_009d6710()
{
    g_obj_009d6710.m((void*)&g_009d6710_0, (void*)&g_009d6710_1, 364, 2, 0);
    tail_fn_009d6710(&g_tail_009d6710);
}