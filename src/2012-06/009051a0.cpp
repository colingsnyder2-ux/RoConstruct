// from server: 95% by Intel
extern "C" double g_00b4fd78;

struct ContentProviderJob
{
    void f(double* value, double* scale);
};

void ContentProviderJob::f(double* value, double* scale)
{
    unsigned int resolution = *(int*)((char*)this + 0x278);
    *(char*)((char*)value + 8) = 0;
    double result = (double)resolution;
    if (resolution < 0)
        result += g_00b4fd78;
    value[0] = result * *scale;
}
