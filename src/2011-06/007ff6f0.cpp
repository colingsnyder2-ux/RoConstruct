// from server: 100% by atomic.potato
int g_d16fec;
int g_d16ff0;
int g_d16ff4;
int g_d16ff8;
int g_d16ffc;

void f(int value)
{
    int old = g_d16ff4;
    int a = g_d16ff0;
    int b = g_d16fec;
    ++g_d16ffc;
    g_d16ff8 = old;
    g_d16ff4 = a;
    g_d16ff0 = b;
    g_d16fec = value;
}
