// from server: 77% by atomic.potato
struct GenericJob
{
    int value;
    void f(double*, double*);
};

double g_9a44d0 = 2147483648.0;

void GenericJob::f(double* result, double* multiplier)
{
    int value = *(int*)((char*)this + 0x1f4);
    double converted = (double)value;
    if (value < 0)
        converted += g_9a44d0;
    converted *= *multiplier;
    *result = converted;
    *((char*)result + 8) = value > 0 ? 1 : 0;
}
