// from server: 54% by atomic.potato
typedef float __cdecl FloatFunc(float);
typedef void (__thiscall *Method)(void *, float *, float);

extern "C" float __cdecl G1_func_004481b0(float);

struct S
{
    int padding[7];
    void f(float value);
};

void S::f(float value)
{
    float converted = G1_func_004481b0(value);
    void *object = *(void **)((char *)this + 0x1c);
    void **vtable = *(void ***)object;
    Method method = (Method)vtable[4];
    method(object, &converted, value);
}
