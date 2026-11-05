// from server: 100% by colin
namespace ns_ROCX000007 {
struct CXTColorHex {
    char pad[0x70];
    int field_70;
    char pad2[0x4];
    void* field_78;
    void sub_800280(int);
    void sub_8002c0(int);
};

void CXTColorHex::sub_8002c0(int arg) {
    void* esi;
    int edi;
    field_70 = arg;
    esi = field_78;
    edi = -1;
    while (esi != 0) {
        int* eax = *(int**)((char*)esi + 8);
        if (eax != 0 && arg == eax[6]) {
            sub_800280(edi);
        }
        esi = *(void**)esi;
        edi++;
    }
}
}
