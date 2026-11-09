// from server: 46% by atomic.potato
struct MegaTextureProxy
{
    MegaTextureProxy();
};

MegaTextureProxy::MegaTextureProxy()
{
    int* p = (int*)((char*)this + 8);
    p[0] = 0;
    p[1] = 0;
}
