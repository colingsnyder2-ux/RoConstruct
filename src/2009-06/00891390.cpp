// from server: 100% by colin
extern int g_00891390_0;
extern int g_00891390_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00891390(void*);
struct O_00891390 { int m(void*, void*, int, int); };
extern O_00891390 g_obj_00891390;
extern int g_tail_00891390;
void func_00891390()
{
    g_obj_00891390.m((void*)&g_00891390_0, (void*)&g_00891390_1, 392, 7);
    tail_fn_00891390(&g_tail_00891390);
}