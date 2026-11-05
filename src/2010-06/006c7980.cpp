// from server: 47% by atomic.potato
struct S_func_006c7980 {
    float __cdecl f(void *object, float value);
};

float S_func_006c7980::f(void *object, float value)
{
    typedef float (__thiscall *Function)(void *, float);
    Function function = *(Function *)*(void **)((char *)object + 4);
    return function(object, value);
}
