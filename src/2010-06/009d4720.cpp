// from server: 100% by colin
extern int g_009d4720_0;
extern int g_009d4720_1;
extern int g_009d4720_2;
extern int g_009d4720_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d4720(void*);
struct O_009d4720 { int m(void*, void*, void*, void*, int); };
extern O_009d4720 g_obj_009d4720;
extern int g_tail_009d4720;
void func_009d4720()
{
    g_obj_009d4720.m((void*)&g_009d4720_0, (void*)&g_009d4720_1, (void*)&g_009d4720_2, (void*)&g_009d4720_3, 15);
    tail_fn_009d4720(&g_tail_009d4720);
}