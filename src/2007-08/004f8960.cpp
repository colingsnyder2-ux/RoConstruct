// from server: 100% by Intel
﻿// from server: 78% by EspClaude
// roc 2007-08 004f8960  unit: G3D::Sphere  size: 340 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f8960
//
// 004f8960  6aff                 push -1
// 004f8962  6850e07400           push 0x74e050
// 004f8967  64a100000000         mov eax, dword ptr fs:[0]
// 004f896d  50                   push eax
// 004f896e  83ec20               sub esp, 0x20
// 004f8971  53                   push ebx
// 004f8972  56                   push esi
// 004f8973  57                   push edi
// 004f8974  a188518b00           mov eax, dword ptr [0x8b5188]
// 004f8979  33c4                 xor eax, esp
// 004f897b  50                   push eax
// 004f897c  8d442430             lea eax, [esp + 0x30]
// 004f8980  64a300000000         mov dword ptr fs:[0], eax
// 004f8986  8bf9                 mov edi, ecx
// 004f8988  8b5c2440             mov ebx, dword ptr [esp + 0x40]
// 004f898c  8b4304               mov eax, dword ptr [ebx + 4]
// 004f898f  8b4f68               mov ecx, dword ptr [edi + 0x68]
// 004f8992  85c9                 test ecx, ecx
// 004f8994  8d7768               lea esi, [edi + 0x68]
// 004f8997  8d0440               lea eax, [eax + eax*2]
// 004f899a  8d048510000000       lea eax, [eax*4 + 0x10]
// 004f89a1  740c                 je 0x4f89af
// 004f89a3  394128               cmp dword ptr [ecx + 0x28], eax
// 004f89a6  7207                 jb 0x4f89af
// 004f89a8  e803a1f7ff           call 0x472ab0
// 004f89ad  eb59                 jmp 0x4f8a08
// 004f89af  6a02                 push 2
// 004f89b1  50                   push eax
// 004f89b2  8d442448             lea eax, [esp + 0x48]
// 004f89b6  50                   push eax
// 004f89b7  e824a5f7ff           call 0x472ee0
// 004f89bc  83c40c               add esp, 0xc
// 004f89bf  8b08                 mov ecx, dword ptr [eax]
// 004f89c1  51                   push ecx
// 004f89c2  8bce                 mov ecx, esi
// 004f89c4  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 004f89cc  e89fc5f7ff           call 0x474f70
// 004f89d1  8b442440             mov eax, dword ptr [esp + 0x40]
// 004f89d5  85c0                 test eax, eax
// 004f89d7  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 004f89df  7427                 je 0x4f8a08
// 004f89e1  83c004               add eax, 4
// 004f89e4  50                   push eax
// 004f89e5  ff15e8d27700         call dword ptr [0x77d2e8]
// 004f89eb  85c0                 test eax, eax
// 004f89ed  7519                 jne 0x4f8a08
// 004f89ef  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 004f89f3  e8d8f3f5ff           call 0x457dd0
// 004f89f8  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 004f89fc  85c9                 test ecx, ecx
// 004f89fe  7408                 je 0x4f8a08
// 004f8a00  8b11                 mov edx, dword ptr [ecx]
// 004f8a02  8b02                 mov eax, dword ptr [edx]
// 004f8a04  6a01                 push 1
// 004f8a06  ffd0                 call eax
// 004f8a08  51                   push ecx
// 004f8a09  8bcc                 mov ecx, esp
// 004f8a0b  c70100000000         mov dword ptr [ecx], 0
// 004f8a11  8b16                 mov edx, dword ptr [esi]
// 004f8a13  89642444             mov dword ptr [esp + 0x44], esp
// 004f8a17  52                   push edx
// 004f8a18  e853c5f7ff           call 0x474f70
// 004f8a1d  53                   push ebx
// 004f8a1e  8d4c2418             lea ecx, [esp + 0x18]
// 004f8a22  e8a9bbffff           call 0x4f45d0
// 004f8a27  8bf0                 mov esi, eax
// 004f8a29  8b06                 mov eax, dword ptr [esi]
// 004f8a2b  83c748               add edi, 0x48
// 004f8a2e  50                   push eax
// 004f8a2f  8bcf                 mov ecx, edi
// 004f8a31  c744243c01000000     mov dword ptr [esp + 0x3c], 1
// 004f8a39  e832c5f7ff           call 0x474f70
// 004f8a3e  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f8a41  894f04               mov dword ptr [edi + 4], ecx
// 004f8a44  8b5608               mov edx, dword ptr [esi + 8]
// 004f8a47  895708               mov dword ptr [edi + 8], edx
// 004f8a4a  8b460c               mov eax, dword ptr [esi + 0xc]
// 004f8a4d  89470c               mov dword ptr [edi + 0xc], eax
// 004f8a50  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004f8a53  894f10               mov dword ptr [edi + 0x10], ecx
// 004f8a56  8b5614               mov edx, dword ptr [esi + 0x14]
// 004f8a59  895714               mov dword ptr [edi + 0x14], edx
// 004f8a5c  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f8a5f  894718               mov dword ptr [edi + 0x18], eax
// 004f8a62  8b442410             mov eax, dword ptr [esp + 0x10]
// 004f8a66  85c0                 test eax, eax
// 004f8a68  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 004f8a6b  894f1c               mov dword ptr [edi + 0x1c], ecx
// 004f8a6e  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 004f8a76  7427                 je 0x4f8a9f
// 004f8a78  83c004               add eax, 4
// 004f8a7b  50                   push eax
// 004f8a7c  ff15e8d27700         call dword ptr [0x77d2e8]
// 004f8a82  85c0                 test eax, eax
// 004f8a84  7519                 jne 0x4f8a9f
// 004f8a86  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004f8a8a  e841f3f5ff           call 0x457dd0
// 004f8a8f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004f8a93  85c9                 test ecx, ecx
// 004f8a95  7408                 je 0x4f8a9f
// 004f8a97  8b11                 mov edx, dword ptr [ecx]
// 004f8a99  8b02                 mov eax, dword ptr [edx]
// 004f8a9b  6a01                 push 1
// 004f8a9d  ffd0                 call eax
// 004f8a9f  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004f8aa3  64890d00000000       mov dword ptr fs:[0], ecx
// 004f8aaa  59                   pop ecx
// 004f8aab  5f                   pop edi
// 004f8aac  5e                   pop esi
// 004f8aad  5b                   pop ebx
// 004f8aae  83c42c               add esp, 0x2c
// 004f8ab1  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 005033e0  unit: RBX::Render::RenderScene  size: 337 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005033e0
//
// 005033e0  64a100000000         mov eax, dword ptr fs:[0]
// 005033e6  6aff                 push -1
// 005033e8  68a0b47c00           push 0x7cb4a0
// 005033ed  50                   push eax
// 005033ee  64892500000000       mov dword ptr fs:[0], esp
// 005033f5  83ec20               sub esp, 0x20
// 005033f8  53                   push ebx
// 005033f9  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 005033fd  8b4304               mov eax, dword ptr [ebx + 4]
// 00503400  56                   push esi
// 00503401  57                   push edi
// 00503402  8bf9                 mov edi, ecx
// 00503404  8b8fd0020000         mov ecx, dword ptr [edi + 0x2d0]
// 0050340a  8db7d0020000         lea esi, [edi + 0x2d0]
// 00503410  8d0440               lea eax, [eax + eax*2]
// 00503413  8d048510000000       lea eax, [eax*4 + 0x10]
// 0050341a  85c9                 test ecx, ecx
// 0050341c  740c                 je 0x50342a
// 0050341e  394128               cmp dword ptr [ecx + 0x28], eax
// 00503421  7207                 jb 0x50342a
// 00503423  e8982af7ff           call 0x475ec0
// 00503428  eb59                 jmp 0x503483
// 0050342a  6a02                 push 2
// 0050342c  50                   push eax
// 0050342d  8d442444             lea eax, [esp + 0x44]
// 00503431  50                   push eax
// 00503432  e8992ff7ff           call 0x4763d0
// 00503437  83c40c               add esp, 0xc
// 0050343a  8b08                 mov ecx, dword ptr [eax]
// 0050343c  51                   push ecx
// 0050343d  8bce                 mov ecx, esi
// 0050343f  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00503447  e8545b0900           call 0x598fa0
// 0050344c  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00503450  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 00503458  85c0                 test eax, eax
// 0050345a  7427                 je 0x503483
// 0050345c  83c004               add eax, 4
// 0050345f  50                   push eax
// 00503460  ff15ac218000         call dword ptr [0x8021ac]
// 00503466  85c0                 test eax, eax
// 00503468  7519                 jne 0x503483
// 0050346a  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0050346e  e81d79f5ff           call 0x45ad90
// 00503473  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00503477  85c9                 test ecx, ecx
// 00503479  7408                 je 0x503483
// 0050347b  8b11                 mov edx, dword ptr [ecx]
// 0050347d  8b02                 mov eax, dword ptr [edx]
// 0050347f  6a01                 push 1
// 00503481  ffd0                 call eax
// 00503483  51                   push ecx
// 00503484  8bcc                 mov ecx, esp
// 00503486  c70100000000         mov dword ptr [ecx], 0
// 0050348c  8b16                 mov edx, dword ptr [esi]
// 0050348e  89642440             mov dword ptr [esp + 0x40], esp
// 00503492  52                   push edx
// 00503493  e8085b0900           call 0x598fa0
// 00503498  53                   push ebx
// 00503499  8d4c2414             lea ecx, [esp + 0x14]
// 0050349d  e86ef4ffff           call 0x502910
// 005034a2  8bf0                 mov esi, eax
// 005034a4  8b06                 mov eax, dword ptr [esi]
// 005034a6  81c7b0020000         add edi, 0x2b0
// 005034ac  50                   push eax
// 005034ad  8bcf                 mov ecx, edi
// 005034af  c744243801000000     mov dword ptr [esp + 0x38], 1
// 005034b7  e8e45a0900           call 0x598fa0
// 005034bc  8b4e04               mov ecx, dword ptr [esi + 4]
// 005034bf  894f04               mov dword ptr [edi + 4], ecx
// 005034c2  8b5608               mov edx, dword ptr [esi + 8]
// 005034c5  895708               mov dword ptr [edi + 8], edx
// 005034c8  8b460c               mov eax, dword ptr [esi + 0xc]
// 005034cb  89470c               mov dword ptr [edi + 0xc], eax
// 005034ce  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005034d1  894f10               mov dword ptr [edi + 0x10], ecx
// 005034d4  8b5614               mov edx, dword ptr [esi + 0x14]
// 005034d7  895714               mov dword ptr [edi + 0x14], edx
// 005034da  8b4618               mov eax, dword ptr [esi + 0x18]
// 005034dd  894718               mov dword ptr [edi + 0x18], eax
// 005034e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005034e4  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 005034e7  894f1c               mov dword ptr [edi + 0x1c], ecx
// 005034ea  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 005034f2  85c0                 test eax, eax
// 005034f4  7427                 je 0x50351d
// 005034f6  83c004               add eax, 4
// 005034f9  50                   push eax
// 005034fa  ff15ac218000         call dword ptr [0x8021ac]
// 00503500  85c0                 test eax, eax
// 00503502  7519                 jne 0x50351d
// 00503504  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00503508  e88378f5ff           call 0x45ad90
// 0050350d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00503511  85c9                 test ecx, ecx
// 00503513  7408                 je 0x50351d
// 00503515  8b11                 mov edx, dword ptr [ecx]
// 00503517  8b02                 mov eax, dword ptr [edx]
// 00503519  6a01                 push 1
// 0050351b  ffd0                 call eax
// 0050351d  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00503521  5f                   pop edi
// 00503522  5e                   pop esi
// 00503523  64890d00000000       mov dword ptr fs:[0], ecx
// 0050352a  5b                   pop ebx
// 0050352b  83c42c               add esp, 0x2c
// 0050352e  c20400               ret 4

extern "C" long (__stdcall *InterlockedDecrement)(volatile long *);

struct Object {
    virtual ~Object();
    volatile long references;
    unsigned char padding[32];
    unsigned capacity;

    void release();
    void reset();
};

struct Ref {
    Object *p;

    Ref() : p(0) {}
    Ref(const Ref& other) : p(0) { assign(other.p); }

    Ref& assign(Object *);
    Ref& operator=(const Ref& other) { return assign(other.p); }

    ~Ref() {
        if (p && InterlockedDecrement(&p->references) == 0) {
            p->release();
            if (p)
                delete p;
        }
    }
};

Ref __cdecl createArea(unsigned size, int kind);

struct Input {
    unsigned reserved;
    unsigned count;
};

struct Vertex {
    Ref area;
    unsigned a, b, c, d, e, f, g;

    Vertex(Input *, Ref);
};

struct S {
    unsigned char padding[0x48];
    Vertex vertex;
    Ref area;

    void update(Input *);
};

void S::update(Input *input)
{
    unsigned size = input->count * 12 + 16;
    if (area.p && area.p->capacity >= size)
        area.p->reset();
    else
        area = createArea(size, 2);

    vertex = Vertex(input, area);
}
