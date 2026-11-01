// from server: 100% by colin
extern int g_009d5410_0;
extern int g_009d5410_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d5410(void*);
struct O_009d5410 { int m(void*, void*, int, int, int); };
extern O_009d5410 g_obj_009d5410;
extern int g_tail_009d5410;
void func_009d5410()
{
    g_obj_009d5410.m((void*)&g_009d5410_0, (void*)&g_009d5410_1, 408, 15, 0);
    tail_fn_009d5410(&g_tail_009d5410);
}