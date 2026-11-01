// from server: 100% by colin
extern int g_009cda20_1;
extern int g_009cda20_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009cda20(void*);
struct O_009cda20 { int m(int, void*, void*, int, int); };
extern O_009cda20 g_obj_009cda20;
extern int g_tail_009cda20;
void func_009cda20()
{
    g_obj_009cda20.m(212, (void*)&g_009cda20_1, (void*)&g_009cda20_2, 0, 1);
    tail_fn_009cda20(&g_tail_009cda20);
}