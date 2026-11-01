// from server: 100% by colin
extern int g_00889980_0;
extern int g_00889980_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00889980(void*);
struct O_00889980 { int m(void*, void*, int, int); };
extern O_00889980 g_obj_00889980;
extern int g_tail_00889980;
void func_00889980()
{
    g_obj_00889980.m((void*)&g_00889980_0, (void*)&g_00889980_1, 154, 7);
    tail_fn_00889980(&g_tail_00889980);
}