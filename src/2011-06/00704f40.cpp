// from server: 100% by atomic.potato
extern "C" void Initialize(void *);

unsigned int g_flag;
int g_value0;
int g_value1;

void f()
{
    if (!(g_flag & 1))
    {
        g_flag |= 1;
        g_value0 = 0;
        g_value1 = 0;
        Initialize((void *)0xa3dfb0);
    }
}
