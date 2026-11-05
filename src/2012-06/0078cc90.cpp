// from server: 32% by atomic.potato
struct X_0078cc90 {
    void* f_0;
    void* f_4;
    char pad_8[0x14];
    void* f_18;
    void* f_1c;
    char pad_20[0x64];
    void* f_84;
    char pad_88[0x1c];
    void* f_a4;
    void dtor();
};

extern "C" void __stdcall sub_974150(void*);
extern "C" void __stdcall sub_982114(void*);
extern "C" void __stdcall sub_685090(void*);
extern "C" void __stdcall sub_b2263c(void*);

void X_0078cc90::dtor() {
    f_0 = (void*)0xbb1e14;
    f_4 = (void*)0xbb1e0c;
    f_18 = (void*)0xbb1e00;
    f_1c = (void*)0xbb1df4;
    void* p = f_a4;
    if (p) {
        sub_974150(p);
        sub_982114(p);
    }
    sub_b2263c((char*)this + 0x84);
    f_0 = (void*)0xbb1d9c;
    f_4 = (void*)0xbb1d90;
    f_18 = (void*)0xbb1d84;
    f_1c = (void*)0xbb1d78;
    sub_685090(this);
}
