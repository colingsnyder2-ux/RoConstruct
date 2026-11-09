// from server: 35% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Obj {
    char pad[0x78];
    void* field78;
};

struct RefPair {
    void* vfptr;
    long refcount;
    long weakcount;
};

extern "C" void* __stdcall sub_403800(void* out, void* arg);
extern "C" void* __stdcall sub_403830(void* out, void* arg);
extern "C" void __stdcall sub_40D550(void* p);
extern "C" void* __stdcall sub_450EC0(void* p);
extern "C" void __stdcall sub_5595A0(void* p);

struct ReportAbuseVerb {
    void method(int arg);
};

void ReportAbuseVerb::method(int arg)
{
    Obj* self = (Obj*)this;
    void* tmp[2];
    void* tmp2[2];
    void* holder;
    void* obj;
    int flag;

    sub_403800(tmp, self->field78);

    void* p = tmp[0];
    void* q = tmp[1];
    holder = 0;
    tmp[0] = tmp;

    if (q != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)q + 4), 1);
    }

    sub_40D550(tmp2);

    void* r = tmp[1];
    if (r != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)r + 4), -1) == 1) {
            void** vt = *(void***)r;
            ((void (__thiscall*)(void*))vt[1])(r);
            if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1) {
                void** vt2 = *(void***)r;
                ((void (__thiscall*)(void*))vt2[2])(r);
            }
        }
    }

    sub_403830(tmp2, self);

    obj = sub_450EC0(tmp2[0]);

    void* s = tmp2[1];
    if (s != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)s + 4), -1) == 1) {
            void** vt = *(void***)s;
            ((void (__thiscall*)(void*))vt[1])(s);
            if (_InterlockedExchangeAdd((volatile long*)((char*)s + 8), -1) == 1) {
                void** vt2 = *(void***)s;
                ((void (__thiscall*)(void*))vt2[2])(s);
            }
        }
    }

    if (*(char*)((char*)obj + 0x1ac) == 0 && *(int*)((char*)obj + 0x14c) != 1)
        flag = 1;
    else
        flag = 0;

    void* u = holder;
    void** vt = *(void***)u;
    ((void (__thiscall*)(void*, int))vt[0])(u, flag);

    sub_5595A0(tmp2);
}
