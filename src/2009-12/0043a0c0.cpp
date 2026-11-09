// from server: 81% by atomic.potato
struct Vector3Item {
    char pad0[0x24];
    void* items[3];
    void destroy(void*);
};

extern "C" void __stdcall sub_437580(void*);

void Vector3Item::destroy(void* a)
{
    sub_437580(a);
    for (int i = 0; i < 3; ++i) {
        if (items[i]) {
            void** vt = *(void***)((char*)items[i] + 0x10c);
            ((void (__stdcall*)(void*))vt[0])(a);
        }
    }
}
