// from server: 46% by atomic.potato
extern float g_004e0780;

int f_004e0780(float a, float b)
{
    return (a == b || (a - b < 0.0f ? b - a : a - b) >= g_004e0780) ? 1 : 0;
}
