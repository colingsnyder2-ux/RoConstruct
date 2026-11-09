// from server: 30% by atomic.potato
struct Body
{
    int f();
};

struct Assembly
{
    void f();
};

int Body::f()
{
    return 0;
}

void Assembly::f()
{
    throw 15;
}
