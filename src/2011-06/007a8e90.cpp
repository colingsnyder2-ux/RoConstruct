// from server: 47% by atomic.potato
extern float g_00abcd24;
extern float g_00a7fb4c;

struct WedgePoly
{
    void getValue(float* result);
};

void WedgePoly::getValue(float* result)
{
    result[0] = 0.0f;
    result[1] = *(float*)((char*)this + 8) * g_00abcd24;
    result[2] = *(float*)((char*)this + 12) * g_00a7fb4c;
}
