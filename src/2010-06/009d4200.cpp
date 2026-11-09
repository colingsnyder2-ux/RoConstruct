// from server: 100% by colin
extern int g_009d4200_0;
extern int g_009d4200_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d4200(void*);
struct O_009d4200 { int m(void*, void*, int, int, int); };
extern O_009d4200 g_obj_009d4200;
extern int g_tail_009d4200;
void func_009d4200()
{
    g_obj_009d4200.m((void*)&g_009d4200_0, (void*)&g_009d4200_1, 212, 15, 0);
    tail_fn_009d4200(&g_tail_009d4200);
}