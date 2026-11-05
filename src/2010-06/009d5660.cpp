// from server: 100% by colin
extern int g_009d5660_0;
extern int g_009d5660_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d5660(void*);
struct O_009d5660 { int m(void*, void*, int, int, int); };
extern O_009d5660 g_obj_009d5660;
extern int g_tail_009d5660;
void func_009d5660()
{
    g_obj_009d5660.m((void*)&g_009d5660_0, (void*)&g_009d5660_1, 352, 15, 0);
    tail_fn_009d5660(&g_tail_009d5660);
}