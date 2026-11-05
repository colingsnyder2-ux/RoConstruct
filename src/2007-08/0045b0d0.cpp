// from server: 46% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refCount;
    long weakRefCount;
};

struct String {
    void* pad[4];
};

extern "C" void* __stdcall sub_45AF20(void* out, const char* s);
extern "C" void __stdcall sub_541630(void* self, void* arg);
extern "C" void* __stdcall sub_77E698(void* self, const char* s);
extern "C" void __stdcall sub_77E6AC(void* self);

struct TypedStatsItem {
    void* vptr;
    void* func[2];
    void* update(const char* name);
};

void* TypedStatsItem::update(const char* name) {
    void* local[2];
    void* result;
    void* obj;
    void* tmp;
    long old;

    sub_45AF20(local, name);
    obj = local[0];
    tmp = local[1];

    if (tmp) {
        _InterlockedExchangeAdd((volatile long*)((char*)tmp + 4), 1);
    }

    if (local[0]) {
        old = _InterlockedExchangeAdd((volatile long*)((char*)local[0] + 4), -1);
        if (old == 1) {
            void** vt = *(void***)local[0];
            ((void (__thiscall*)(void*))vt[1])(local[0]);
            old = _InterlockedExchangeAdd((volatile long*)((char*)local[0] + 8), -1);
            if (old == 1) {
                void** vt2 = *(void***)local[0];
                ((void (__thiscall*)(void*))vt2[2])(local[0]);
            }
        }
    }

    sub_77E698(local, name);

    void** vt3 = *(void***)obj;
    ((void (__thiscall*)(void*, void*))vt3[2])(obj, local);

    sub_77E6AC(local);

    sub_541630(obj, this);

    if (tmp) {
        old = _InterlockedExchangeAdd((volatile long*)((char*)tmp + 4), -1);
        if (old == 1) {
            void** vt4 = *(void***)tmp;
            ((void (__thiscall*)(void*))vt4[1])(tmp);
            old = _InterlockedExchangeAdd((volatile long*)((char*)tmp + 8), -1);
            if (old == 1) {
                void** vt5 = *(void***)tmp;
                ((void (__thiscall*)(void*))vt5[2])(tmp);
            }
        }
    }

    return obj;
}
