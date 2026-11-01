// from server: 100% by colin
extern int g_009d5380_0;
extern int g_009d5380_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009d5380(void*);
struct O_009d5380 { int m(void*, void*, int, int, int); };
extern O_009d5380 g_obj_009d5380;
extern int g_tail_009d5380;
void func_009d5380()
{
    g_obj_009d5380.m((void*)&g_009d5380_0, (void*)&g_009d5380_1, 392, 15, 0);
    tail_fn_009d5380(&g_tail_009d5380);
}