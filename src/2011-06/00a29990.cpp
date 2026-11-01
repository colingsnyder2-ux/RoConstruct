// from server: 100% by colin
extern int g_00a29990_1;
extern int g_00a29990_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a29990(void*);
struct O_00a29990 { int m(int, void*, void*, int); };
extern O_00a29990 g_obj_00a29990;
extern int g_tail_00a29990;
void func_00a29990()
{
    g_obj_00a29990.m(512, (void*)&g_00a29990_1, (void*)&g_00a29990_2, 0);
    tail_fn_00a29990(&g_tail_00a29990);
}