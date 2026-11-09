// from server: 61% by atomic.potato
struct RotateConnector
{
    char pad[0x78];
    float field78;
    float field7c;
    void SetAngle(float angle);
};

extern "C" double __stdcall func_0080b906(double);
extern "C" float __stdcall func_006ccbb0(float, float);
extern "C" unsigned int __stdcall func_0079f670();

extern const double g_a9bd18;
extern const double g_a9bd28;
extern const double g_a9bd30;
extern const double g_a9bd38;

void RotateConnector::SetAngle(float angle)
{
    double v = (double)angle;
    double result;
    if (v < g_a9bd38)
    {
        result = func_0080b906((v + g_a9bd18) * g_a9bd30) * g_a9bd28 - v;
    }
    else if (v > g_a9bd18)
    {
        result = v;
    }
    else
    {
        result = func_0080b906((v + g_a9bd18) * g_a9bd30) * g_a9bd28 - v;
    }
    float f = func_006ccbb0(field78, (float)result);
    field7c = f / (float)func_0079f670();
}
