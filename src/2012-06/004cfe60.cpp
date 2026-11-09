// from server: 69% by atomic.potato
extern "C" void __cdecl Ogre_NedPoolingImpl_deallocBytes(void *);

struct GfxClustererPart
{
    void f();
    int pad0;
    int pad1;
    int pad2;
    int field10;
    int field14;
};

extern void GfxClustererPart_004cfd10(GfxClustererPart *, int *, int, int);

void GfxClustererPart::f()
{
    int value;
    GfxClustererPart_004cfd10(this, &value, field10, *(int *)field10);
    Ogre_NedPoolingImpl_deallocBytes((void *)field10);
    field10 = 0;
    field14 = 0;
}
