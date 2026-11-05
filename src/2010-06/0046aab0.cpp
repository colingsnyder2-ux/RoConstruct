// from server: 71% by atomic.potato
typedef double (__thiscall *GetValueFn)(void *);
typedef void (__thiscall *SetValueFn)(void *, const double *);

struct S
{
    char padding[0xc0];
    double GetValue();
    void SetValue(const double *);
    void f();
};

void S::f()
{
    double value = GetValue();
    SetValue(&value);
}
