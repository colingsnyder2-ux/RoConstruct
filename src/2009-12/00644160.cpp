// from server: 51% by atomic.potato
extern "C" void __cdecl sub_6bc2a0(float*, float*);

struct Inner
{
    virtual float get(int);
};

struct S
{
    char padding[0x1c];
    Inner* inner;
    float f(int);
};

float S::f(int a)
{
    float tmp = inner->get(a);
    float result;
    sub_6bc2a0(&result, &tmp);
    return result;
}
