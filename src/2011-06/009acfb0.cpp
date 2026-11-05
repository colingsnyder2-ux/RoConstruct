// from server: 58% by atomic.potato
struct CylinderBuilder {
    void* vtable;
    int field4;
    char pad8[0x1C];
    float f24;
    float f28;
    float f2c;
    void construct(int a, const void* src);
};

void CylinderBuilder::construct(int a, const void* src) {
    const char* s = (const char*)src;
    field4 = a;
    vtable = (void*)0xaf7164;
    *(int*)((char*)this + 8) = *(const int*)(s + 0);
    *(int*)((char*)this + 0xc) = *(const int*)(s + 4);
    *(int*)((char*)this + 0x10) = *(const int*)(s + 8);
    *(int*)((char*)this + 0x14) = *(const int*)(s + 0xc);
    *(int*)((char*)this + 0x18) = *(const int*)(s + 0x10);
    *(int*)((char*)this + 0x1c) = *(const int*)(s + 0x14);
    *(int*)((char*)this + 0x20) = *(const int*)(s + 0x18);
    f24 = *(const float*)(s + 0x1c);
    f28 = *(const float*)(s + 0x20);
    f2c = *(const float*)(s + 0x24);
    vtable = (void*)0xaf8bd8;
}
