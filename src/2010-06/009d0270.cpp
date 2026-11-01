// from server: 100% by colin
extern int g_009d0270_0;
extern int g_009d0270_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d0270(void*);
struct O_009d0270 { int m(void*, void*, int, int, int); };
extern O_009d0270 g_obj_009d0270;
extern int g_tail_009d0270;
void func_009d0270()
{
    g_obj_009d0270.m((void*)&g_009d0270_0, (void*)&g_009d0270_1, 196, 15, 0);
    tail_fn_009d0270(&g_tail_009d0270);
}