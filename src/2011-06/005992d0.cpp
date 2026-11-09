// from server: 92% by atomic.potato
struct PhysicsJob
{
    char padding[480];
    double value;

    void f(double *out, const double *factor);
};

void PhysicsJob::f(double *out, const double *factor)
{
    *out = value * *factor;
    *((char *)out + 8) = 0;
}
