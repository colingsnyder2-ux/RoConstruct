// from server: 54% by atomic.potato
extern "C" float G1_func_00454a30(int);

struct S
{
    int f(int);
    int value;
};

int S::f(int value)
{
    float converted = G1_func_00454a30(value);
    int *object = (int *)this->value;
    int (__thiscall *method)(int *, float *, int) =
        (int (__thiscall *)(int *, float *, int))(*(int *)object + 12);
    return method(object, &converted, value);
}
