// from server: 53% by atomic.potato
typedef float float4;

extern "C" float4 g_0xc03cc4[4];

void sub_4e0ea0(float4 *p)
{
    p[4] = g_0xc03cc4[0];
    p[5] = g_0xc03cc4[1];
    p[6] = g_0xc03cc4[2];
}
