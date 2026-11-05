// from server: 41% by atomic.potato
extern int g_0xb98818;
extern int g_0xb9881c;
extern float g_0x9ab804;

float GetRatio()
{
    int a = g_0xb98818;
    int b = g_0xb9881c;
    int sum = b + a;
    if (sum == 0)
        return g_0x9ab804;
    return (float)a / (float)sum;
}
