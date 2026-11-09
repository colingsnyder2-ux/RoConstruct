// from server: 100% by atomic.potato
struct GfxClustererPart
{
    int unused;
    int* field_4;
    void f();
};

void GfxClustererPart::f()
{
    if (field_4[91] == (int)this)
        field_4[91] = 0;
}
