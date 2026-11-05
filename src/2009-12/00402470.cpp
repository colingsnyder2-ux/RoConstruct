// from server: 51% by atomic.potato
extern "C" void SleepStage(void *, void *);

struct S
{
    void f();
};

void S::f()
{
    *(int *)this = 0x99f56c;
    SleepStage((void *)0xb794d8, this);
}
