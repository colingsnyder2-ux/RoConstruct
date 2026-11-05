// from server: 41% by atomic.potato
struct S;

typedef float (__thiscall *GetValue)(void *, float);
extern "C" void __cdecl helper(S *, float *);

struct S {
    void *field0;
    char pad[24];

    void __thiscall f(float value);
};

void __thiscall S::f(float value)
{
    void *object = *(void **)((char *)this + 28);
    void *vtable = *(void **)object;
    GetValue getValue = (GetValue)*(void **)((char *)vtable + 8);
    float result = getValue(object, value);
    helper(this, &result);
}
