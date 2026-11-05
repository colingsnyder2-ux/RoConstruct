// from server: 87% by atomic.potato
struct Stage
{
    void first(void *);
    void second(void *);
};

struct AssemblyStage
{
    void *field8;
    void first(void *);
    void second(void *);
    void f(void *);
};

void AssemblyStage::f(void *arg)
{
    first(arg);
    second(arg);
    ((Stage *)arg)->first(this);
}
