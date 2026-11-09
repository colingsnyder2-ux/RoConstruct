// from server: 49% by atomic.potato
struct BaseThreadPool
{
    BaseThreadPool* initialize();
    int unused00[12];
    float field30;
    float field34;
    float field38;
};

BaseThreadPool* BaseThreadPool::initialize()
{
    initialize();
    field30 = 0.0f;
    field34 = 0.0f;
    field38 = 0.0f;
    return this;
}
