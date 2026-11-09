// from server: 73% by atomic.potato
struct Stage
{
};

struct Pipeline
{
    struct VTable
    {
        void (*remove)(Pipeline *, Stage *);
    };

    VTable *vtable;
};

extern "C" void removeFromStage(Pipeline *, Stage *);

struct SpatialFilter
{
    Pipeline *pipeline;
    void f(Stage *);
};

void SpatialFilter::f(Stage *stage)
{
    Pipeline *p = pipeline;
    p->vtable->remove(p, stage);
    removeFromStage((Pipeline *)stage, (Stage *)this);
}
