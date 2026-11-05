// from server: 68% by atomic.potato
extern void G1_func_0092e8e0(void*, void*, void*, void*);
extern "C" void __cdecl Ogre_NedPoolingImpl_deallocBytes(void*);

struct GfxClustererPart
{
    int pad0[4];
    void* field10;
    void* field14;
    int f();
};

int GfxClustererPart::f()
{
    void* p = field10;
    G1_func_0092e8e0(this, &p, *(void**)p, p);
    Ogre_NedPoolingImpl_deallocBytes(field10);
    field10 = 0;
    field14 = 0;
    return 0;
}
