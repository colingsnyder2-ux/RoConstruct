// from server: 76% by atomic.potato
struct S
{
    int (*callable)(float, float, float, float);
    int value10;
    int value14;
    int value18;
    int f(float, float, float, float);
};

int S::f(float a, float b, float c, float d)
{
    return callable(d, c, b, a);
}
