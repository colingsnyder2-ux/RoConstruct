// from server: 100% by colin
struct LegacyHopperService {
    void construct();
    LegacyHopperService* init();
};

extern "C" void __fastcall sub_59dce0(LegacyHopperService* self);

LegacyHopperService* LegacyHopperService::init() {
    sub_59dce0(this);
    *(int*)((char*)this + 0x00) = 0x7b2634;
    *(int*)((char*)this + 0x04) = 0x7b2628;
    *(int*)((char*)this + 0x10) = 0x7b2620;
    *(int*)((char*)this + 0x14) = 0x7b2610;
    *(int*)((char*)this + 0x2c) = 0x7b2600;
    *(int*)((char*)this + 0x44) = 0x7b25f0;
    *(int*)((char*)this + 0x5c) = 0x7b25e0;
    *(int*)((char*)this + 0x74) = 0x7b25d0;
    *(int*)((char*)this + 0x8c) = 0x7b25c0;
    *(int*)((char*)this + 0xe8) = 0x7b25b8;
    return this;
}
