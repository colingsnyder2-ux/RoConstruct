// from server: 41% by atomic.potato
extern int g_0xc22924;
extern int g_0xc22928;
extern float g_0xa0c610;

struct RBX_BallBlockConnector {
    float getValue();
};

float RBX_BallBlockConnector::getValue()
{
    int a = g_0xc22924;
    int b = g_0xc22928;
    int sum = b + a;
    if (sum == 0)
        return g_0xa0c610;
    return (float)a / (float)sum;
}
