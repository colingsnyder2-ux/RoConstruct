// from server: 29% by atomic.potato
struct S
{
    void* f(void*);
    void g(void*);
};

void S::g(void* value)
{
    f((char*)value + 4);
}

void* S::f(void* value)
{
    return value;
}
