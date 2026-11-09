// from server: 100% by Intel
struct VCBrowserViewExternal_CComObjectNoLock {
    void* scalar_constructor(int flags);
};

struct UnknownTypeAtOffsetC {
    void __thiscall sub_415360();
};

extern "C" void __cdecl sub_982114(void* ptr);

void* VCBrowserViewExternal_CComObjectNoLock::scalar_constructor(int flags) {
    *(void**)this = (void*)0x00b45df8;
    *(void**)((char*)this + 4) = (void*)0x00b45dc8;
    *(int*)((char*)this + 8) = 0xc0000001;
    ((UnknownTypeAtOffsetC*)((char*)this + 0xc))->sub_415360();
    if (flags & 1) {
        sub_982114(this);
    }
    return this;
}
