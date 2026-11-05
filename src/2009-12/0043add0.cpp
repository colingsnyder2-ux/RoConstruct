// from server: 95% by atomic.potato
struct UDim2ComponentItem {
    char pad0[0x38];
    void* items[2];
    void setItem(void*);
};

extern "C" void __fastcall sub_437DE0(void*, void*);

void UDim2ComponentItem::setItem(void* arg) {
    sub_437DE0(this, arg);
    for (int i = 0; i < 2; ++i) {
        if (items[i]) {
            void** vtbl = *(void***)((char*)items[i] + 0x10c);
            ((void (__thiscall*)(void*, void*))vtbl[0])((char*)items[i] + 0x10c, arg);
        }
    }
}
