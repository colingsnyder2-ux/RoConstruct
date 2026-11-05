// from server: 23% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refCount;
    long weakCount;
};

struct SharedPtr {
    void* ptr;
    RefCounted* control;
};

struct String {
    char buf[28];
};

struct Item {
    void* vptr;
};

struct TypedStatsItem : Item {
    SharedPtr func;
    void update();
    void formatValue(const String&);
};

extern "C" void __stdcall sub_45AE90(SharedPtr* out, const void* arg);
extern "C" void __stdcall sub_541630(void* arg1, void* arg2);
extern "C" void __stdcall sub_77E698(String* out, const char* str);
extern "C" void __stdcall sub_77E6AC(String* str);

void TypedStatsItem::update()
{
    SharedPtr local;
    sub_45AE90(&local, *(void**)((char*)this + 8));

    SharedPtr tmp;
    tmp.ptr = local.ptr;
    tmp.control = local.control;
    if (tmp.control) {
        _InterlockedExchangeAdd(&tmp.control->refCount, 1);
    }

    if (local.control) {
        if (_InterlockedExchangeAdd(&local.control->refCount, -1) == 1) {
            void** vt = *(void***)local.control;
            ((void (__thiscall*)(void*))vt[1])(local.control);
            if (_InterlockedExchangeAdd(&local.control->weakCount, -1) == 1) {
                void** vt2 = *(void***)local.control;
                ((void (__thiscall*)(void*))vt2[2])(local.control);
            }
        }
    }

    String s;
    sub_77E698(&s, *(const char**)((char*)this + 12));

    void** vt = *(void***)tmp.ptr;
    ((void (__thiscall*)(void*, String*))vt[2])(tmp.ptr, &s);

    sub_77E6AC(&s);

    sub_541630(tmp.ptr, this);

    if (tmp.control) {
        if (_InterlockedExchangeAdd(&tmp.control->refCount, -1) == 1) {
            void** vt2 = *(void***)tmp.control;
            ((void (__thiscall*)(void*))vt2[1])(tmp.control);
            if (_InterlockedExchangeAdd(&tmp.control->weakCount, -1) == 1) {
                void** vt3 = *(void***)tmp.control;
                ((void (__thiscall*)(void*))vt3[2])(tmp.control);
            }
        }
    }
}
