// from server: 84% by atomic.potato
struct AxesItem {
    char pad0[0x24];
    void* items[3];
    void setItem(void*);
};

extern "C" void __stdcall sub_438200(void*, void*);

void AxesItem::setItem(void* a) {
    sub_438200(this, a);
    for (int i = 0; i < 3; i++) {
        if (items[i]) {
            void* p = *(void**)((char*)items[i] + 0x10c);
            (*(void(__thiscall**)(void*, void*))*(void**)p)(p, a);
        }
    }
}
