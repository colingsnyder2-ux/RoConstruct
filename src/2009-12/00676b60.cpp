// from server: 53% by atomic.potato
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);

struct GlobalSettings {
    char pad[0xdc];
    void* handle;
    void sub_672900();
    void* destroy(char);
};

void GlobalSettings::sub_672900() {
    void* old = handle;
    handle = 0;
    if (old) {
        CloseHandle(old);
    }
}

void* GlobalSettings::destroy(char flags) {
    void* old = handle;
    handle = 0;
    if (old) {
        CloseHandle(old);
    }
    sub_672900();
    if (flags & 1) {
        extern void __cdecl op_delete(void*);
        op_delete(this);
    }
    return this;
}
