// from server: 100% by colin
extern int g_009d4e40_1;
extern int g_009d4e40_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d4e40(void*);
struct O_009d4e40 { int m(int, void*, void*, int, int); };
extern O_009d4e40 g_obj_009d4e40;
extern int g_tail_009d4e40;
void func_009d4e40()
{
    g_obj_009d4e40.m(176, (void*)&g_009d4e40_1, (void*)&g_009d4e40_2, 0, 1);
    tail_fn_009d4e40(&g_tail_009d4e40);
}