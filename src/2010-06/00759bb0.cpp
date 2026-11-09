// from server: 47% by atomic.potato
struct WedgePoly
{
    float value8;
    float valueC;
    void get(float *out);
};

extern float g_scale1;
extern float g_scale2;

void WedgePoly::get(float *out)
{
    out[0] = 0.0f;
    out[1] = value8 * g_scale1;
    out[2] = valueC * g_scale2;
}
