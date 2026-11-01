// from server: 64% by atomic.potato
struct S
{
    int field8;
    void f(void *);
};

extern "C" void call_007ba860(void *, void *);
extern "C" void call_007b2f40(void *, void *);

void S::f(void *stage)
{
    call_007ba860((void *)field8, stage);
    call_007b2f40(stage, this);
}
