// from server: 100% by Yeetserama
// roc 2011-06 006fb4c0  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 209 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006fb4c0
//
// 006fb4c0  64a100000000         mov eax, dword ptr fs:[0]
// 006fb4c6  6aff                 push -1
// 006fb4c8  6868449d00           push 0x9d4468
// 006fb4cd  50                   push eax
// 006fb4ce  64892500000000       mov dword ptr fs:[0], esp
// 006fb4d5  83ec08               sub esp, 8
// 006fb4d8  53                   push ebx
// 006fb4d9  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 006fb4dd  56                   push esi
// 006fb4de  8b742420             mov esi, dword ptr [esp + 0x20]
// 006fb4e2  53                   push ebx
// 006fb4e3  56                   push esi
// 006fb4e4  e847deffff           call 0x6f9330
// 006fb4e9  83c408               add esp, 8
// 006fb4ec  84c0                 test al, al
// 006fb4ee  0f848c000000         je 0x6fb580
// 006fb4f4  57                   push edi
// 006fb4f5  6a00                 push 0
// 006fb4f7  685490c700           push 0xc79054
// 006fb4fc  68f871c000           push 0xc071f8
// 006fb501  6a00                 push 0
// 006fb503  56                   push esi
// 006fb504  e8e1fd1000           call 0x80b2ea
// 006fb509  83c414               add esp, 0x14
// 006fb50c  85c0                 test eax, eax
// 006fb50e  7404                 je 0x6fb514
// 006fb510  8bfe                 mov edi, esi
// 006fb512  eb06                 jmp 0x6fb51a
// 006fb514  8bfb                 mov edi, ebx
// 006fb516  3bde                 cmp ebx, esi
// 006fb518  7502                 jne 0x6fb51c
// 006fb51a  8bf3                 mov esi, ebx
// 006fb51c  8d44240c             lea eax, [esp + 0xc]
// 006fb520  50                   push eax
// 006fb521  e8da8fedff           call 0x5d4500
// 006fb526  83c404               add esp, 4
// 006fb529  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006fb52d  57                   push edi
// 006fb52e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 006fb536  e865fdffff           call 0x6fb2a0
// 006fb53b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006fb53f  56                   push esi
// 006fb540  e8cbc3e9ff           call 0x597910
// 006fb545  8b742410             mov esi, dword ptr [esp + 0x10]
// 006fb549  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 006fb551  5f                   pop edi
// 006fb552  85f6                 test esi, esi
// 006fb554  742a                 je 0x6fb580
// 006fb556  8d4e04               lea ecx, [esi + 4]
// 006fb559  83caff               or edx, 0xffffffff
// 006fb55c  f00fc111             lock xadd dword ptr [ecx], edx
// 006fb560  751e                 jne 0x6fb580
// 006fb562  8b06                 mov eax, dword ptr [esi]
// 006fb564  8b5004               mov edx, dword ptr [eax + 4]
// 006fb567  8bce                 mov ecx, esi
// 006fb569  ffd2                 call edx
// 006fb56b  8d4608               lea eax, [esi + 8]
// 006fb56e  83c9ff               or ecx, 0xffffffff
// 006fb571  f00fc108             lock xadd dword ptr [eax], ecx
// 006fb575  7509                 jne 0x6fb580
// 006fb577  8b16                 mov edx, dword ptr [esi]
// 006fb579  8b4208               mov eax, dword ptr [edx + 8]
// 006fb57c  8bce                 mov ecx, esi
// 006fb57e  ffd0                 call eax
// 006fb580  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006fb584  5e                   pop esi
// 006fb585  5b                   pop ebx
// 006fb586  64890d00000000       mov dword ptr fs:[0], ecx
// 006fb58d  83c414               add esp, 0x14
// 006fb590  c3                   ret 
// copied from an identical function in another client (function ?connectHole@ns_ROCX00000e@@YAXPAUInstance@1@0@Z)

namespace ns_ROCX00000e {
// from server: 100% by king_originala
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
}
