// from server: 100% by EspClaude
// from server: 95% by EspClaude
// roc 2009-06 004087a0  unit: VCApp::?$CComObject  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004087a0
//
// 004087a0  6aff                 push -1
// 004087a2  686b088500           push 0x85086b
// 004087a7  64a100000000         mov eax, dword ptr fs:[0]
// 004087ad  50                   push eax
// 004087ae  64892500000000       mov dword ptr fs:[0], esp
// 004087b5  83ec08               sub esp, 8
// 004087b8  c7042400000000       mov dword ptr [esp], 0
// 004087bf  680c010000           push 0x10c
// 004087c4  c644240400           mov byte ptr [esp + 4], 0
// 004087c9  e86a023100           call 0x718a38
// 004087ce  83c404               add esp, 4
// 004087d1  89442404             mov dword ptr [esp + 4], eax
// 004087d5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004087dd  85c0                 test eax, eax
// 004087df  7409                 je 0x4087ea
// 004087e1  8bc8                 mov ecx, eax
// 004087e3  e878b20300           call 0x443a60
// 004087e8  eb02                 jmp 0x4087ec
// 004087ea  33c0                 xor eax, eax
// 004087ec  8b0c24               mov ecx, dword ptr [esp]
// 004087ef  56                   push esi
// 004087f0  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004087f4  51                   push ecx
// 004087f5  50                   push eax
// 004087f6  8bce                 mov ecx, esi
// 004087f8  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00408800  e8ebfeffff           call 0x4086f0
// 00408805  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00408809  8bc6                 mov eax, esi
// 0040880b  5e                   pop esi
// 0040880c  64890d00000000       mov dword ptr fs:[0], ecx
// 00408813  83c414               add esp, 0x14
// 00408816  c3                   ret 

// from server: 100% by tester
// roc 2008-06 00408ed0  unit: RBX::VDebugSettings::?$FactoryProduct::Creator  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00408ed0
//
// 00408ed0  6aff                 push -1
// 00408ed2  683b467d00           push 0x7d463b
// 00408ed7  64a100000000         mov eax, dword ptr fs:[0]
// 00408edd  50                   push eax
// 00408ede  64892500000000       mov dword ptr fs:[0], esp
// 00408ee5  83ec08               sub esp, 8
// 00408ee8  c7042400000000       mov dword ptr [esp], 0
// 00408eef  687c010000           push 0x17c
// 00408ef4  c644240400           mov byte ptr [esp + 4], 0
// 00408ef9  ff15b0288000         call dword ptr [0x8028b0]
// 00408eff  83c404               add esp, 4
// 00408f02  89442404             mov dword ptr [esp + 4], eax
// 00408f06  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00408f0e  85c0                 test eax, eax
// 00408f10  7409                 je 0x408f1b
// 00408f12  8bc8                 mov ecx, eax
// 00408f14  e847fd0300           call 0x448c60
// 00408f19  eb02                 jmp 0x408f1d
// 00408f1b  33c0                 xor eax, eax
// 00408f1d  8b0c24               mov ecx, dword ptr [esp]
// 00408f20  56                   push esi
// 00408f21  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00408f25  51                   push ecx
// 00408f26  50                   push eax
// 00408f27  8bce                 mov ecx, esi
// 00408f29  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00408f31  e8eafeffff           call 0x408e20
// 00408f36  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00408f3a  8bc6                 mov eax, esi
// 00408f3c  5e                   pop esi
// 00408f3d  64890d00000000       mov dword ptr fs:[0], ecx
// 00408f44  83c414               add esp, 0x14
// 00408f47  c3                   ret 

void* __cdecl operator new(unsigned int size);

void __cdecl operator delete(void*);

struct Product {
    unsigned char storage[0x10c];
    Product();
};

struct Deleter {
    union {
        unsigned int value;
        unsigned char unused;
    };
};

struct Result {
    Result(Product*, Deleter);
};

Result __cdecl create()
{
    Deleter deleter = { 0 };
    *(volatile unsigned char*)&deleter.unused = 0;
    return Result(new Product, deleter);
}
