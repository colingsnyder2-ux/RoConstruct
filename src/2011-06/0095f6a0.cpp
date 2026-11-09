// from server: 100% by atomic.potato
struct GfxClustererPart
{
    void f();
};

void GfxClustererPart::f()
{
    int* p = *(int**)((char*)this + 4);
    if (*(GfxClustererPart**)((char*)p + 0x16c) == this)
        *(GfxClustererPart**)((char*)p + 0x16c) = 0;
}
