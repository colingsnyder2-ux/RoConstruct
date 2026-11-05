// from server: 100% by colin
struct StarterPackService {
    void construct();
};

extern "C" void __stdcall sub_59cb00();

void StarterPackService::construct() {
    *(int*)((char*)this + 0x00) = 0x7b1f84;
    *(int*)((char*)this + 0x04) = 0x7b1f7c;
    *(int*)((char*)this + 0x10) = 0x7b1f74;
    *(int*)((char*)this + 0x14) = 0x7b1f64;
    *(int*)((char*)this + 0x2c) = 0x7b1f54;
    *(int*)((char*)this + 0x44) = 0x7b1f44;
    *(int*)((char*)this + 0x5c) = 0x7b1f34;
    *(int*)((char*)this + 0x74) = 0x7b1f24;
    *(int*)((char*)this + 0x8c) = 0x7b1f14;
    *(int*)((char*)this + 0xe8) = 0x7b1f0c;
    sub_59cb00();
}
