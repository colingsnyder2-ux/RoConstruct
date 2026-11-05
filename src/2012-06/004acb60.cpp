// from server: 43% by atomic.potato
struct S
{
    int value;
    int unused;
};

struct DxUserInput
{
};

void __cdecl f(float* result, S* source)
{
    result[0] = 0.0f;
    result[1] = 0.0f;

    float value = (float)source->unused;
    if (source->value == 0)
        result[0] = value;
    else
        result[1] = value;
}
