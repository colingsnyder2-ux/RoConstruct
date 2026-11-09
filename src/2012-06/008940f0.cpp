// from server: 41% by atomic.potato
struct RBX_BallBlockConnector
{
    float GetRatio();
};

extern int g_8940f0_a;
extern int g_8940f0_b;
extern float g_8940f0_c;

float RBX_BallBlockConnector::GetRatio()
{
    int a = g_8940f0_a;
    int b = g_8940f0_b;
    int sum = b + a;
    if (sum == 0)
        return g_8940f0_c;
    return (float)a / (float)sum;
}
