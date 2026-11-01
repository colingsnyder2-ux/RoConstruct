// from server: 100% by user
// from server: 99% by king_originala
// roc 2008-06 004211b0  unit: RBX::VInstance::?$MarshaledListener  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004211b0
//
// 004211b0  51                   push ecx
// 004211b1  56                   push esi
// 004211b2  57                   push edi
// 004211b3  8bf9                 mov edi, ecx
// 004211b5  8b7720               mov esi, dword ptr [edi + 0x20]
// 004211b8  83c62c               add esi, 0x2c
// 004211bb  56                   push esi
// 004211bc  ff15d4228000         call dword ptr [0x8022d4]
// 004211c2  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004211c6  83ec10               sub esp, 0x10
// 004211c9  8bc4                 mov eax, esp
// 004211cb  8908                 mov dword ptr [eax], ecx
// 004211cd  8b542428             mov edx, dword ptr [esp + 0x28]
// 004211d1  895004               mov dword ptr [eax + 4], edx
// 004211d4  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004211d8  89642418             mov dword ptr [esp + 0x18], esp
// 004211dc  85c9                 test ecx, ecx
// 004211de  740c                 je 0x4211ec
// 004211e0  83c104               add ecx, 4
// 004211e3  ba01000000           mov edx, 1
// 004211e8  f00fc111             lock xadd dword ptr [ecx], edx
// 004211ec  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004211f0  894808               mov dword ptr [eax + 8], ecx
// 004211f3  8b542430             mov edx, dword ptr [esp + 0x30]
// 004211f7  89500c               mov dword ptr [eax + 0xc], edx
// 004211fa  8b442430             mov eax, dword ptr [esp + 0x30]
// 004211fe  85c0                 test eax, eax
// 00421200  740c                 je 0x42120e
// 00421202  83c004               add eax, 4
// 00421205  b901000000           mov ecx, 1
// 0042120a  f00fc108             lock xadd dword ptr [eax], ecx
// 0042120e  8b17                 mov edx, dword ptr [edi]
// 00421210  8b442420             mov eax, dword ptr [esp + 0x20]
// 00421214  8b520c               mov edx, dword ptr [edx + 0xc]
// 00421217  50                   push eax
// 00421218  8bcf                 mov ecx, edi
// 0042121a  ffd2                 call edx
// 0042121c  56                   push esi
// 0042121d  ff15f4218000         call dword ptr [0x8021f4]
// 00421223  8d4c2414             lea ecx, [esp + 0x14]
// 00421227  e8341a0000           call 0x422c60
// 0042122c  5f                   pop edi
// 0042122d  5e                   pop esi
// 0042122e  59                   pop ecx
// 0042122f  c21400               ret 0x14

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

extern "C" {
    extern void (__stdcall *EnterCriticalSection)(void*);
    extern void (__stdcall *LeaveCriticalSection)(void*);
}

struct Control {
    long unused;
    volatile long strong;
};

struct Shared {
    void* pointer;
    Control* control;

    __forceinline Shared(const Shared& other)
        : pointer(other.pointer), control(other.control)
    {
        if (control) {
            volatile long* count = &control->strong;
            _ReadWriteBarrier();
            _InterlockedExchangeAdd(count, 1);
        }
    }
    ~Shared() throw();
};

struct Arguments {
    Shared first;
    Shared second;
    ~Arguments() throw();
};

struct Listener {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void dispatch(void*, Arguments) throw();

    char padding[28];
    char* owner;

    void invoke(void* value, Arguments arguments) throw();
};

void Listener::invoke(void* value, Arguments arguments) throw()
{
    void* criticalSection = owner + 44;
    EnterCriticalSection(criticalSection);
    dispatch(value, arguments);
    LeaveCriticalSection(criticalSection);
}
