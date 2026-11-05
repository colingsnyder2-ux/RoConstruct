// from server: 100% by colin
extern int g_00891910_0;
extern int g_00891910_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00891910(void*);
struct O_00891910 { int m(void*, void*, int, int); };
extern O_00891910 g_obj_00891910;
extern int g_tail_00891910;
void func_00891910()
{
    g_obj_00891910.m((void*)&g_00891910_0, (void*)&g_00891910_1, 336, 7);
    tail_fn_00891910(&g_tail_00891910);
}