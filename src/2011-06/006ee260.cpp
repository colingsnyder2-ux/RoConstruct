// from server: 46% by atomic.potato
struct BaseThreadPool {
    BaseThreadPool();
    float unknown30;
    float unknown34;
    float unknown38;
};

extern "C" void __cdecl InitializeBaseThreadPool();

BaseThreadPool::BaseThreadPool()
{
    InitializeBaseThreadPool();
    unknown30 = 0.0f;
    unknown34 = 0.0f;
    unknown38 = 0.0f;
}
