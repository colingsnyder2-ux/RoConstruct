// from server: 56% by atomic.potato
struct PhysicsJob
{
    double value;
    void GetValue(void *, double *);
};

void PhysicsJob::GetValue(void *result, double *factor)
{
    *(double *)result = *(double *)0x1d0 * *factor;
    *(unsigned char *)((char *)result + 8) = 0;
}
