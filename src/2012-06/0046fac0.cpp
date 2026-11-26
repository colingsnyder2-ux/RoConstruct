// from server: 100% by Xemicl
// roc 2012-06 0046fac0  unit: CRobloxApp  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046fac0
//
// 0046fac0  6aff                 push -1
// 0046fac2  6898dea900           push 0xa9de98
// 0046fac7  64a100000000         mov eax, dword ptr fs:[0]
// 0046facd  50                   push eax
// 0046face  64892500000000       mov dword ptr fs:[0], esp
// 0046fad5  51                   push ecx
// 0046fad6  56                   push esi
// 0046fad7  8bf1                 mov esi, ecx
// 0046fad9  57                   push edi
// 0046fada  89742408             mov dword ptr [esp + 8], esi
// 0046fade  8b7e08               mov edi, dword ptr [esi + 8]
// 0046fae1  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0046fae9  85ff                 test edi, edi
// 0046faeb  7410                 je 0x46fafd
// 0046faed  8bcf                 mov ecx, edi
// 0046faef  e85c465000           call 0x974150
// 0046faf4  57                   push edi
// 0046faf5  e81a265100           call 0x982114
// 0046fafa  83c404               add esp, 4
// 0046fafd  8b7604               mov esi, dword ptr [esi + 4]
// 0046fb00  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0046fb08  85f6                 test esi, esi
// 0046fb0a  742a                 je 0x46fb36
// 0046fb0c  8d4604               lea eax, [esi + 4]
// 0046fb0f  83c9ff               or ecx, 0xffffffff
// 0046fb12  f00fc108             lock xadd dword ptr [eax], ecx
// 0046fb16  751e                 jne 0x46fb36
// 0046fb18  8b16                 mov edx, dword ptr [esi]
// 0046fb1a  8b4204               mov eax, dword ptr [edx + 4]
// 0046fb1d  8bce                 mov ecx, esi
// 0046fb1f  ffd0                 call eax
// 0046fb21  8d4e08               lea ecx, [esi + 8]
// 0046fb24  83caff               or edx, 0xffffffff
// 0046fb27  f00fc111             lock xadd dword ptr [ecx], edx
// 0046fb2b  7509                 jne 0x46fb36
// 0046fb2d  8b06                 mov eax, dword ptr [esi]
// 0046fb2f  8b5008               mov edx, dword ptr [eax + 8]
// 0046fb32  8bce                 mov ecx, esi
// 0046fb34  ffd2                 call edx
// 0046fb36  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046fb3a  5f                   pop edi
// 0046fb3b  5e                   pop esi
// 0046fb3c  64890d00000000       mov dword ptr fs:[0], ecx
// 0046fb43  83c410               add esp, 0x10
// 0046fb46  c3                   ret 
// copied from an identical function in another client (function ??1S@@QAE@XZ)

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

void __cdecl operator delete(void*);

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

struct Payload {
    ~Payload();
};

struct S {
    Shared shared;
    Payload* payload;
    ~S();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

S::~S()
{
    delete payload;
}