// from server: 37% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void addRef() { _InterlockedExchangeAdd((volatile long*)((char*)this + 8), 1); }
};

struct FuncDescBase {
    void init();
};

struct BoundFuncDesc {
    int field0;
    void construct(int a, int b, int c, RefCounted* d, int e, int f, int g, RefCounted* h);
};

void BoundFuncDesc::construct(int a, int b, int c, RefCounted* d, int e, int f, int g, RefCounted* h)
{
    field0 = 0;
    if (d) {
        _InterlockedExchangeAdd((volatile long*)((char*)d + 8), 1);
    }
    if (h) {
        _InterlockedExchangeAdd((volatile long*)((char*)h + 4), 1);
    }
    ((FuncDescBase*)this)->init();
}
