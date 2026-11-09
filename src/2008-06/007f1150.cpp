// from server: 100% by colin
extern int g_007f1150_0;
extern int g_007f1150_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f1150(void*);
struct O_007f1150 { int m(void*, void*, int, int); };
extern O_007f1150 g_obj_007f1150;
extern int g_tail_007f1150;
void func_007f1150()
{
    g_obj_007f1150.m((void*)&g_007f1150_0, (void*)&g_007f1150_1, 444, 4);
    tail_fn_007f1150(&g_tail_007f1150);
}