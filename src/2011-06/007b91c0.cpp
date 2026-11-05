// from server: 100% by atomic.potato
struct RBX_Instance;

extern "C" void* __cdecl sub_80B2EA(void*, void*, void*, void*, void*);
extern "C" void* __cdecl sub_640AF0(void*);

struct RBX_FilterDescendents {
    void* getCameraSubject();
};

void* RBX_FilterDescendents::getCameraSubject() {
    void* p = sub_80B2EA(this, 0, (void*)0x00C38F48, (void*)0x00C071F8, 0);
    if (p != 0) {
        p = sub_640AF0(p);
        if (p != 0) {
            return *(void**)((char*)p + 0xB4);
        }
    }
    return 0;
}
