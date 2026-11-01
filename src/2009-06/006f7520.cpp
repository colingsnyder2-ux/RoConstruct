// from server: 100% by EspClaude
// roc 2009-06 006f7520  unit: RBX::VGroupDragTool::?$Named  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006f7520
//
// 006f7520  6aff                 push -1
// 006f7522  68780e8700           push 0x870e78
// 006f7527  64a100000000         mov eax, dword ptr fs:[0]
// 006f752d  50                   push eax
// 006f752e  64892500000000       mov dword ptr fs:[0], esp
// 006f7535  51                   push ecx
// 006f7536  56                   push esi
// 006f7537  8bf1                 mov esi, ecx
// 006f7539  57                   push edi
// 006f753a  89742408             mov dword ptr [esp + 8], esi
// 006f753e  c706d4e98e00         mov dword ptr [esi], 0x8ee9d4
// 006f7544  c74604bce98e00       mov dword ptr [esi + 4], 0x8ee9bc
// 006f754b  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 006f754e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 006f7556  85ff                 test edi, edi
// 006f7558  7410                 je 0x6f756a
// 006f755a  8bcf                 mov ecx, edi
// 006f755c  e82fb5fbff           call 0x6b2a90
// 006f7561  57                   push edi
// 006f7562  e8cb140200           call 0x718a32
// 006f7567  83c404               add esp, 4
// 006f756a  8bce                 mov ecx, esi
// 006f756c  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 006f7574  e807e6fbff           call 0x6b5b80
// 006f7579  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006f757d  5f                   pop edi
// 006f757e  5e                   pop esi
// 006f757f  64890d00000000       mov dword ptr fs:[0], ecx
// 006f7586  83c410               add esp, 0x10
// 006f7589  c3                   ret 
// copied from an identical function in another client (function ??1S@@UAE@XZ)

void __cdecl operator delete(void *);

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    unsigned int reserved[5];
    virtual ~Base();
};

struct Owned {
    ~Owned();
};

struct S : Base {
    Owned *owned;
    virtual ~S();
};

S::~S()
{
    delete owned;
}