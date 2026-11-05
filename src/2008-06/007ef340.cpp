// from server: 100% by colin
extern int g_007ef340_0;
extern int g_007ef340_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007ef340(void*);
struct O_007ef340 { int m(void*, void*, int, int); };
extern O_007ef340 g_obj_007ef340;
extern int g_tail_007ef340;
void func_007ef340()
{
    g_obj_007ef340.m((void*)&g_007ef340_0, (void*)&g_007ef340_1, 305, 5);
    tail_fn_007ef340(&g_tail_007ef340);
}