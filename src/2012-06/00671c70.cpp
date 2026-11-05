// from server: 25% by atomic.potato
extern "C" float __cdecl function_983bca(float);

struct S
{
    char padding[0xa4];
    float value;
    float f();
};

float S::f()
{
    float x = value;
    x = function_983bca(x);
    return x;
}
