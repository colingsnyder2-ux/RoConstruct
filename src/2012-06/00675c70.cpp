// from server: 26% by atomic.potato
struct S
{
    float value;
    float f();
};

extern "C" float sub_00686ab0(float *, float);

float S::f()
{
    float local;
    value = sub_00686ab0(&local, value);
    return value;
}
