// from server: 100% by atomic.potato
struct LegacyHopperService {
    void initialize();
};

extern "C" void __cdecl sub_62EB30();

void LegacyHopperService::initialize() {
    *(int*)((char*)this + 0x00) = 0x00a95ff4;
    *(int*)((char*)this + 0x04) = 0x00a95fe8;
    *(int*)((char*)this + 0x18) = 0x00a95fdc;
    *(int*)((char*)this + 0x1c) = 0x00a95fd0;
    *(int*)((char*)this + 0x90) = 0x00a95fc8;
    sub_62EB30();
}
