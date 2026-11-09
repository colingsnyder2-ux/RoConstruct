// from server: 29% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RBXName {
    void* dummy;
};

struct CreatorBase {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
};

struct Creator : CreatorBase {
    int isConstructed;
    static int isConstructedTrue();
    static bool wasConstructed();
    const RBXName& getClassNameUnconstructed() const;
    const RBXName& getClassName() const;
    Creator();
    ~Creator();
};

struct RefCounted {
    long refcount;
    virtual void destroy();
    virtual void destroy2();
};

struct CreatorPtr {
    Creator* ptr;
    RefCounted* ref;
};

struct CreatorMap {
    void* tree;
};

extern "C" void __cdecl sub_972290(int, const char*);
extern "C" CreatorPtr* __cdecl sub_414140(CreatorPtr*);

extern unsigned char byte_E580B3;
extern int dword_E16538;
extern int (__stdcall *dword_E5809C)(int, const char*, const char*);
extern const char str_B42F90[];
extern const char str_B42FA8[];
extern const char str_B432F8[];

CreatorPtr* __cdecl sub_414140(CreatorPtr* out);

CreatorPtr* __cdecl sub_414140(CreatorPtr* out)
{
    return out;
}

Creator::Creator()
{
    CreatorPtr local;
    local.ptr = 0;
    local.ref = 0;

    if (byte_E580B3 != 0 && dword_E16538 != 0x29a) {
        if (dword_E5809C != 0) {
            if (!dword_E5809C(0xca, str_B42F90, str_B42FA8)) {
                sub_972290(byte_E580B3, str_B432F8);
            }
        } else {
            sub_972290(byte_E580B3, str_B432F8);
        }
    }

    CreatorPtr* result = sub_414140(&local);
    Creator* c = result->ptr;
    if (c != 0) {
        c = (Creator*)((char*)c + 0x18);
    } else {
        c = 0;
    }
    this->isConstructed = 0;
    (void)c;
}
