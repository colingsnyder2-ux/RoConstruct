// from server: 24% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" {
    void __stdcall sub_77E6A4(void*);
    void __stdcall sub_77E6AC(void*);
    void __stdcall sub_77E6A8(void*);
    void __stdcall sub_77E690(void*, int);
    void __stdcall sub_77E69C(void*, void*);
    void __stdcall sub_77E660(void*, const char*);
    void __stdcall sub_77E664(void*, void*);
    void __stdcall sub_77E668(void*, const char*, int, int, int);
    void __stdcall sub_77E66C(void*);
    void __stdcall sub_77E6D8(void);
    void __stdcall sub_725750(void*);
    void __stdcall sub_725770(void*);
    void* __cdecl sub_56C3B0(void*);
    void __cdecl sub_56C0A0(void*, int, const char*, void*);
    void __cdecl sub_553EA0(void*, void*, void*, int, void*);
}

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
    void Release();
};

void RefCounted::Release() {
    if (_InterlockedExchangeAdd(&ref1, -1) == 1) {
        (*(void(__thiscall**)(RefCounted*))(*(void***)this)[1])(this);
        if (_InterlockedExchangeAdd(&ref2, -1) == 1) {
            (*(void(__thiscall**)(RefCounted*))(*(void***)this)[2])(this);
        }
    }
}

struct Inner {
    char pad[0x14];
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
};

struct Outer {
    char pad[0x8];
    void* m_8;
    void* m_c;
    void* m_10;
    Inner m_14;
    char pad2[0x4];
    void* m_1c;
    int method(void* arg1, RefCounted* arg2);
};

int Outer::method(void* arg1, RefCounted* arg2) {
    char buf1[0x20];
    char buf2[0x20];
    char buf3[0x100];
    RefCounted* local;

    sub_77E6A4(buf1);
    sub_725750(&m_14);
    if (m_10 == 0) {
        sub_725770(&m_14);
        sub_77E6AC(buf1);
        if (arg2) {
            arg2->Release();
        }
        return 0;
    }
    void* p = m_c;
    void* end = (char*)m_10 + (int)p;
    if (p > end) {
        sub_77E6D8();
    }
    void* p2 = m_c;
    void* end2 = (char*)m_10 + (int)p2;
    if (p2 < end2) {
        // ok
    } else {
        sub_77E6D8();
    }
    void* base = m_8;
    int idx;
    if (base > p2) {
        idx = (int)p2;
    } else {
        idx = (int)p2 - (int)base;
    }
    void* elem = ((void**)m_8)[idx];
    sub_77E690(buf1, (int)elem);
    sub_725770(&m_14);
    void* r = sub_56C3B0(&m_14);
    void* v = *(void**)r;
    sub_77E6A8(buf1);
    sub_56C0A0(v, 1, "Uploading error log: %s", (void*)0);
    if (local) {
        local->Release();
    }
    sub_77E69C(buf2, &m_1c);
    sub_77E660(buf2, "?filename=");
    sub_77E664(buf2, buf1);
    sub_77E6A8(buf1);
    sub_77E668(buf3, (const char*)0, 0x21, 0x40, 1);
    sub_77E6A4(buf2);
    sub_553EA0(buf2, buf3, buf1, 1, buf2);
    sub_77E6AC(buf2);
    sub_77E66C(buf3);
    sub_77E6AC(buf1);
    return 1;
}
