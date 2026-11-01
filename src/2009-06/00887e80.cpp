// from server: 100% by colin
extern int g_00887e80_0;
extern int g_00887e80_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00887e80(void*);
struct O_00887e80 { int m(void*, void*, int, int); };
extern O_00887e80 g_obj_00887e80;
extern int g_tail_00887e80;
void func_00887e80()
{
    g_obj_00887e80.m((void*)&g_00887e80_0, (void*)&g_00887e80_1, 192, 7);
    tail_fn_00887e80(&g_tail_00887e80);
}