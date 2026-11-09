// from server: 48% by atomic.potato
extern "C" void __stdcall CloseHandle(void*);

struct GlobalAdvancedSettings {
    char pad[0xe0];
    void* handle;
    void sub_5B7E00();
    void* destroy(char);
};

void* GlobalAdvancedSettings::destroy(char flag) {
    void* old = handle;
    handle = 0;
    if (old) {
        CloseHandle(old);
    }
    sub_5B7E00();
    if (flag & 1) {
        extern void __cdecl op_delete(void*);
        op_delete(this);
    }
    return this;
}
