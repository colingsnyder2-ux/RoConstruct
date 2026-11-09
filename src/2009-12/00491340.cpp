// from server: 32% by atomic.potato
extern "C" void SleepStage(void *);

struct RbxEntity
{
    void f(void *);
};

void RbxEntity::f(void *value)
{
    SleepStage((char *)this + 0xdc);
}
