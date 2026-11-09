// from server: 52% by atomic.potato
struct S
{
    int value;
};

double g_0xa66290;

struct ContentProviderJob
{
    void f(double* result, double value);
    int member_0x240;
};

void ContentProviderJob::f(double* result, double value)
{
    int v = member_0x240;
    *result = (double)(v < 0 ? v + g_0xa66290 : v) * value;
    ((char*)result)[8] = 0;
}
