// from server: 100% by Intel
// from server: 99% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 0043d330  unit: RBX::Soundscape::VSoundId::?$XItem  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043d330
//
// 0043d330  6aff                 push -1
// 0043d332  6868077c00           push 0x7c0768
// 0043d337  64a100000000         mov eax, dword ptr fs:[0]
// 0043d33d  50                   push eax
// 0043d33e  64892500000000       mov dword ptr fs:[0], esp
// 0043d345  51                   push ecx
// 0043d346  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043d34a  56                   push esi
// 0043d34b  8bf1                 mov esi, ecx
// 0043d34d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0043d351  50                   push eax
// 0043d352  51                   push ecx
// 0043d353  8bce                 mov ecx, esi
// 0043d355  8974240c             mov dword ptr [esp + 0xc], esi
// 0043d359  e892cdffff           call 0x43a0f0
// 0043d35e  6a01                 push 1
// 0043d360  8bce                 mov ecx, esi
// 0043d362  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0043d36a  c7069c468100         mov dword ptr [esi], 0x81469c
// 0043d370  c746203c468100       mov dword ptr [esi + 0x20], 0x81463c
// 0043d377  c7862001000034468100 mov dword ptr [esi + 0x120], 0x814634
// 0043d381  e8faa32d00           call 0x717780
// 0043d386  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043d38a  8bc6                 mov eax, esi
// 0043d38c  5e                   pop esi
// 0043d38d  64890d00000000       mov dword ptr fs:[0], ecx
// 0043d394  83c410               add esp, 0x10
// 0043d397  c20800               ret 8

struct Primary {
    virtual ~Primary();
    char storage[0x1C];
};

struct Secondary {
    virtual ~Secondary();
    char storage[0xF0];
};

struct Tertiary {
    virtual ~Tertiary();
};

struct Base : Primary, Secondary, Tertiary {
    Base(int, int);
    virtual ~Base();
    void SetCheckBoxStyle(int);
};

struct S : Base {
    S(int, int);
    virtual ~S();
};

S::S(int a, int b) : Base(a, b) {
    SetCheckBoxStyle(1);
}
