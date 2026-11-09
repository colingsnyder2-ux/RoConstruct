// from server: 84% by atomic.potato
struct Vector3Item {
    char pad0[0x24];
    void* items[3];
    void destroy(void*);
};

extern "C" void __fastcall sub_438C20(void*, void*);

void Vector3Item::destroy(void* a) {
    sub_438C20(this, a);
    for (int i = 0; i < 3; i++) {
        if (items[i]) {
            void** vt = *(void***)((char*)items[i] + 0x10C);
            ((void (__stdcall*)(void*, void*))vt[0])((char*)items[i] + 0x10C, a);
        }
    }
}
