// from server: 100% by colin
extern int g_009d0110_0;
extern int g_009d0110_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d0110(void*);
struct O_009d0110 { int m(void*, void*, int, int, int); };
extern O_009d0110 g_obj_009d0110;
extern int g_tail_009d0110;
void func_009d0110()
{
    g_obj_009d0110.m((void*)&g_009d0110_0, (void*)&g_009d0110_1, 152, 15, 0);
    tail_fn_009d0110(&g_tail_009d0110);
}