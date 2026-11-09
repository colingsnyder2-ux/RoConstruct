// from server: 39% by colin
struct FlagStandService {
    char pad[0x298];
    void* field_298;
    void* field_294;
    void* field_ec;
    void* field_c;
    void* field_0;
    void* field_4;
    void* field_10;
    void* field_14;
    void* field_2c;
    void* field_44;
    void* field_5c;
    void* field_74;
    void* field_8c;
    void* field_e8;
    void* field_158;
    void* field_170;
    void* field_17c;
    void construct(void* arg);
};

extern "C" void __stdcall sub_5912a0();
extern "C" void __stdcall sub_5e9ae0();

void FlagStandService::construct(void* arg) {
    void* p = field_298;
    field_294 = (void*)0x7a4cac;
    void* q = *(void**)((char*)p + 4);
    *(void**)((char*)q + (int)this + 0x298) = (void*)0x7a4ca4;
    sub_5e9ae0();
    void* r = field_ec;
    field_0 = (void*)0x7be044;
    field_4 = (void*)0x7be03c;
    field_10 = (void*)0x7be034;
    field_14 = (void*)0x7be024;
    field_2c = (void*)0x7be014;
    field_44 = (void*)0x7be004;
    field_5c = (void*)0x7bdff4;
    field_74 = (void*)0x7bdfe4;
    field_8c = (void*)0x7bdfd4;
    field_e8 = (void*)0x7bdfc8;
    field_158 = (void*)0x7bdfb8;
    field_170 = (void*)0x7bdfac;
    field_17c = (void*)0x7bdf94;
    void* s = *(void**)((char*)r + 4);
    *(void**)((char*)s + (int)this + 0xec) = (void*)0x7bdf88;
    void* t = field_ec;
    void* u = *(void**)((char*)t + 8);
    *(void**)((char*)u + (int)this + 0xec) = (void*)0x7bdf80;
    void* v = field_ec;
    void* w = *(void**)((char*)v + 0xc);
    *(void**)((char*)w + (int)this + 0xec) = (void*)0x7bdf64;
    void* x = field_ec;
    void* y = *(void**)((char*)x + 4);
    *(void**)((char*)y + (int)this + 0xe8) = (void*)((char*)y - 0x198);
    void* z = field_ec;
    void* aa = *(void**)((char*)z + 8);
    *(void**)((char*)aa + (int)this + 0xe8) = (void*)((char*)aa - 0x1a0);
    void* ab = field_ec;
    void* ac = *(void**)((char*)ab + 0xc);
    *(void**)((char*)ac + (int)this + 0xe8) = (void*)((char*)ac - 0x1a8);
    sub_5912a0();
    field_c = (void*)0;
}
