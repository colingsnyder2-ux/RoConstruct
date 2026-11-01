// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct String {
    char storage[28];
};

typedef void (__thiscall *StringCopy)(String*, const String&);
extern StringCopy copyString;

struct Control {
    long reserved;
    volatile long references;
};

struct S : String {
    long value;
    void* first;
    Control* firstControl;
    void* second;
    Control* secondControl;

    S(const S&);
};

S::S(const S& source)
{
    copyString(this, source);
    value = source.value;
    first = source.first;
    firstControl = source.firstControl;
    if (firstControl) {
        volatile long* count = &firstControl->references;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(count, 1);
    }

    second = source.second;
    Control* control = source.secondControl;
    secondControl = control;
    if (control) {
        volatile long* count = &control->references;
        _ReadWriteBarrier();
        _InterlockedIncrement(count);
    }
}