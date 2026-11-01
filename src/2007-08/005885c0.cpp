// from server: 100% by colin
struct SoundChannel {
    void construct();
};

extern char G1_007aebcc;
extern char G2_007aebc0;
extern char G3_007aebb8;
extern char G4_007aeba8;
extern char G5_007aeb98;
extern char G6_007aeb88;
extern char G7_007aeb78;
extern char G8_007aeb68;
extern char G9_007aeb58;
extern char G10_007aeb4c;

void func_00588410();

void SoundChannel::construct()
{
    *(void**)((char*)this + 0) = &G1_007aebcc;
    *(void**)((char*)this + 4) = &G2_007aebc0;
    *(void**)((char*)this + 0x10) = &G3_007aebb8;
    *(void**)((char*)this + 0x14) = &G4_007aeba8;
    *(void**)((char*)this + 0x2c) = &G5_007aeb98;
    *(void**)((char*)this + 0x44) = &G6_007aeb88;
    *(void**)((char*)this + 0x5c) = &G7_007aeb78;
    *(void**)((char*)this + 0x74) = &G8_007aeb68;
    *(void**)((char*)this + 0x8c) = &G9_007aeb58;
    *(void**)((char*)this + 0xe8) = &G10_007aeb4c;
    func_00588410();
}
