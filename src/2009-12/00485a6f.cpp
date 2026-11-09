// from server: 53% by atomic.potato
struct String {
    char pad[0x1c];
};

struct MaterialPtr {
    void* p;
};

struct Material {
    MaterialPtr clone(const String& name, bool b1, const String& b2) const;
    unsigned short getNumSupportedTechniques() const;
};

struct MaterialManager {
    static MaterialManager& getSingleton();
};

extern "C" {
    void* __stdcall sub_98bd88();
    void* __stdcall sub_98b680(void*, const char*, void*);
    void __stdcall sub_98b6e4(void*);
    void __stdcall sub_98bd84(void*, void*);
    void __stdcall sub_98bdcc(void*);
    void __stdcall sub_98be5c(void*);
    void* __stdcall sub_98c04c(void*, void*, void*, void*);
    void __stdcall sub_98c050(void*, void*);
}

extern char byte_9b27b4;
extern char byte_9b21f0;
extern void* dword_98c048;

struct GfxClustererPart {
    int f(int, int, int, int, int, int, int, int, int);
};

int GfxClustererPart::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) {
    char buf1[0x18];
    char buf2[0x18];
    char buf3[0x54];
    int result = 1;

    void* mgr = sub_98bd88();
    sub_98b680(buf3, &byte_9b27b4, buf1);

    void** vt = *(void***)mgr;
    void* fn = vt[0x13];
    void* r = ((void* (__thiscall*)(void*, void*, void*))fn)(mgr, buf2, buf1);
    (void)r;

    sub_98bd84(buf1, buf2);

    *(void**)buf2 = &byte_9b21f0;
    int* cnt = *(int**)(buf2 + 8);
    if (cnt) {
        --*cnt;
        cnt = *(int**)(buf2 + 8);
        if (*cnt == 0) {
            void** vt2 = *(void***)buf2;
            void* fn2 = vt2[1];
            ((void (__thiscall*)(void*))fn2)(buf2);
        }
    }

    sub_98b6e4(buf3);

    void* p34 = *(void**)(buf1 + 4);
    if (p34) {
        void** vt3 = *(void***)p34;
        void* fn3 = vt3[0x11];
        ((void (__thiscall*)(void*, int))fn3)(p34, 0);
        sub_98be5c(*(void**)(buf1 + 4));
    }

    if (*(void**)(buf1 + 4)) {
        void* m = sub_98bd88();
        void** vt4 = *(void***)m;
        void* fn4 = vt4[0x13];
        void* r2 = ((void* (__thiscall*)(void*, void*, void*))fn4)(m, buf2, buf1);
        bool empty = (*(int*)((char*)r2 + 4) == 0);

        *(void**)buf2 = &byte_9b21f0;
        int* cnt2 = *(int**)(buf2 + 8);
        if (cnt2) {
            --*cnt2;
            cnt2 = *(int**)(buf2 + 8);
            if (*cnt2 == 0) {
                void** vt5 = *(void***)buf2;
                void* fn5 = vt5[1];
                ((void (__thiscall*)(void*))fn5)(buf2);
            }
        }

        if (empty) {
            void* p = sub_98c04c(*(void**)(buf1 + 4), 0, buf1, buf2);
            sub_98c050(buf2, p);
            sub_98bdcc(buf2);
        }
    }

    sub_98bdcc(buf2);
    sub_98b6e4(buf1);

    return result;
}
