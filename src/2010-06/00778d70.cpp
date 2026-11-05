// from server: 22% by atomic.potato
struct S
{
    float a;
    float b;
    float c;
    float d;
    float e;
    float f_value;
    int g;
    int h;

    void f();
};

void S::f()
{
    a = 0.0f;
    b = 0.0f;
    c = 0.0f;
    d = 0.0f;
    e = 0.0f;
    f_value = 0.0f;
    g = 0;
    h = 0;
}
