// from server: 44% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_66c780(void*);
extern "C" void* __cdecl sub_721520(void*, void*);

struct Holder {
    void* vptr;
    long refcount;
};

struct AdvRunDragger {
    char pad0[0x1c];
    Holder* field1c;
    char pad20[0x1c];
    void* field3c;
    void release();
};

void AdvRunDragger::release() {
    if (field3c != 0) {
        void* a = sub_66c780(field3c);
        void* b;
        sub_721520(&b, a);
        Holder* old = field1c;
        field1c = (Holder*)b;
        if (old != 0) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)old + 8), -1) == 1) {
                void (__thiscall *del)(void*) = *(void (__thiscall**)(void*))((*(void***)old)[2]);
                del(old);
            }
        }
        if (b != 0) {
            Holder* r = (Holder*)b;
            if (_InterlockedExchangeAdd(&r->refcount, -1) == 1) {
                void (__thiscall *dtor)(void*) = *(void (__thiscall**)(void*))((*(void***)r)[1]);
                dtor(r);
                if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1) {
                    void (__thiscall *del2)(void*) = *(void (__thiscall**)(void*))((*(void***)r)[2]);
                    del2(r);
                }
            }
        }
    } else {
        Holder* h = field1c;
        field1c = 0;
        if (h != 0) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)h + 8), -1) == 1) {
                void (__thiscall *del)(void*) = *(void (__thiscall**)(void*))((*(void***)h)[2]);
                del(h);
            }
        }
    }
}
