// from server: 41% by atomic.potato
extern int g_0xe52544;
extern int g_0xe52548;
extern float g_0xb5abb8;

struct RBX_BallBlockConnector {
    float getValue();
};

float RBX_BallBlockConnector::getValue()
{
    int a = g_0xe52544;
    int b = g_0xe52548;
    int sum = b + a;
    if (sum == 0)
        return g_0xb5abb8;
    return (float)a / (float)sum;
}
