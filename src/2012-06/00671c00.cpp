// from server: 27% by atomic.potato
struct S
{
    struct T
    {
        char pad[8];
        double value;
    };

    T *f(int, T *);
    double g();
};

double S::g()
{
    T local;
    return f(-1, &local)->value;
}
