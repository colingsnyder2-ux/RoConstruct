// from server: 47% by atomic.potato
extern "C" {
    void __stdcall sub_6ba1d0(void*, void*, unsigned char);
    void __stdcall sub_6ba050(void*, void*);
    int __stdcall sub_80b2ea(void*, void*, void*, void*, void*);
    void __stdcall sub_80b0ac(void*, void*);
    void __stdcall sub_4bbb80(void*);
    void* __stdcall sub_a40a10(void*);
}

struct VPlayer {
    void func(char* buf);
};

void VPlayer::func(char* buf) {
    char local[0x100];
    void* p;
    void* q;
    void* r;
    void* s;
    unsigned char flag;

    sub_6ba1d0(buf, (void*)0x5f5220, *(unsigned char*)0xcb5a01);
    sub_4bbb80(this);

    p = *(void**)(buf + 0x78);
    flag = 4;
    if (sub_80b2ea(p, (void*)0xc073f8, (void*)0xc1a970, 0, 0) == 0) {
        sub_a40a10((void*)0xa5c10c);
        sub_80b0ac((void*)0xb989fc, local);
    }
    sub_6ba050(this, local);

    q = *(void**)(buf + 0x18);
    flag = 1;
    if (q != 0) {
        void** vt = *(void***)q;
        void (*fn)(int) = (void (*)(int))vt[0];
        fn(1);
    }

    r = *(void**)(buf + 0x40);
    flag = 0;
    if (r != 0) {
        void* v = *(void**)r;
        if (v != 0) {
            void (*fn2)(int, void*, void*) = (void (*)(int, void*, void*))v;
            fn2(2, local + 0x48, local + 0x48);
        }
        *(void**)(buf + 0x40) = 0;
    }

    s = *(void**)(buf + 0x60);
    flag = 0xff;
    if (s != 0) {
        void* v2 = *(void**)s;
        if (v2 != 0) {
            void (*fn3)(int, void*, void*) = (void (*)(int, void*, void*))v2;
            fn3(2, local + 0x68, local + 0x68);
        }
    }
}
