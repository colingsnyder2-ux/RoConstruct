// from server: 39% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void AddRef();
    void Release();
};

struct String {
    String(const char*);
    ~String();
};

struct Obj94 {
    virtual void f0();
    virtual void f1(void*);
};

extern "C" void __stdcall sub_43EF00(void*, void*);
extern "C" void __stdcall sub_4026A0(void*, void*);
extern "C" void __stdcall sub_6848E0(void*, int);
extern "C" void __stdcall sub_684200(void*, void*, void*);

extern "C" void* __stdcall sub_B22648();
extern "C" void __stdcall sub_B2263C(void*);

struct StarterGuiService {
    char pad[0x94];
    Obj94* field94;
    void* field98;
    void method();
};

void StarterGuiService::method()
{
    void* local4;
    void* tmp;
    String s("RobloxGui");

    sub_43EF00(&local4, &local4);
    field94 = *(Obj94**)&local4;
    sub_4026A0(&field98, &local4);

    RefCounted* rc = (RefCounted*)local4;
    if (rc) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)rc + 4), -1) == 1) {
            rc->Release();
        }
        if (_InterlockedExchangeAdd((volatile long*)((char*)rc + 8), -1) == 1) {
            rc->Release();
        }
    }

    field94->f1(&tmp);
    sub_B2263C(&tmp);
    sub_6848E0(field94, 1);
    sub_684200(field94, this, 0);
}
