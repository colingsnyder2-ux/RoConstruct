// from server: 84% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00456620  unit: CRobloxReportView::CStatsItemRecord::CNameItem  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00456620
//
// 00456620  6aff                 push -1
// 00456622  6813247c00           push 0x7c2413
// 00456627  64a100000000         mov eax, dword ptr fs:[0]
// 0045662d  50                   push eax
// 0045662e  64892500000000       mov dword ptr fs:[0], esp
// 00456635  83ec08               sub esp, 8
// 00456638  56                   push esi
// 00456639  8bf1                 mov esi, ecx
// 0045663b  57                   push edi
// 0045663c  89742408             mov dword ptr [esp + 8], esi
// 00456640  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00456644  83ec08               sub esp, 8
// 00456647  8bc4                 mov eax, esp
// 00456649  8908                 mov dword ptr [eax], ecx
// 0045664b  8b542430             mov edx, dword ptr [esp + 0x30]
// 0045664f  895004               mov dword ptr [eax + 4], edx
// 00456652  8b442430             mov eax, dword ptr [esp + 0x30]
// 00456656  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0045665e  89642414             mov dword ptr [esp + 0x14], esp
// 00456662  85c0                 test eax, eax
// 00456664  740c                 je 0x456672
// 00456666  83c004               add eax, 4
// 00456669  b901000000           mov ecx, 1
// 0045666e  f00fc108             lock xadd dword ptr [eax], ecx
// 00456672  8d4e7c               lea ecx, [esi + 0x7c]
// 00456675  e896e10f00           call 0x554810
// 0045667a  8bce                 mov ecx, esi
// 0045667c  c644241801           mov byte ptr [esp + 0x18], 1
// 00456681  e8ba0c2700           call 0x6c7340
// 00456686  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0045668a  8b542420             mov edx, dword ptr [esp + 0x20]
// 0045668e  c706f4858100         mov dword ptr [esi], 0x8185f4
// 00456694  899684000000         mov dword ptr [esi + 0x84], edx
// 0045669a  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004566a2  85ff                 test edi, edi
// 004566a4  742a                 je 0x4566d0
// 004566a6  8d4704               lea eax, [edi + 4]
// 004566a9  83c9ff               or ecx, 0xffffffff
// 004566ac  f00fc108             lock xadd dword ptr [eax], ecx
// 004566b0  751e                 jne 0x4566d0
// 004566b2  8b17                 mov edx, dword ptr [edi]
// 004566b4  8b4204               mov eax, dword ptr [edx + 4]
// 004566b7  8bcf                 mov ecx, edi
// 004566b9  ffd0                 call eax
// 004566bb  8d4f08               lea ecx, [edi + 8]
// 004566be  83caff               or edx, 0xffffffff
// 004566c1  f00fc111             lock xadd dword ptr [ecx], edx
// 004566c5  7509                 jne 0x4566d0
// 004566c7  8b07                 mov eax, dword ptr [edi]
// 004566c9  8b5008               mov edx, dword ptr [eax + 8]
// 004566cc  8bcf                 mov ecx, edi
// 004566ce  ffd2                 call edx
// 004566d0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004566d4  5f                   pop edi
// 004566d5  8bc6                 mov eax, esi
// 004566d7  64890d00000000       mov dword ptr fs:[0], ecx
// 004566de  5e                   pop esi
// 004566df  83c414               add esp, 0x14
// 004566e2  c20c00               ret 0xc

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;

    void release();
    void releaseWeak();
};

inline void Control::releaseWeak()
{
    if (_InterlockedDecrement(&weak) == 0)
        destroy();
}

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        releaseWeak();
    }
}

struct Ptr
{
    void* object;
    Control* control;

    Ptr(const Ptr&);
    ~Ptr();
};

inline Ptr::Ptr(const Ptr& other)
    : object(other.object), control(other.control)
{
    if (control)
    {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Ptr::~Ptr()
{
    if (control)
        control->release();
}

struct Holder
{
    void* object;
    Control* control;

    Holder(Ptr);
    ~Holder();
};

struct RecordItem
{
    virtual void reserved();
    char data[120];

    RecordItem();
    ~RecordItem();
};

struct S : Holder, RecordItem
{
    int index;

    S(int, Ptr);
    virtual void reserved();
};

S::S(int value, Ptr pointer)
    : Holder(pointer), RecordItem(), index(value)
{
}
