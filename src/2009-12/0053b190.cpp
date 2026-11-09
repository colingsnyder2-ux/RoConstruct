// from server: 55% by atomic.potato
struct S
{
    void __cdecl f(float, void *);
};

extern "C" void __cdecl sub_539d90(float *);
extern "C" void __cdecl sub_532eb0(void *, float);

void S::f(float value, void *arg)
{
    float result;
    sub_539d90(&result);
    sub_532eb0(arg, result);
}
