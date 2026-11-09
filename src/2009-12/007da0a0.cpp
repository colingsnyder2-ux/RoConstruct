// from server: 18% by atomic.potato
struct S
{
    void first(void *);
    void second(void *);

    void f(void *value);
};

void S::second(void *value)
{
}

void S::first(void *value)
{
}

void S::f(void *value)
{
    first(value);
    second(value);
}
