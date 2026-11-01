// from server: 80% by atomic.potato
struct S {
    char pad0[0x10];
    char pad1[0x10];
    float f20;
    float f24;
    int i28;
    int i2c;
    float f30;
    char pad34[4];
    int i38;
    S* ctor(const S* a, const S* b, float x, int y, int z, float w);
};

S* S::ctor(const S* a, const S* b, float x, int y, int z, float w)
{
    *(int*)((char*)this + 0x00) = *(int*)((char*)a + 0x00);
    *(int*)((char*)this + 0x04) = *(int*)((char*)a + 0x04);
    *(int*)((char*)this + 0x08) = *(int*)((char*)a + 0x08);
    *(int*)((char*)this + 0x0c) = *(int*)((char*)a + 0x0c);
    *(int*)((char*)this + 0x10) = *(int*)((char*)b + 0x00);
    *(int*)((char*)this + 0x14) = *(int*)((char*)b + 0x04);
    *(int*)((char*)this + 0x18) = *(int*)((char*)b + 0x08);
    *(int*)((char*)this + 0x1c) = *(int*)((char*)b + 0x0c);
    f20 = 0.0f;
    f24 = x;
    i28 = y;
    i2c = z;
    f30 = w;
    i38 = 0;
    return this;
}
