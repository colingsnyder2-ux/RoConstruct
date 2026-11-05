// from server: 52% by atomic.potato
extern "C" void __cdecl Call_0056db20(void *, void *, void *, unsigned long);

struct EquationDisplay
{
    void f(void *);
};

void EquationDisplay::f(void *arg)
{
    unsigned long value = *(unsigned long *)((char *)this + 8) + 4;
    Call_0056db20(arg, (char *)this + 4, (void *)value, 0);
}
