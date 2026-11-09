// from server: 100% by colin
extern int g_009d6d00_0;
extern int g_009d6d00_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d6d00(void*);
struct O_009d6d00 { int m(void*, void*, int, int, int); };
extern O_009d6d00 g_obj_009d6d00;
extern int g_tail_009d6d00;
void func_009d6d00()
{
    g_obj_009d6d00.m((void*)&g_009d6d00_0, (void*)&g_009d6d00_1, 152, 15, 0);
    tail_fn_009d6d00(&g_tail_009d6d00);
}