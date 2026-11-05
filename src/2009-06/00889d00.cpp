// from server: 100% by colin
extern int g_00889d00_1;
extern int g_00889d00_2;
extern int g_00889d00_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00889d00(void*);
struct O_00889d00 { int m(int, void*, void*, void*); };
extern O_00889d00 g_obj_00889d00;
extern int g_tail_00889d00;
void func_00889d00()
{
    g_obj_00889d00.m(132, (void*)&g_00889d00_1, (void*)&g_00889d00_2, (void*)&g_00889d00_3);
    tail_fn_00889d00(&g_tail_00889d00);
}