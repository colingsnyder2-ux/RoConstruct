// from server: 30% by atomic.potato
extern int g_0xc2292c;
extern int g_0xc22930;
extern float g_0xa0c610;

struct RBX_BallBlockConnector {
    float getValue();
};

float RBX_BallBlockConnector::getValue()
{
    int a = g_0xc2292c;
    int b = g_0xc22930;
    int sum = b + a;
    if (sum != 0) {
        float fa = (float)a;
        float fb = (float)sum;
        return fa / fb;
    }
    return g_0xa0c610;
}
