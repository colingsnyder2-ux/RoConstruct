// from server: 14% by atomic.potato
struct RbxSceneUpdater {
    char pad0[8];
    float f8;
    char padC[8];
    int f14;
    int f18;
    void update(float* a, float* b, unsigned short* c);
};

extern float g_9af2dc;
extern float g_9aea18;
extern float g_9b1624;

extern "C" float sqrtf(float);

void RbxSceneUpdater::update(float* a, float* b, unsigned short* c)
{
    float xmm4 = 0.0f;
    if (!(f8 > xmm4) && !(f8 < xmm4))
        return;

    float xmm0 = g_9af2dc;
    unsigned short ax = c[0];
    if (ax == 0) {
        float xmm1 = f8 * xmm0;
        xmm1 += a[0];
        a[0] = xmm1;
        unsigned short dx = c[1];
        if (dx != 0) {
            int edx = (short)dx;
            if (edx != f18)
                goto L4011;
        }
        float xmm2 = f8 * xmm0;
        xmm2 += xmm1;
        a[0] = xmm2;
        goto L4011;
    }
    {
        int eax = (short)ax;
        if (eax == f14) {
            float xmm2 = f8 * xmm0;
            float xmm1 = a[0];
            xmm1 -= xmm2;
            a[0] = xmm1;
            unsigned short dx = c[1];
            if (dx != 0) {
                int edx = (short)dx;
                if (edx != f18)
                    goto L4011;
            }
            float xmm2b = f8 * xmm0;
            xmm1 -= xmm2b;
            goto L400D;
        }
        if (xmm4 > a[0]) {
            float xmm1 = f8 - b[0];
            goto L400D;
        }
        float xmm1b = b[0] - f8;
    L400D:
        a[0] = xmm1b;
    }
L4011:
    {
        unsigned short dx = c[1];
        if (dx != 0) {
            int edx = (short)dx;
            if (edx != f18)
                goto L403A;
        }
        float xmm1 = f8 * xmm0;
        float xmm2 = a[2];
        xmm2 -= xmm1;
        a[2] = xmm2;
        goto L4059;
    }
L403A:
    if (xmm4 > a[1]) {
        float xmm1 = f8 - b[1];
        a[1] = xmm1;
    } else {
        float xmm1 = b[1] - f8;
        a[1] = xmm1;
    }
L4059:
    {
        float xmm5 = g_9aea18;
        unsigned short dx = c[0];
        if (dx != 0) {
            int edx = (short)dx;
            if (edx != f14) {
                unsigned short dx2 = c[1];
                if (dx2 != 0) {
                    int edx2 = (short)dx2;
                    if (edx2 != f18) {
                        a[3] = xmm4;
                        a[4] = xmm4;
                        a[5] = xmm5;
                        goto L40F8;
                    }
                }
            }
        }
        {
            float xmm1 = f8 * xmm0;
            float xmm3 = a[0];
            float xmm0b = a[2];
            xmm0b -= xmm1;
            a[2] = xmm0b;
            float t = xmm3 * xmm3 + xmm0b * xmm0b;
            float inv = 1.0f / sqrtf(t);
            float xmm2 = inv * xmm3;
            float xmm3b = inv * xmm4;
            float xmm1b = inv * xmm0b;
            a[3] = xmm2;
            a[4] = xmm3b;
            a[5] = xmm1b;
        }
    L40F8:
        {
            float xmm0c = a[0];
            xmm0c /= b[0];
            float xmm1c = g_9b1624;
            float xmm2c = a[1];
            xmm0c += xmm5;
            a[9] = xmm0c;
            float xmm0d = b[1];
            xmm2c += xmm0d;
            xmm0d *= xmm1c;
            xmm2c /= xmm0d;
            xmm2c *= xmm1c;
            xmm1c -= xmm2c;
            a[10] = xmm1c;
        }
    }
}
