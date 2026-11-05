// from server: 32% by atomic.potato
extern "C" void* __stdcall assign_string(void*, const void*);

struct RbxMaterialAdapter {
    char pad0[0x44];
    void* field44;
    char pad1[0x28];
    int field70;
    char pad2[0x24];
    int field98;
    float field9c;
    float fielda0;
    float fielda4;
    float fielda8;
};

RbxMaterialAdapter* __stdcall copy_range(RbxMaterialAdapter* first, RbxMaterialAdapter* last, RbxMaterialAdapter* dest) {
    if (first == last) return dest;
    RbxMaterialAdapter* src = first;
    RbxMaterialAdapter* dst = dest;
    do {
        assign_string(&dst->field44, &src->field44);
        dst->field70 = src->field70;
        assign_string(&dst->field98, &src->field98);
        dst->field9c = src->field9c;
        dst->fielda0 = src->fielda0;
        dst->fielda4 = src->fielda4;
        dst->fielda8 = src->fielda8;
        src++;
        dst++;
    } while (src != last);
    return dst;
}
