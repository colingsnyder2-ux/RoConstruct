// from server: 49% by atomic.potato
struct S
{
    struct V
    {
        double (*f)(void *, double);
    };

    void *vtable;
    char pad[24];
    void *value;

    void f(double value);
};

extern "C" void sub_528f10(S *, double *);

void S::f(double value)
{
    V *v = *(V **)this->value;
    double result = v->f(this->value, value);
    sub_528f10(this, &result);
}
