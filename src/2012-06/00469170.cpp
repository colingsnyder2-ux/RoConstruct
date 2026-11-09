// from server: 55% by atomic.potato
typedef float (__thiscall *TransformFunction)(int *, float *);

struct S {
    int field28;
    float f(int value);
};

extern "C" float __cdecl sub_4690a0(int);

float S::f(int value)
{
    float result = sub_4690a0(value);
    int *object = *(int **)((char *)this + 0x28);
    TransformFunction function =
        *(TransformFunction *)(*(int **)((char *)object) + 12);
    return function(object, &result);
}
