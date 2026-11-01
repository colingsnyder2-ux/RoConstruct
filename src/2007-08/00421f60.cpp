// from server: 100% by colin
struct CXTTreeCtrl {
    char pad[0x54];
    int field_54;
    char pad2[0x90 - 0x58];
    unsigned char field_90;
    void method();
};

extern "C" void __stdcall sub_62fcd4();

void CXTTreeCtrl::method()
{
    sub_62fcd4();
    if (field_90 != 0) {
        int* p = (int*)field_54;
        void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))p[0x44 / 4];
        fn((char*)this + 0x54);
    }
}
