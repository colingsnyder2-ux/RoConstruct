// from server: 41% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall sub_700B00(int);

struct Inner {
    int refcount;
};

struct Holder {
    void* vptr;
    Inner* ptr;
};

struct Outer {
    int field0;
    Holder holder;
};

struct S {
    int field0;
    void* field4;
    int field8;
    int f(int, int, int, int);
};

int S::f(int a, int b, int c, int d)
{
    Holder local;
    local.vptr = 0;
    local.ptr = 0;
    int* p = (int*)&local;
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    if (d != 0) {
        _InterlockedExchangeAdd((volatile long*)(d + 4), 1);
    }
    int r = sub_700B00(0xb93ff4);
    int val = (r != 0) ? 0xb93ff4 : 0;
    this->field0 = val;
    if (local.ptr != 0) {
        Inner* ip = local.ptr;
        if (_InterlockedExchangeAdd((volatile long*)((char*)ip + 4), -1) == 1) {
            void** vt = *(void***)ip;
            ((void (__thiscall*)(Inner*))vt[1])(ip);
            if (_InterlockedExchangeAdd((volatile long*)((char*)ip + 8), -1) == 1) {
                void** vt2 = *(void***)ip;
                ((void (__thiscall*)(Inner*))vt2[2])(ip);
            }
        }
    }
    return this->field0;
}
