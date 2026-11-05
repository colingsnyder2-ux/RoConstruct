// from server: 23% by atomic.potato
struct PhysicsPacketCache {
    void sub_5a4c40();
};

extern "C" void __cdecl sub_4125d0();
extern "C" void __cdecl sub_6cab60();
extern "C" void __cdecl sub_9831f5();

void PhysicsPacketCache::sub_5a4c40() {
    if ((*(unsigned char*)0xe25b24 & 1) == 0) {
        *(unsigned int*)0xe25b24 |= 1;
        sub_4125d0();
        sub_6cab60();
        sub_9831f5();
    }
}
