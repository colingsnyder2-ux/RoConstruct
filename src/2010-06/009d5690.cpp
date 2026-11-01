// from server: 100% by colin
extern int g_009d5690_0;
extern int g_009d5690_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d5690(void*);
struct O_009d5690 { int m(void*, void*, int, int, int); };
extern O_009d5690 g_obj_009d5690;
extern int g_tail_009d5690;
void func_009d5690()
{
    g_obj_009d5690.m((void*)&g_009d5690_0, (void*)&g_009d5690_1, 364, 15, 0);
    tail_fn_009d5690(&g_tail_009d5690);
}