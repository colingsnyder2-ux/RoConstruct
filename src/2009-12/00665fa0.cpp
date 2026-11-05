// from server: 100% by atomic.potato
struct S {
    double f();
    char pad[0xa98];
    void *field;
};

double S::f()
{
    struct T {
        char pad[0xb0];
        double value;
    };
    return ((T *)field)->value;
}
