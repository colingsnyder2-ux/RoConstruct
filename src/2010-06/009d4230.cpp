// from server: 100% by colin
extern int g_009d4230_0;
extern int g_009d4230_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d4230(void*);
struct O_009d4230 { int m(void*, void*, int, int, int); };
extern O_009d4230 g_obj_009d4230;
extern int g_tail_009d4230;
void func_009d4230()
{
    g_obj_009d4230.m((void*)&g_009d4230_0, (void*)&g_009d4230_1, 244, 15, 0);
    tail_fn_009d4230(&g_tail_009d4230);
}