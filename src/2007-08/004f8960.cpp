// from server: 78% by EspClaude
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
    unsigned char padding[0x2b0];
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
