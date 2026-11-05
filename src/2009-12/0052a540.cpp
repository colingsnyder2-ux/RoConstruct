// from server: 44% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VCRenderSettingsItem {
    char pad0[0x1d4];
    void* field_1d4;
    void cleanup();
};

void VCRenderSettingsItem::cleanup() {
    void* p = this->field_1d4;
    this->field_1d4 = 0;
    if (p) {
        long old = _InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1);
        if (old == 1) {
            void** vt = *(void***)p;
            ((void (__thiscall*)(void*))vt[2])(p);
        }
    }
    ((void (__thiscall*)(VCRenderSettingsItem*))0x7e8520)(this);
}
