// from server: 100% by colin
extern int g_009d0170_0;
extern int g_009d0170_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d0170(void*);
struct O_009d0170 { int m(void*, void*, int, int, int); };
extern O_009d0170 g_obj_009d0170;
extern int g_tail_009d0170;
void func_009d0170()
{
    g_obj_009d0170.m((void*)&g_009d0170_0, (void*)&g_009d0170_1, 160, 15, 0);
    tail_fn_009d0170(&g_tail_009d0170);
}