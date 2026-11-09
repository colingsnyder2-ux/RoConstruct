// from server: 47% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[0xc];
    int* begin;
    int* end;
};

struct Outer {
    char pad0[0x4c];
    void* field4c;
};

struct RefCounted {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    long ref1;
    long ref2;
};

struct S {
    void method(int, int, int, int, int);
};

extern "C" void __stdcall sub_5f50c0(int, int, int, int, int);

void* sub_409630_helper(void* p, void* out);

void S::method(int a, int b, int c, int d, int e)
{
    int local = 0;
    Inner* inner = *(Inner**)((char*)this + 0x50);
    if (inner != 0) {
        int count = (int)((inner->end - inner->begin) >> 3);
        if (count > 0) {
            void* p = ((Outer*)this)->field4c;
            int tmp = 0;
            sub_409630_helper(inner, &tmp);
            int v = *(int*)&tmp;
            sub_5f50c0(*(int*)((char*)p + 0xaa0), v, 2, 1, (int)&local);
            RefCounted* rc = (RefCounted*)local;
            if (rc != 0) {
                if (_InterlockedExchangeAdd(&rc->ref1, -1) == 1) {
                    rc->f1();
                    if (_InterlockedExchangeAdd(&rc->ref2, -1) == 1) {
                        rc->f2();
                    }
                }
            }
        }
    }
    RefCounted* rc2 = (RefCounted*)local;
    if (rc2 != 0) {
        if (_InterlockedExchangeAdd(&rc2->ref1, -1) == 1) {
            rc2->f1();
            if (_InterlockedExchangeAdd(&rc2->ref2, -1) == 1) {
                rc2->f2();
            }
        }
    }
}
