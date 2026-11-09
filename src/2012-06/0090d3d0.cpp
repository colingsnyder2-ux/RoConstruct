// from server: 47% by atomic.potato
struct V
{
    float x;
    float y;
    float z;
};

struct WedgePoly
{
    float a;
    float b;
    float c;
    float d;
    void f(V *);
};

float g1;
float g2;

void WedgePoly::f(V *out)
{
    out->x = 0.0f;
    out->y = c * g1;
    out->z = d * g2;
}
