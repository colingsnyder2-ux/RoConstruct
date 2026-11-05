// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0045ee60  unit: G3D::VStopwatch::?$TypedStatsItem  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045ee60
//
// 0045ee60  6aff                 push -1
// 0045ee62  68982f7c00           push 0x7c2f98
// 0045ee67  64a100000000         mov eax, dword ptr fs:[0]
// 0045ee6d  50                   push eax
// 0045ee6e  64892500000000       mov dword ptr fs:[0], esp
// 0045ee75  51                   push ecx
// 0045ee76  56                   push esi
// 0045ee77  8bf1                 mov esi, ecx
// 0045ee79  89742404             mov dword ptr [esp + 4], esi
// 0045ee7d  8b8658010000         mov eax, dword ptr [esi + 0x158]
// 0045ee83  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0045ee8b  85c0                 test eax, eax
// 0045ee8d  741f                 je 0x45eeae
// 0045ee8f  8b00                 mov eax, dword ptr [eax]
// 0045ee91  8d8e60010000         lea ecx, [esi + 0x160]
// 0045ee97  85c0                 test eax, eax
// 0045ee99  7409                 je 0x45eea4
// 0045ee9b  6a01                 push 1
// 0045ee9d  51                   push ecx
// 0045ee9e  51                   push ecx
// 0045ee9f  ffd0                 call eax
// 0045eea1  83c40c               add esp, 0xc
// 0045eea4  c7865801000000000000 mov dword ptr [esi + 0x158], 0
// 0045eeae  8bce                 mov ecx, esi
// 0045eeb0  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0045eeb8  e853cbffff           call 0x45ba10
// 0045eebd  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0045eec1  5e                   pop esi
// 0045eec2  64890d00000000       mov dword ptr fs:[0], ecx
// 0045eec9  83c410               add esp, 0x10
// 0045eecc  c3                   ret 

typedef void (__cdecl *Manager)(void *, void *, int);

struct Base
{
    char storage[0xb8];
    ~Base();
};

struct S : Base
{
    Manager *manager;
    unsigned int padding;
    char buffer[16];

    ~S();
};

S::~S()
{
    if (manager)
    {
        Manager destroy = *manager;
        void *data = buffer;
        if (destroy)
            destroy(data, data, 2);
        manager = 0;
    }
}
