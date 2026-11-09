// from server: 100% by colin
struct Exposer {
    void construct();
};

extern "C" void __stdcall sub_4AA580();

void Exposer::construct() {
    *(int*)((char*)this + 0x00) = 0x79c044;
    *(int*)((char*)this + 0x04) = 0x79c038;
    *(int*)((char*)this + 0x10) = 0x79c030;
    *(int*)((char*)this + 0x14) = 0x79c020;
    *(int*)((char*)this + 0x2c) = 0x79c010;
    *(int*)((char*)this + 0x44) = 0x79c000;
    *(int*)((char*)this + 0x5c) = 0x79bff0;
    *(int*)((char*)this + 0x74) = 0x79bfe0;
    *(int*)((char*)this + 0x8c) = 0x79bfd0;
    *(int*)((char*)this + 0xe8) = 0x79bfa0;
    *(int*)((char*)this + 0xec) = 0x79bf94;
    sub_4AA580();
}
