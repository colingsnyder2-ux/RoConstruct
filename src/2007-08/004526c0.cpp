// from server: 27% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refcount;
    volatile long weakrefcount;
};

struct String {
    void* pad0;
    char* data;
    int size;
    int cap;
};

struct StreamBuf {
    void* pad[16];
};

struct OStringStream {
    void* pad[16];
};

struct ReportAbuseVerb {
    char pad[0x78];
    void* field78;

    void method();
};

extern "C" {
    void __stdcall sub_77ddac(void*);
    void __stdcall sub_77d59c(void*, int);
    void* __stdcall sub_77dd98(void*);
    void __stdcall sub_77ddbc(void*);
    void __stdcall sub_77e67c(void*, int, int);
    void __stdcall sub_77e5fc(void*);
    void __stdcall sub_77e680(void*, void*);
    void __stdcall sub_77e6a8(void*);
    void __stdcall sub_77e6ac(void*);
}

void sub_6303f4(void*, int, void*, int, int, void*);
int sub_6303ee(void*);
void sub_6303e8(void*, void*);
void sub_46bba0(void*, void*);
void sub_46bce0(void*, void*);
void sub_403800(void*, void*);
void sub_40d550(void*);
void sub_403830(void*, void*);
void sub_42e5d0(void*);
void sub_53ced0(void*, void*, void*, int, void*, void*);
void sub_42db50(void*, void*);
void sub_62fc62(void*);
void sub_5595a0(void*);

void ReportAbuseVerb::method()
{
    char buf[0xc0];
    void* stream;
    void* str;
    void* tmp;
    void* p;
    int result;
    RefCounted* rc;
    RefCounted* rc2;
    void* local;

    sub_77ddac(buf);
    sub_77d59c(buf, 0x8d);
    sub_77dd98(buf);
    sub_77dd98(buf);
    sub_6303f4(&local, 1, (void*)0x791a04, 0, 6, 0);
    result = sub_6303ee(&local);
    if (result == 1) {
        sub_6303e8(&local, &tmp);
        sub_77dd98(&tmp);
        sub_46bba0(&stream, &tmp);
        sub_77ddbc(&tmp);
        sub_77e67c(&str, 2, 1);
        sub_46bce0(&stream, &str);
        sub_77e5fc(&str);
        sub_403800(field78, &p);
        rc = (RefCounted*)p;
        if (rc->refcount != 0) {
            _InterlockedExchangeAdd(&rc->refcount, 1);
        }
        sub_40d550(&tmp);
        rc2 = (RefCounted*)tmp;
        if (rc2 != 0) {
            if (_InterlockedExchangeAdd(&rc2->refcount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))rc2->vptr)(rc2);
                if (_InterlockedExchangeAdd(&rc2->weakrefcount, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))rc2->vptr)(rc2);
                }
            }
        }
        sub_77e680(&str, &tmp);
        sub_403830(this, &p);
        sub_77e6a8(&tmp);
        sub_42e5d0(p);
        sub_53ced0(p, (void*)0x7919fc, &tmp, 1, &str, &p);
        if (p != 0) {
            if (*(void**)((char*)p + 4) != 0) {
                sub_42db50(*(void**)((char*)p + 4), *(void**)((char*)p + 8));
                sub_62fc62(*(void**)((char*)p + 4));
            }
            *(void**)((char*)p + 4) = 0;
            *(void**)((char*)p + 8) = 0;
            *(void**)((char*)p + 0xc) = 0;
            sub_62fc62(p);
        }
        rc2 = (RefCounted*)tmp;
        if (rc2 != 0) {
            if (_InterlockedExchangeAdd(&rc2->refcount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))rc2->vptr)(rc2);
                if (_InterlockedExchangeAdd(&rc2->weakrefcount, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))rc2->vptr)(rc2);
                }
            }
        }
        sub_77e6ac(&tmp);
        if (p != 0) {
            sub_42db50(p, *(void**)((char*)p + 4));
            sub_62fc62(p);
        }
        sub_5595a0(&tmp);
    }
}
