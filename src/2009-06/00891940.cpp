// from server: 100% by colin
extern int g_00891940_0;
extern int g_00891940_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00891940(void*);
struct O_00891940 { int m(void*, void*, int, int); };
extern O_00891940 g_obj_00891940;
extern int g_tail_00891940;
void func_00891940()
{
    g_obj_00891940.m((void*)&g_00891940_0, (void*)&g_00891940_1, 336, 7);
    tail_fn_00891940(&g_tail_00891940);
}