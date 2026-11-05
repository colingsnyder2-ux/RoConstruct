// from server: 20% by atomic.potato
struct RbxSceneUpdater
{
    void f(void *);
};

struct RbxEntity
{
    void f(void *);
};

void RbxSceneUpdater::f(void *)
{
}

void RbxEntity::f(void *value)
{
    ((RbxSceneUpdater *)((char *)this + 0xdc))->f(&value);
}
