// from server: 100% by colin
extern int g_009ced90_0;
extern int g_009ced90_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009ced90(void*);
struct O_009ced90 { int m(void*, void*, int, int, int); };
extern O_009ced90 g_obj_009ced90;
extern int g_tail_009ced90;
void func_009ced90()
{
    g_obj_009ced90.m((void*)&g_009ced90_0, (void*)&g_009ced90_1, 412, 15, 0);
    tail_fn_009ced90(&g_tail_009ced90);
}