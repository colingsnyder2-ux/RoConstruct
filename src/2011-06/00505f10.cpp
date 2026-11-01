// from server: 32% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_4FAAE0(void*, void*);
extern "C" void __cdecl sub_5004B0(void*, void*, void*);
extern "C" void __cdecl sub_503B70(void*, void*);

struct Arg {
    char pad0[4];
    void* a;   // +4
    void* b;   // +8
};

struct EventInvocationItem {
    char pad0[0xc];
    unsigned char flags;   // +0xc
    char pad1[0x3];
    void* ptr;             // +0x10
    void Dispatch(int op, Arg* arg);
};

void EventInvocationItem::Dispatch(int op, Arg* arg) {
    if (op != 0) {
        if ((flags & 1) != 0) return;
        void* p = arg->a;
        void* q = arg->b;
        void* tmp[2];
        tmp[0] = p;
        tmp[1] = q;
        if (q != 0) {
            _InterlockedExchangeAdd((volatile long*)((char*)q + 4), 1);
        }
        sub_4FAAE0(tmp, 0);
        return;
    }
    op -= 2;
    if (op == 0) {
        if ((flags & 2) == 0) return;
        sub_503B70(ptr, arg->a);
        return;
    }
    op -= 1;
    if (op != 0) return;
    if ((flags & 2) == 0) return;
    sub_5004B0(ptr, arg->a, arg->b);
}
