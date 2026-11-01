// from server: 100% by colin
extern int g_00a2c390_0;
extern int g_00a2c390_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2c390(void*);
struct O_00a2c390 { int m(void*, void*, int, int, int); };
extern O_00a2c390 g_obj_00a2c390;
extern int g_tail_00a2c390;
void func_00a2c390()
{
    g_obj_00a2c390.m((void*)&g_00a2c390_0, (void*)&g_00a2c390_1, 272, 31, 0);
    tail_fn_00a2c390(&g_tail_00a2c390);
}