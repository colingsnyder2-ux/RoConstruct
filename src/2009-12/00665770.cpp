// from server: 72% by atomic.potato
struct S
{
    void *f(double);
};

extern "C" void *__cdecl call_007e7820(double);
extern "C" void call_007eac30(void *);

void *S::f(double value)
{
    void *p = call_007e7820(value);
    call_007eac30(p);
    return p;
}
