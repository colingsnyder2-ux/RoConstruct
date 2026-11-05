// from server: 83% by atomic.potato
struct S
{
    void f();
};

volatile float g_009b3e08;
volatile float g_009b3e0c;
volatile float g_00b7ce30;
volatile float g_00b7ce34;
volatile float g_00b7ce38;
volatile float g_00b7ce3c;

void S::f()
{
    g_00b7ce30 = g_009b3e0c;
    g_00b7ce34 = g_009b3e0c;
    g_00b7ce38 = g_009b3e0c;
    g_00b7ce3c = g_009b3e08;
}
