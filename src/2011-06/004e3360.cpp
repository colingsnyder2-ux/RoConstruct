// from server: 75% by atomic.potato
struct S
{
    struct VTable
    {
        double (__thiscall *get)(void *, void *);
    };

    void *field_1c;
    void f(void *, void *);
};

extern "C" void sub_4e32b0(void *, double *);

void S::f(void *a, void *b)
{
    double value = ((VTable *)*(void **)field_1c)->get(field_1c, a);
    sub_4e32b0(b, &value);
}
