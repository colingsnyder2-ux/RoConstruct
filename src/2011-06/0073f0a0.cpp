// from server: 41% by atomic.potato
struct Scale9Frame {
    char pad0[0x16c];
    short field_16c;
    short field_16e;
    short field_170;
    char pad1[0x18c - 0x172];
    float field_18c;
    void method(float, float, float, float, void*, void*, void*);
};

extern "C" void __stdcall sub_6a76c0(void*, void*, void*, void*, void*, void*);

void Scale9Frame::method(float a, float b, float c, float d, void* p1, void* p2, void* p3)
{
    float v0 = (float)(field_16c * 3);
    float v1 = (float)(field_16e * 3);
    float z = 0.0f;
    sub_6a76c0(p1, &field_170, &field_16c, &v0, &field_18c, &z);
}
