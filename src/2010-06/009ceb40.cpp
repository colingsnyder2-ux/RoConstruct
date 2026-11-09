// from server: 100% by colin
extern int g_009ceb40_0;
extern int g_009ceb40_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009ceb40(void*);
struct O_009ceb40 { int m(void*, void*, int, int, int); };
extern O_009ceb40 g_obj_009ceb40;
extern int g_tail_009ceb40;
void func_009ceb40()
{
    g_obj_009ceb40.m((void*)&g_009ceb40_0, (void*)&g_009ceb40_1, 416, 2, 0);
    tail_fn_009ceb40(&g_tail_009ceb40);
}