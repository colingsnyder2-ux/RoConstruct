// from server: 100% by colin
extern int g_00888060_0;
extern int g_00888060_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00888060(void*);
struct O_00888060 { int m(void*, void*, int, int); };
extern O_00888060 g_obj_00888060;
extern int g_tail_00888060;
void func_00888060()
{
    g_obj_00888060.m((void*)&g_00888060_0, (void*)&g_00888060_1, 168, 7);
    tail_fn_00888060(&g_tail_00888060);
}