// from server: 100% by colin
struct RBX_VRotate_FactoryProduct {
    void construct();
};

void RBX_VRotate_FactoryProduct::construct() {
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x00) = 0x7b665c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x04) = 0x7b6654;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10) = 0x7b664c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x14) = 0x7b663c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x2c) = 0x7b662c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x44) = 0x7b661c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x5c) = 0x7b660c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x74) = 0x7b65fc;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x8c) = 0x7b65ec;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xe8) = 0x7b65d4;
    extern void tail_call();
    tail_call();
}
