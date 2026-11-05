// from server: 36% by atomic.potato
struct MegaTextureProxy
{
    void f(void*, void*, void*);
};

void MegaTextureProxy::f(void* a, void* b, void* c)
{
    *(int*)b = 0;
    *(int*)a = 0;
    *((int*)b + 1) = 0;
}
