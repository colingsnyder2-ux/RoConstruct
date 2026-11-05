// from server: 89% by atomic.potato
extern "C" void __cdecl init_9831f5(const char*);

static volatile unsigned int g_flag;
static volatile int g_value0;
static volatile int g_value1;

void f()
{
    if (g_flag & 1)
        return;

    g_flag |= 1;
    g_value0 = 0;
    g_value1 = 0;
    init_9831f5("8csm");
}
