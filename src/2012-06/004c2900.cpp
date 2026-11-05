// from server: 75% by atomic.potato
struct S
{
    struct V
    {
        float x;
        float y;
        float z;
        float w;
        float a;
        float b;
        float c;
        float d;
        float e;
        float f;
        float g;
        float h;
        float i;
        float j;
        float k;
        float l;
        float m;
        float n;
        float o;
        float p;
        float q;
        float r;
        float s;
        float t;
        float u;
        float v;
        float q24;
        float q28;
        float q2c;
    };

    V value;
    void f(const V& v);
};

void S::f(const V& v)
{
    value = v;
    value.q24 = v.q24;
    value.q28 = v.q28;
    value.q2c = v.q2c;
}
