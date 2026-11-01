// from server: 64% by atomic.potato
struct TreeStage
{
    int field8;
    void f(void *);
};

extern "C" void call_7efa10(int *, void *);
extern "C" void call_7a1d00(void *, TreeStage *);

void TreeStage::f(void *arg)
{
    call_7efa10((int *)field8, arg);
    call_7a1d00(arg, this);
}
