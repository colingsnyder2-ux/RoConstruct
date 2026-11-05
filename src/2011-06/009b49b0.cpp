// from server: 58% by atomic.potato
struct PyramidBuilder {
    void* vtable;
    int field4;
    char pad8[0x2C];
    void construct(int, const void*);
};

void PyramidBuilder::construct(int a, const void* src)
{
    vtable = (void*)0xaf8bf8;
    field4 = a;
    char* d = (char*)this;
    const char* s = (const char*)src;
    *(int*)(d + 8) = *(const int*)(s + 0);
    *(int*)(d + 0xc) = *(const int*)(s + 4);
    *(int*)(d + 0x10) = *(const int*)(s + 8);
    *(int*)(d + 0x14) = *(const int*)(s + 0xc);
    *(int*)(d + 0x18) = *(const int*)(s + 0x10);
    *(int*)(d + 0x1c) = *(const int*)(s + 0x14);
    *(int*)(d + 0x20) = *(const int*)(s + 0x18);
    *(float*)(d + 0x24) = *(const float*)(s + 0x1c);
    *(float*)(d + 0x28) = *(const float*)(s + 0x20);
    *(float*)(d + 0x2c) = *(const float*)(s + 0x24);
    vtable = (void*)0xaf8c28;
    *(float*)(d + 0x30) = *(const float*)(s + 0x2c);
    *(int*)(d + 0x34) = *(const int*)(s + 0);
    *(int*)(d + 0x38) = *(const int*)(s + 4);
    *(int*)(d + 0x3c) = *(const int*)(s + 8);
    *(int*)(d + 0x40) = *(const int*)(s + 0xc);
    *(int*)(d + 0x44) = *(const int*)(s + 0x10);
    *(int*)(d + 0x48) = *(const int*)(s + 0x14);
    *(int*)(d + 0x4c) = *(const int*)(s + 0x18);
    *(float*)(d + 0x50) = *(const float*)(s + 0x1c);
    *(float*)(d + 0x54) = *(const float*)(s + 0x20);
    *(float*)(d + 0x58) = *(const float*)(s + 0x24);
    *(int*)(d + 0x5c) = *(const int*)(s + 0x28);
    *(float*)(d + 0x60) = *(const float*)(s + 0x2c);
}
