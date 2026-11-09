// from server: 40% by Intel
struct RBX_Stats_Item {
    char gap0[56];
    void* field_38;

    int sub_75D710();
};

extern "C" void __stdcall sub_46BD10();
extern "C" int __stdcall sub_6C8100(void*);

int RBX_Stats_Item::sub_75D710() {
    void* eax = field_38;
    if (!eax) {
        return 0;
    }
    void* esi = (char*)eax + 0x1c;
    if (!esi) {
        return 0;
    }
    void* edi = *(void**)((char*)esi + 0xc);
    sub_46BD10();
    int eax2 = (int)edi;
    sub_6C8100(edi);
    if ((eax2 & 0xff) == 0) {
        return 0;
    }
    void* ecx = (char*)esi - 0x1c;
    if (!ecx) {
        return 0;
    }
    void* eax3 = *(void**)ecx;
    void* edx = *(void**)((char*)eax3 + 0x54);
    return (int)edx;
}
