// from server: 37% by atomic.potato
struct S_func_008c0590 { virtual ~S_func_008c0590(); };

struct X_007b71d0 {
    void* f_0;
    void* f_4;
    char pad_8[0x10];
    void* f_18;
    void* f_1c;
    char pad_20[0x60];
    S_func_008c0590 f_80;
    void run();
};

void X_007b71d0::run() {
    f_0 = (void*)0xbb996c;
    f_4 = (void*)0xbb9960;
    f_18 = (void*)0xbb9954;
    f_1c = (void*)0xbb9948;
    *(void**)&f_80 = (void*)0xbb9940;
    f_80.~S_func_008c0590();
    f_0 = (void*)0xbb98ac;
    f_4 = (void*)0xbb98a4;
    f_18 = (void*)0xbb9898;
    f_1c = (void*)0xbb988c;
    ((void(__thiscall*)(X_007b71d0*))0x685090)(this);
}
