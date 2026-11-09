// from server: 53% by atomic.potato
extern "C" int call_00701650(void);
extern "C" void call_007ba690(const void *, const void *, int);

struct AssemblyStage
{
    void f(void *);
};

void AssemblyStage::f(void *value)
{
    int result = call_00701650();
    call_007ba690(value, (const void *)0x7d9e60, result);
}
