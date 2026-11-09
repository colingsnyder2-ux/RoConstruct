// from server: 41% by atomic.potato
extern int g_0xb98810;
extern int g_0xb98814;
extern float g_0x9ab804;

struct RBX_BallBlockConnector {
    float getValue();
};

float RBX_BallBlockConnector::getValue()
{
    int a = g_0xb98810;
    int b = g_0xb98814;
    int sum = b + a;
    if (sum == 0)
        return g_0x9ab804;
    return (float)a / (float)sum;
}
