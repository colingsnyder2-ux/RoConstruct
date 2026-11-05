// from server: 69% by atomic.potato
extern unsigned char g_b7a2ec;
extern int g_b7a2e8;
extern char g_97de80;

extern "C" void func_007f4929(char*);

int func_0042af80()
{
    if (!g_b7a2ec)
    {
        g_b7a2ec |= 1;
        g_b7a2e8 = 0;
        func_007f4929(&g_97de80);
    }
    return 1;
}
