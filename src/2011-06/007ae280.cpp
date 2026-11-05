// from server: 72% by atomic.potato
struct S
{
    char padding[208];
    int fieldD0;
    float fieldD4;

    void f();
};

extern "C" void __cdecl function_0079b310(float, int);

void S::f()
{
    if (fieldD0)
        function_0079b310(fieldD4, fieldD0);
}
