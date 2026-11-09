// from server: 51% by atomic.potato
struct VTextLabel {
    void* vf0;
    void* vf4;
    char pad8[0x10];
    void* vf18;
    void* vf1c;
    char pad20[8];
    void* field28;
    char pad2c[0x54];
    void* vf80;
    void* vf84;
    VTextLabel(void*);
};

extern "C" void __stdcall sub_7f4ee0(void*);
extern "C" void* __stdcall sub_73a2c0();
extern int dword_e48ad0;

VTextLabel::VTextLabel(void* a) {
    sub_7f4ee0(a);
    vf0 = (void*)0xbc501c;
    vf4 = (void*)0xbc5010;
    vf18 = (void*)0xbc5004;
    vf1c = (void*)0xbc4ff8;
    vf80 = (void*)0xbc4fe8;
    vf84 = (void*)0xbc4fbc;
    field28 = sub_73a2c0();
    dword_e48ad0++;
}
