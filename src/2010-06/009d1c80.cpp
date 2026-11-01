// from server: 100% by colin
extern int g_009d1c80_0;
extern int g_009d1c80_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d1c80(void*);
struct O_009d1c80 { int m(void*, void*, int, int, int); };
extern O_009d1c80 g_obj_009d1c80;
extern int g_tail_009d1c80;
void func_009d1c80()
{
    g_obj_009d1c80.m((void*)&g_009d1c80_0, (void*)&g_009d1c80_1, 588, 2, 0);
    tail_fn_009d1c80(&g_tail_009d1c80);
}