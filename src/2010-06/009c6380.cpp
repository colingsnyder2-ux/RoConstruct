// from server: 100% by colin
extern int g_009c6380_0;
extern int g_009c6380_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c6380(void*);
struct O_009c6380 { int m(void*, void*, int, int, int); };
extern O_009c6380 g_obj_009c6380;
extern int g_tail_009c6380;
void func_009c6380()
{
    g_obj_009c6380.m((void*)&g_009c6380_0, (void*)&g_009c6380_1, 220, 6, 2);
    tail_fn_009c6380(&g_tail_009c6380);
}