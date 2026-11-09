// from server: 46% by atomic.potato
struct S
{
    void* field_100;
    float f();
};

float S::f()
{
    if (field_100)
    {
        struct V
        {
            float (__thiscall *get)();
        };
        return ((V*)*(void**)field_100)->get();
    }
    volatile float result = 0.0f;
    return result;
}
