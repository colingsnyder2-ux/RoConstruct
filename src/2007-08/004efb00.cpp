// from server: 100% by EspClaude
// from server: 50% by colin
// roc 2007-08 004efb00  unit: RBX::Render::VChunk::?$WeakReferenceCountedPointer  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004efb00
//
// 004efb00  6aff                 push -1
// 004efb02  6878d37400           push 0x74d378
// 004efb07  64a100000000         mov eax, dword ptr fs:[0]
// 004efb0d  50                   push eax
// 004efb0e  51                   push ecx
// 004efb0f  56                   push esi
// 004efb10  57                   push edi
// 004efb11  a188518b00           mov eax, dword ptr [0x8b5188]
// 004efb16  33c4                 xor eax, esp
// 004efb18  50                   push eax
// 004efb19  8d442410             lea eax, [esp + 0x10]
// 004efb1d  64a300000000         mov dword ptr fs:[0], eax
// 004efb23  8bf1                 mov esi, ecx
// 004efb25  8974240c             mov dword ptr [esp + 0xc], esi
// 004efb29  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004efb2d  8a07                 mov al, byte ptr [edi]
// 004efb2f  8806                 mov byte ptr [esi], al
// 004efb31  8a4f01               mov cl, byte ptr [edi + 1]
// 004efb34  884e01               mov byte ptr [esi + 1], cl
// 004efb37  d94704               fld dword ptr [edi + 4]
// 004efb3a  d95e04               fstp dword ptr [esi + 4]
// 004efb3d  8d4e08               lea ecx, [esi + 8]
// 004efb40  c70100000000         mov dword ptr [ecx], 0
// 004efb46  8b5708               mov edx, dword ptr [edi + 8]
// 004efb49  52                   push edx
// 004efb4a  e82154f8ff           call 0x474f70
// 004efb4f  8d4e0c               lea ecx, [esi + 0xc]
// 004efb52  c70100000000         mov dword ptr [ecx], 0
// 004efb58  8b470c               mov eax, dword ptr [edi + 0xc]
// 004efb5b  50                   push eax
// 004efb5c  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004efb64  e80754f8ff           call 0x474f70
// 004efb69  8bc6                 mov eax, esi
// 004efb6b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004efb6f  64890d00000000       mov dword ptr fs:[0], ecx
// 004efb76  59                   pop ecx
// 004efb77  5f                   pop edi
// 004efb78  5e                   pop esi
// 004efb79  83c410               add esp, 0x10
// 004efb7c  c20400               ret 4

struct Ptr {
    void* p;
    Ptr(const Ptr& o) : p(0) { assign(o.p); }
    ~Ptr();
    void assign(void* np);
};

struct Holder {
    bool b0;
    bool b1;
    float f4;
    Ptr p8;
    Ptr pC;
    Holder(const Holder& o);
};

Holder::Holder(const Holder& o)
    : b0(o.b0), b1(o.b1), f4(o.f4), p8(o.p8), pC(o.pC) {}
