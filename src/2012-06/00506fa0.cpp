// from server: 100% by tester
struct GfxClustererPart
{
    void f();
};

void GfxClustererPart::f()
{
    int* p = *(int**)((char*)this + 4);
    if (*(GfxClustererPart**)((char*)p + 0x19c) == this)
        *(GfxClustererPart**)((char*)p + 0x19c) = 0;
}
