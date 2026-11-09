// from server: 34% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __stdcall CryptAcquireContextA(void**, const char*, const char*, unsigned long, unsigned long);
extern "C" int __stdcall CryptCreateHash(void*, unsigned long, unsigned long, unsigned long, void**);
extern "C" unsigned long __stdcall GetLastError();

struct RBXString {
    void* rep;
    RBXString();
    ~RBXString();
};

struct RefCounted {
    long refcount;
    long weakrefcount;
    virtual void destroy();
    virtual void weakdestroy();
};

struct SettingsItem {
    void* vptr;
    void* hProv;
    void* hHash;
    RBXString name;
    SettingsItem();
};

void __cdecl sub_56C3B0(RBXString* out);
void __cdecl sub_56C0A0(void* str, int level, const char* fmt, unsigned long err);

SettingsItem::SettingsItem()
{
    vptr = (void*)0x7a6f88;
    name.RBXString::RBXString();
    hProv = 0;
    if (!CryptAcquireContextA(&hProv, 0, 0, 1, 0xf0000000)) {
        RBXString tmp;
        sub_56C3B0(&tmp);
        unsigned long err = GetLastError();
        sub_56C0A0(tmp.rep, 3, "Error during CryptAcquireContext. GetLastError = %d", err);
        if (tmp.rep) {
            RefCounted* p = (RefCounted*)tmp.rep;
            if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
                p->destroy();
                if (_InterlockedExchangeAdd(&p->weakrefcount, -1) == 1) {
                    p->weakdestroy();
                }
            }
        }
    }
    hHash = 0;
    if (!CryptCreateHash(hProv, 0x8003, 0, 0, &hHash)) {
        RBXString tmp;
        sub_56C3B0(&tmp);
        unsigned long err = GetLastError();
        sub_56C0A0(tmp.rep, 3, "Error during CryptCreateHash. GetLastError = %d", err);
        if (tmp.rep) {
            RefCounted* p = (RefCounted*)tmp.rep;
            if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
                p->destroy();
                if (_InterlockedExchangeAdd(&p->weakrefcount, -1) == 1) {
                    p->weakdestroy();
                }
            }
        }
    }
}
