// from server: 42% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct CRobloxTreeCtrlNode;

struct RefCounted {
    void AddRef();
    void Release();
};

struct Node {
    char pad0[0x28];
    void* field28;
};

struct TreeCtrlNode {
    char pad0[0x0c];
    void* field0c;
    char pad10[0x08];
    void* field18;
    char pad1c[0x14];
    void* field30;
};

struct Inner {
    char pad0[0x98];
    void* field98;
    char pad9c[0x14];
    void* fieldb0;
};

struct CRobloxTreeCtrlNode {
    char pad0[0x28];
    Inner* field28;
    void method(void* arg);
};

extern "C" void __stdcall sub_725750(void*);
extern "C" void __stdcall sub_725770(void*);
extern "C" void __stdcall sub_407220(void*, void*);
extern "C" void __stdcall sub_44f4c0(void*, void*, void*);
extern "C" void __stdcall sub_4a9660(void*, void*, void*);
extern "C" void __stdcall sub_421fd0(void*, void*);

void CRobloxTreeCtrlNode::method(void* arg) {
    Inner* inner = this->field28;
    void* p = (char*)inner + 0xb0;
    sub_725750(p);

    void* local14 = arg;
    sub_407220((char*)inner + 0x98, &local14);

    void* local1c = 0;
    void* local18 = 0;
    sub_44f4c0((char*)this + 0x0c, &local18, &local14);

    void* ebx = local18;
    void* ebp = local1c;
    void* eax = *(void**)((char*)this + 0x10);
    void* local20 = eax;

    if (ebx != 0 && ebx != (char*)this + 0x0c) {
        _invalid_parameter_noinfo();
    }

    if (ebp != local20) {
        if (ebx == 0) {
            _invalid_parameter_noinfo();
        }
        if (ebp == *(void**)((char*)ebx + 4)) {
            _invalid_parameter_noinfo();
        }
        ebp = (char*)ebp + 0x10;
        sub_4a9660((char*)this + 0x18, &local1c, ebp);
    }

    sub_421fd0((char*)this + 0x30, &arg);

    sub_725770(p);

    Inner* inner2 = this->field28;
    void** vtbl = *(void***)inner2;
    void (*fn)(void*) = (void (*)(void*))vtbl[0x154 / 4];
    fn((char*)this - 8);

    RefCounted* rc = (RefCounted*)arg;
    if (rc != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)rc + 4), -1) == 1) {
            void** vtbl2 = *(void***)rc;
            void (*fn2)(void*) = (void (*)(void*))vtbl2[1];
            fn2(rc);
            if (_InterlockedExchangeAdd((volatile long*)((char*)rc + 8), -1) == 1) {
                void** vtbl3 = *(void***)rc;
                void (*fn3)(void*) = (void (*)(void*))vtbl3[2];
                fn3(rc);
            }
        }
    }
}
