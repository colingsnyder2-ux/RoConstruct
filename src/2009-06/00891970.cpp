// from server: 100% by colin
extern int g_00891970_0;
extern int g_00891970_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00891970(void*);
struct O_00891970 { int m(void*, void*, int, int); };
extern O_00891970 g_obj_00891970;
extern int g_tail_00891970;
void func_00891970()
{
    g_obj_00891970.m((void*)&g_00891970_0, (void*)&g_00891970_1, 348, 7);
    tail_fn_00891970(&g_tail_00891970);
}