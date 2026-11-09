// from server: 32% by atomic.potato
struct S
{
    int f(float);
};

extern "C" void __cdecl sub_63aa30(int, int, int);

int S::f(float value)
{
    int ecx_value = *(int*)this;
    int edx_value = *(int*)&value;
    int eax_value = 0x63a900;

    if (ecx_value)
        sub_63aa30(eax_value, edx_value, ecx_value);

    return 0;
}
