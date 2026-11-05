// from server: 68% by atomic.potato
float g_009af2dc;

struct S
{
    float a;
    float b;
    void f(float value);
};

void S::f(float value)
{
    a = value * g_009af2dc;
    b = 1.0f / (value * g_009af2dc * 2.0f);
}
