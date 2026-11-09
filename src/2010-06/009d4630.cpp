// from server: 100% by colin
extern int g_009d4630_0;
extern int g_009d4630_1;
extern int g_009d4630_2;
extern int g_009d4630_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d4630(void*);
struct O_009d4630 { int m(void*, void*, void*, void*, int); };
extern O_009d4630 g_obj_009d4630;
extern int g_tail_009d4630;
void func_009d4630()
{
    g_obj_009d4630.m((void*)&g_009d4630_0, (void*)&g_009d4630_1, (void*)&g_009d4630_2, (void*)&g_009d4630_3, 15);
    tail_fn_009d4630(&g_tail_009d4630);
}