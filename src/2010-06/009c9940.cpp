// from server: 100% by colin
extern int g_009c9940_1;
extern int g_009c9940_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c9940(void*);
struct O_009c9940 { int m(int, void*, void*, int, int); };
extern O_009c9940 g_obj_009c9940;
extern int g_tail_009c9940;
void func_009c9940()
{
    g_obj_009c9940.m(140, (void*)&g_009c9940_1, (void*)&g_009c9940_2, 0, 1);
    tail_fn_009c9940(&g_tail_009c9940);
}