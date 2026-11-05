// from server: 25% by atomic.potato
extern "C" void* __cdecl sub_80A05E(unsigned int);

struct Alloc {
    void ctor();
};

struct VGuiImageButton {
    void* __cdecl Creator(void* a, void* b);
};

void* VGuiImageButton::Creator(void* a, void* b) {
    void* mem = sub_80A05E(0x2a8);
    void* obj = 0;
    if (mem) {
        ((Alloc*)mem)->ctor();
        obj = mem;
    }
    ((void (__thiscall*)(void*, void*, void*))0x4AF170)(this, obj, a);
    return this;
}
