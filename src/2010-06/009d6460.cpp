// from server: 100% by colin
extern int g_009d6460_0;
extern int g_009d6460_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d6460(void*);
struct O_009d6460 { int m(void*, void*, int, int, int); };
extern O_009d6460 g_obj_009d6460;
extern int g_tail_009d6460;
void func_009d6460()
{
    g_obj_009d6460.m((void*)&g_009d6460_0, (void*)&g_009d6460_1, 324, 2, 0);
    tail_fn_009d6460(&g_tail_009d6460);
}