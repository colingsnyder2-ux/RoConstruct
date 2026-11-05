// from server: 30% by atomic.potato
extern float g_a;
extern int g_b;
extern int g_c;

float f()
{
    int b = g_b;
    int c = g_c;
    int sum = c + b;
    if (sum != 0)
        return (float)b / (float)sum;
    return g_a;
}
