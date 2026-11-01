// from server: 100% by colin
struct VMotorFeature {
    void removeAll();
    void sub_5de6c0(void*);
    void func(void*);
};

void VMotorFeature::func(void* a) {
    void* p = *(void**)((char*)a + 0x28);
    if (p != 0) {
        do {
            sub_5de6c0(p);
            p = *(void**)((char*)a + 0x28);
        } while (p != 0);
    }
}
