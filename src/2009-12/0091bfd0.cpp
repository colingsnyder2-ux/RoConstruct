// from server: 8% by atomic.potato
struct PartChunk
{
    void f();
};

struct AggregatingSceneManager
{
    void f();
};

void PartChunk::f()
{
}

void AggregatingSceneManager::f()
{
    PartChunk *p = (PartChunk *)((char *)this + 8);
    p->f();
}
