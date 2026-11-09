// from server: 30% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __stdcall sub_9776B0();
extern "C" void __stdcall sub_470180(void*);
extern "C" void __stdcall sub_5728D0(void*);

struct RefCounted {
    void* ptr;
    void* ref;
};

struct Holder {
    char pad[0x8c];
    RefCounted field_8c;
};

struct PhysicsJob {
    char pad[0x8c];
    RefCounted field_8c;
    void __cdecl method(RefCounted* src);
};

void PhysicsJob::method(RefCounted* src) {
    field_8c.ptr = src->ptr;
    field_8c.ref = src->ref;
    if (field_8c.ref) {
        _InterlockedExchangeAdd((volatile long*)((char*)field_8c.ref + 4), 1);
    }
    void* a = sub_9776B0();
    sub_470180(a);
    sub_5728D0(&field_8c);
    if (field_8c.ptr) {
        RefCounted tmp;
        tmp.ptr = field_8c.ptr;
        tmp.ref = field_8c.ref;
        if (tmp.ref) {
            _InterlockedExchangeAdd((volatile long*)((char*)tmp.ref + 4), 1);
        }
        void* b = sub_9776B0();
        sub_470180(b);
        sub_5728D0(&tmp);
    }
}
