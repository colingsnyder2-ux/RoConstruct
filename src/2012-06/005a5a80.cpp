// from server: 76% by Intel
struct PhysicsPacketCache {
    void handlePacket(void* packet);
};

extern "C" int __stdcall sub_7b9430(void* thisptr);
extern "C" void __stdcall sub_5a53c0(PhysicsPacketCache* thisptr, int value);

void PhysicsPacketCache::handlePacket(void* packet) {
    void* obj = *reinterpret_cast<void**>(reinterpret_cast<char*>(packet) + 0x198);
    int value = sub_7b9430(obj);
    sub_5a53c0(this, value);
}
