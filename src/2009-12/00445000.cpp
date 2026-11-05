// from server: 43% by atomic.potato
struct S
{
    struct VTable
    {
        float (__cdecl *getValue)(void *);
    };

    void *field0;
    void *field4;
    void *field8;
    void *fieldC;
    void *field10;
    void *field14;
    void *field18;
    void *field1C;

    void f(float value);
};

extern "C" void sub_444f20(void *, float *);

void S::f(float value)
{
    float result = ((VTable *)*(void **)field1C)->getValue(field1C);
    sub_444f20(this, &result);
}
