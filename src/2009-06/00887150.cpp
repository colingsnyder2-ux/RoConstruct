// from server: 100% by colin
extern int g_00887150_1;
extern int g_00887150_2;
extern int g_00887150_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00887150(void*);
struct O_00887150 { int m(int, void*, void*, void*); };
extern O_00887150 g_obj_00887150;
extern int g_tail_00887150;
void func_00887150()
{
    g_obj_00887150.m(208, (void*)&g_00887150_1, (void*)&g_00887150_2, (void*)&g_00887150_3);
    tail_fn_00887150(&g_tail_00887150);
}