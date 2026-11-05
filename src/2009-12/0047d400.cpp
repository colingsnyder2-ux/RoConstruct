// from server: 56% by atomic.potato
struct S
{
    int f(int);
};

extern "C" void SleepStage_call(void *, int *);

int S::f(int value)
{
    int *p = &value;
    SleepStage_call((char *)this + 0x20, p);
    return 0;
}
