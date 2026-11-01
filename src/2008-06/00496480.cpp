// from server: 100% by colin
// from server: 97% by king_originala
// roc 2008-06 00496480  unit: RBX::Network::Players::Plugin  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00496480
//
// 00496480  6aff                 push -1
// 00496482  68496b7c00           push 0x7c6b49
// 00496487  64a100000000         mov eax, dword ptr fs:[0]
// 0049648d  50                   push eax
// 0049648e  64892500000000       mov dword ptr fs:[0], esp
// 00496495  51                   push ecx
// 00496496  56                   push esi
// 00496497  57                   push edi
// 00496498  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0049649c  8bf1                 mov esi, ecx
// 0049649e  57                   push edi
// 0049649f  8974240c             mov dword ptr [esp + 0xc], esi
// 004964a3  ff155c248000         call dword ptr [0x80245c]
// 004964a9  8d471c               lea eax, [edi + 0x1c]
// 004964ac  50                   push eax
// 004964ad  8d4e1c               lea ecx, [esi + 0x1c]
// 004964b0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004964b8  ff155c248000         call dword ptr [0x80245c]
// 004964be  8b4f38               mov ecx, dword ptr [edi + 0x38]
// 004964c1  894e38               mov dword ptr [esi + 0x38], ecx
// 004964c4  8b473c               mov eax, dword ptr [edi + 0x3c]
// 004964c7  89463c               mov dword ptr [esi + 0x3c], eax
// 004964ca  85c0                 test eax, eax
// 004964cc  740c                 je 0x4964da
// 004964ce  83c004               add eax, 4
// 004964d1  ba01000000           mov edx, 1
// 004964d6  f00fc110             lock xadd dword ptr [eax], edx
// 004964da  8b4740               mov eax, dword ptr [edi + 0x40]
// 004964dd  894640               mov dword ptr [esi + 0x40], eax
// 004964e0  8b7f44               mov edi, dword ptr [edi + 0x44]
// 004964e3  897e44               mov dword ptr [esi + 0x44], edi
// 004964e6  85ff                 test edi, edi
// 004964e8  740c                 je 0x4964f6
// 004964ea  83c704               add edi, 4
// 004964ed  b901000000           mov ecx, 1
// 004964f2  f00fc10f             lock xadd dword ptr [edi], ecx
// 004964f6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004964fa  5f                   pop edi
// 004964fb  8bc6                 mov eax, esi
// 004964fd  5e                   pop esi
// 004964fe  64890d00000000       mov dword ptr fs:[0], ecx
// 00496505  83c410               add esp, 0x10
// 00496508  c20400               ret 4

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
