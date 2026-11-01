// from server: 100% by colin
extern int g_007ef370_0;
extern int g_007ef370_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007ef370(void*);
struct O_007ef370 { int m(void*, void*, int, int); };
extern O_007ef370 g_obj_007ef370;
extern int g_tail_007ef370;
void func_007ef370()
{
    g_obj_007ef370.m((void*)&g_007ef370_0, (void*)&g_007ef370_1, 306, 5);
    tail_fn_007ef370(&g_tail_007ef370);
}