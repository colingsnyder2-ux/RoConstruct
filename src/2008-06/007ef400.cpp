// from server: 100% by colin
extern int g_007ef400_0;
extern int g_007ef400_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007ef400(void*);
struct O_007ef400 { int m(void*, void*, int, int); };
extern O_007ef400 g_obj_007ef400;
extern int g_tail_007ef400;
void func_007ef400()
{
    g_obj_007ef400.m((void*)&g_007ef400_0, (void*)&g_007ef400_1, 340, 5);
    tail_fn_007ef400(&g_tail_007ef400);
}