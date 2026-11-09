// from server: 100% by colin
struct Flag {
    char pad[0x168];
    void* field_168;
    char pad2[0x220 - 0x16c];
    void* field_220;
    Flag* construct(int);
};

extern "C" void __stdcall sub_5d4ad0(int);

Flag* Flag::construct(int arg) {
    if (arg != 0) {
        field_168 = (void*)0x7bb71c;
        field_220 = (void*)0x7a4ccc;
    }
    sub_5d4ad0(0);
    void* p = field_168;
    *(void**)((char*)this + 0x00) = (void*)0x7bd374;
    *(void**)((char*)this + 0x04) = (void*)0x7bd36c;
    *(void**)((char*)this + 0x10) = (void*)0x7bd364;
    *(void**)((char*)this + 0x14) = (void*)0x7bd354;
    *(void**)((char*)this + 0x2c) = (void*)0x7bd344;
    *(void**)((char*)this + 0x44) = (void*)0x7bd334;
    *(void**)((char*)this + 0x5c) = (void*)0x7bd324;
    *(void**)((char*)this + 0x74) = (void*)0x7bd314;
    *(void**)((char*)this + 0x8c) = (void*)0x7bd304;
    *(void**)((char*)this + 0xe8) = (void*)0x7bd2fc;
    *(void**)((char*)this + 0x158) = (void*)0x7bd2e4;
    int* q = *(int**)((char*)p + 4);
    *(void**)((char*)q + (int)this + 0x168) = (void*)0x7bd2dc;
    void* r = field_168;
    int* s = *(int**)((char*)r + 4);
    int t = (int)s - 0xb8;
    *(int*)((char*)s + (int)this + 0x164) = t;
    return this;
}
