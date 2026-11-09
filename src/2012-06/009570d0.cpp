// from server: 58% by atomic.potato
extern "C" void __stdcall sub_00955b80(float *, float);

struct S
{
    void f(float);
};

void S::f(float value)
{
    float local = value;
    sub_00955b80(&local, value);
}
