// from server: 100% by colin
struct VCamera {
    char pad[0x194];
    void* field_194;
    void* getCameraSubject();
};

extern "C" void __cdecl sub_630D36(void*, void*, void*, void*, void*);

void* VCamera::getCameraSubject() {
    void* p = field_194;
    if (p) {
        sub_630D36(p, 0, (void*)0x881f4c, (void*)0x898f08, 0);
    } else {
        return 0;
    }
}
