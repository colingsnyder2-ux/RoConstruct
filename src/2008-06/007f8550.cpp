// from server: 100% by colin
extern int g_007f8550_0;
extern int g_007f8550_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f8550(void*);
struct O_007f8550 { int m(void*, void*, int, int); };
extern O_007f8550 g_obj_007f8550;
extern int g_tail_007f8550;
void func_007f8550()
{
    g_obj_007f8550.m((void*)&g_007f8550_0, (void*)&g_007f8550_1, 328, 5);
    tail_fn_007f8550(&g_tail_007f8550);
}