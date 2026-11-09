// from server: 100% by atomic.potato
extern "C" void __cdecl fn_00401610(void*, void*);
extern "C" void __cdecl fn_0080b15d(void*);
extern void fn_004252e0();

int g_00cb2570;
int g_00cb2574;
int g_00cb2578;
char g_00cb257c;

int* func_00425310()
{
    fn_00401610((void*)0xcb257c, (void*)0x4252e0);
    if (!(g_00cb2578 & 1)) {
        g_00cb2578 |= 1;
        g_00cb2570 = 0;
        g_00cb2574 = 0;
        fn_0080b15d((void*)0xa30a50);
    }
    return &g_00cb2570;
}
