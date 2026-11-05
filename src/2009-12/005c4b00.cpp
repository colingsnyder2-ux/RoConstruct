// from server: 74% by atomic.potato
extern "C" void *__cdecl sym(void *);

struct S
{
    void *f(void *);
    char padding[40];
    float value;
};

void *S::f(void *arg)
{
    sym(arg);
    value = 0.0f;
    return this;
}
