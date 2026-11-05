// from server: 84% by atomic.potato
struct PhysicsJob
{
    double value;
    int pad[57];
    double factor;
    void f(double* result, const double* multiplier);
};

void PhysicsJob::f(double* result, const double* multiplier)
{
    *result = factor * *multiplier;
    ((char*)result)[8] = 0;
}
