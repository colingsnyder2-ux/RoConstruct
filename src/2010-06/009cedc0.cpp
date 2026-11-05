// from server: 100% by colin
extern int g_009cedc0_1;
extern int g_009cedc0_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009cedc0(void*);
struct O_009cedc0 { int m(int, void*, void*, int, int); };
extern O_009cedc0 g_obj_009cedc0;
extern int g_tail_009cedc0;
void func_009cedc0()
{
    g_obj_009cedc0.m(468, (void*)&g_009cedc0_1, (void*)&g_009cedc0_2, 0, 1);
    tail_fn_009cedc0(&g_tail_009cedc0);
}