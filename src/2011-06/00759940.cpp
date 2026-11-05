// from server: 41% by atomic.potato
extern int g_a;
extern int g_b;
extern float g_one;

float f()
{
    int a = g_a;
    int b = g_b;
    int sum = b + a;
    if (sum == 0)
        return g_one;
    return (float)a / (float)sum;
}
