// from server: 53% by atomic.potato
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);

struct RBX_GlobalAdvancedSettings {
    char pad[0xd0];
    void* handle;
    void sub_6c7620();
    void* destroy(char);
};

void RBX_GlobalAdvancedSettings::sub_6c7620() {
    void* old = handle;
    handle = 0;
    if (old) CloseHandle(old);
}

void* RBX_GlobalAdvancedSettings::destroy(char flag) {
    void* old = handle;
    handle = 0;
    if (old) CloseHandle(old);
    sub_6c7620();
    if (flag & 1) {
        extern void __cdecl op_delete(void*);
        op_delete(this);
    }
    return this;
}
