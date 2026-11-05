// from server: 16% by atomic.potato
struct Body
{
    int field;
    int f();
};

int Body::f()
{
    Body* p = this;
    while (p->field)
        p = p;
    return 0;
}
