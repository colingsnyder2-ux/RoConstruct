// from server: 40% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall PostMessageA(void*, unsigned int, unsigned int, long);
extern "C" int __stdcall compare_string(const char*, const char*);

struct RefCounted {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    volatile long refCount1;
    volatile long refCount2;
};

struct StringHolder {
    virtual void* unknown0();
    virtual void* unknown1();
    virtual void* unknown2();
    char pad[0x100];
};

struct RobloxView {
    char pad0[0x5c];
    void* hwnd;
    char pad1[0x1c];
    void* field_7c;
    char pad2[0x80];
    void method(int a, int b, int c);
};

void RobloxView::method(int a, int b, int c)
{
    StringHolder* sh = (StringHolder*)a;
    RefCounted* rc = (RefCounted*)c;

    sh->unknown0();
    void* v = sh->unknown1();
    if (compare_string((const char*)v + 4, "NetworkClient") != 0) {
        PostMessageA(hwnd, 0, 0x46c, 0);
    }

    sh->unknown0();
    v = sh->unknown1();
    if (compare_string((const char*)v + 4, "NetworkClient") != 0) {
        sh->unknown0();
        v = sh->unknown1();
        if (compare_string((const char*)v + 4, "Players") == 0) {
            PostMessageA(hwnd, 0, 0x46b, 0);
        }
    }

    sh->unknown0();
    v = sh->unknown1();
    if (compare_string((const char*)v + 4, "Players") != 0) {
        void* p = 0;
        if (this->field_7c != 0) {
            p = (char*)this + 4;
        }
        extern void func_00432530(void*, void*);
        func_00432530((char*)sh + 0x100, p);
    }

    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->refCount1, -1) == 1) {
            rc->unknown0();
            if (_InterlockedExchangeAdd(&rc->refCount2, -1) == 1) {
                rc->unknown2();
            }
        }
    }
}
