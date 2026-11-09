// from server: 59% by atomic.potato
struct G3D_BinaryInput {
    float x;
    float y;
    float z;
    float w;
    G3D_BinaryInput& setLength(float len);
};

extern float g_9a6a88;
extern float g_9aea18;
extern double g_b7cc08;
extern unsigned char g_b7cc10;
extern double* g_98b5b0;

G3D_BinaryInput& G3D_BinaryInput::setLength(float len) {
    if (!(len == g_9a6a88)) {
        float s = g_9aea18 / len;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
    if (!(g_b7cc10 & 1)) {
        g_b7cc10 |= 1;
        g_b7cc08 = *g_98b5b0;
    }
    x = (float)g_b7cc08;
    if (!(g_b7cc10 & 1)) {
        g_b7cc10 |= 1;
        g_b7cc08 = *g_98b5b0;
    }
    y = (float)g_b7cc08;
    if (!(g_b7cc10 & 1)) {
        g_b7cc10 |= 1;
        g_b7cc08 = *g_98b5b0;
    }
    z = (float)g_b7cc08;
    if (!(g_b7cc10 & 1)) {
        g_b7cc10 |= 1;
        g_b7cc08 = *g_98b5b0;
    }
    w = (float)g_b7cc08;
    return *this;
}
