// from server: 45% by atomic.potato
extern "C" void __cdecl func_00783c10(float*, float*, float*, float*, float*);

float g_b7cc20;
float g_b7cc24;
float g_b7cc28;
int g_b7cc2c;

void __fastcall func_00783e50(float x, float y, float z, float* out, float* in, float w)
{
    float a = g_b7cc20;
    float b = y;
    float c = z;

    if (!(g_b7cc2c & 1))
    {
        g_b7cc2c |= 1;
        g_b7cc20 = x;
        g_b7cc24 = x;
        g_b7cc28 = x;
    }

    if (in[0] != a || in[1] != b || in[2] != c)
    {
        if (!(g_b7cc2c & 1))
        {
            g_b7cc2c |= 1;
            g_b7cc20 = x;
            g_b7cc24 = x;
            g_b7cc28 = x;
        }
        func_00783c10(&g_b7cc20, in, &a, &b, &c);
    }

    out[0] = a;
    out[1] = b;
    out[2] = c;
}
