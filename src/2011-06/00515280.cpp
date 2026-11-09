// from server: 61% by atomic.potato
extern "C" void __stdcall sub_007fddb0(void *, int *, double);

struct SendDataJob
{
    int pad[122];
    float value;
    int f(int, int);
};

int SendDataJob::f(int a, int b)
{
    int *p;
    p = (int *)0;
    sub_007fddb0((void *)((char *)this + 0x1e8), p, (double)value);
    return (int)p;
}
