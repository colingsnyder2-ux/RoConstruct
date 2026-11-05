// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0060ca00  unit: RBX::VMotorFeature::?$FactoryProduct  size: 209 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060ca00
//
// 0060ca00  64a100000000         mov eax, dword ptr fs:[0]
// 0060ca06  6aff                 push -1
// 0060ca08  6868917d00           push 0x7d9168
// 0060ca0d  50                   push eax
// 0060ca0e  64892500000000       mov dword ptr fs:[0], esp
// 0060ca15  83ec08               sub esp, 8
// 0060ca18  53                   push ebx
// 0060ca19  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0060ca1d  56                   push esi
// 0060ca1e  8b742420             mov esi, dword ptr [esp + 0x20]
// 0060ca22  53                   push ebx
// 0060ca23  56                   push esi
// 0060ca24  e837d0ffff           call 0x609a60
// 0060ca29  83c408               add esp, 8
// 0060ca2c  84c0                 test al, al
// 0060ca2e  0f848c000000         je 0x60cac0
// 0060ca34  57                   push edi
// 0060ca35  6a00                 push 0
// 0060ca37  68289a9500           push 0x959a28
// 0060ca3c  687c909200           push 0x92907c
// 0060ca41  6a00                 push 0
// 0060ca43  56                   push esi
// 0060ca44  e87d4d0900           call 0x6a17c6
// 0060ca49  83c414               add esp, 0x14
// 0060ca4c  85c0                 test eax, eax
// 0060ca4e  7404                 je 0x60ca54
// 0060ca50  8bfe                 mov edi, esi
// 0060ca52  eb06                 jmp 0x60ca5a
// 0060ca54  8bfb                 mov edi, ebx
// 0060ca56  3bde                 cmp ebx, esi
// 0060ca58  7502                 jne 0x60ca5c
// 0060ca5a  8bf3                 mov esi, ebx
// 0060ca5c  8d44240c             lea eax, [esp + 0xc]
// 0060ca60  50                   push eax
// 0060ca61  e83a3af7ff           call 0x5804a0
// 0060ca66  83c404               add esp, 4
// 0060ca69  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0060ca6d  57                   push edi
// 0060ca6e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0060ca76  e885f9ffff           call 0x60c400
// 0060ca7b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0060ca7f  56                   push esi
// 0060ca80  e86bdef4ff           call 0x55a8f0
// 0060ca85  8b742410             mov esi, dword ptr [esp + 0x10]
// 0060ca89  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0060ca91  5f                   pop edi
// 0060ca92  85f6                 test esi, esi
// 0060ca94  742a                 je 0x60cac0
// 0060ca96  8d4e04               lea ecx, [esi + 4]
// 0060ca99  83caff               or edx, 0xffffffff
// 0060ca9c  f00fc111             lock xadd dword ptr [ecx], edx
// 0060caa0  751e                 jne 0x60cac0
// 0060caa2  8b06                 mov eax, dword ptr [esi]
// 0060caa4  8b5004               mov edx, dword ptr [eax + 4]
// 0060caa7  8bce                 mov ecx, esi
// 0060caa9  ffd2                 call edx
// 0060caab  8d4608               lea eax, [esi + 8]
// 0060caae  83c9ff               or ecx, 0xffffffff
// 0060cab1  f00fc108             lock xadd dword ptr [eax], ecx
// 0060cab5  7509                 jne 0x60cac0
// 0060cab7  8b16                 mov edx, dword ptr [esi]
// 0060cab9  8b4208               mov eax, dword ptr [edx + 8]
// 0060cabc  8bce                 mov ecx, esi
// 0060cabe  ffd0                 call eax
// 0060cac0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0060cac4  5e                   pop esi
// 0060cac5  5b                   pop ebx
// 0060cac6  64890d00000000       mov dword ptr fs:[0], ecx
// 0060cacd  83c414               add esp, 0x14
// 0060cad0  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Instance;

struct Hole {
    void setFirst(Instance*);
    void setSecond(Instance*);
};

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

struct SharedHole {
    Hole* object;
    Control* control;
    ~SharedHole();
};

extern bool __cdecl eligible(Instance*, Instance*);
extern SharedHole __cdecl createHole();
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

extern char instanceType;
extern char holeType;

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

__forceinline SharedHole::~SharedHole()
{
    if (control)
        control->release();
}

void __cdecl connectHole(Instance* a, Instance* b)
{
    if (eligible(a, b)) {
        Instance* first;
        if (__RTDynamicCast(a, 0, &instanceType, &holeType, 0))
            first = a;
        else
            first = b;

        if (first == a)
            a = b;

        SharedHole hole = createHole();
        hole.object->setFirst(first);
        hole.object->setSecond(a);
    }
}
