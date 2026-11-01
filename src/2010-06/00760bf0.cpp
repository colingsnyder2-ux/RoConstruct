// from server: 20% by atomic.potato
struct Assembly
{
    void removeFromStage(void *);
};

struct SleepStage
{
    void f(void *);
};

void Assembly::removeFromStage(void *)
{
}

void SleepStage::f(void *stage)
{
    Assembly *assembly = (Assembly *)this;
    assembly->removeFromStage(stage);
}
