// from server: 82% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
struct T { int a; volatile long refs; };
T* __cdecl helper(int*);
void f(T** out, int a) {
    volatile int z = 0;
    T* p = helper(&a);
    *out = p;
    if (p) _InterlockedExchangeAdd(&p->refs, 1);
}