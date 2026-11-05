// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct String;
extern String* (__thiscall *stringCopy)(String*, const String&);

struct String {
    char data[28];
    String(const String&);
    ~String();
};

inline String::String(const String& source)
{
    stringCopy(this, source);
}

inline void increment(volatile long* value)
{
    _ReadWriteBarrier();
    _InterlockedExchangeAdd(value, 1);
}

struct RefCount {
    long reserved;
    volatile long count;
    void addRef() { _InterlockedIncrement(&count); }
};

struct Count {
    RefCount* pi;
    Count(const Count& other) : pi(other.pi)
    {
        if (pi != 0)
            pi->addRef();
    }
};

struct Shared {
    void* px;
    Count pn;
};

struct S {
    String first;
    String second;
    Shared firstShared;
    Shared secondShared;

    S(const S&);
};

S::S(const S& source)
    : first(source.first), second(source.second),
      firstShared(source.firstShared), secondShared(source.secondShared)
{
}