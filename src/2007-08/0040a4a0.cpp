// from server: 100% by Yeetserama
// roc 2007-08 0040a4a0  unit: VCApp::?$CComAggObject  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040a4a0
//
// 0040a4a0  6aff                 push -1
// 0040a4a2  680b997300           push 0x73990b
// 0040a4a7  64a100000000         mov eax, dword ptr fs:[0]
// 0040a4ad  50                   push eax
// 0040a4ae  51                   push ecx
// 0040a4af  56                   push esi
// 0040a4b0  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040a4b5  33c4                 xor eax, esp
// 0040a4b7  50                   push eax
// 0040a4b8  8d44240c             lea eax, [esp + 0xc]
// 0040a4bc  64a300000000         mov dword ptr fs:[0], eax
// 0040a4c2  8bf1                 mov esi, ecx
// 0040a4c4  89742408             mov dword ptr [esp + 8], esi
// 0040a4c8  c7069c547800         mov dword ptr [esi], 0x78549c
// 0040a4ce  c74604010000c0       mov dword ptr [esi + 4], 0xc0000001
// 0040a4d5  8b0d44ae8b00         mov ecx, dword ptr [0x8bae44]
// 0040a4db  8b01                 mov eax, dword ptr [ecx]
// 0040a4dd  8b5008               mov edx, dword ptr [eax + 8]
// 0040a4e0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0040a4e8  ffd2                 call edx
// 0040a4ea  8d4e08               lea ecx, [esi + 8]
// 0040a4ed  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0040a4f5  e896edffff           call 0x409290
// 0040a4fa  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040a4fe  64890d00000000       mov dword ptr fs:[0], ecx
// 0040a505  59                   pop ecx
// 0040a506  5e                   pop esi
// 0040a507  83c410               add esp, 0x10
// 0040a50a  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX000004@@UAE@XZ)

namespace ns_ROCX000004 {
// from server: 100% by king_originala
struct Global
{
    virtual void first();
    virtual void second();
    virtual unsigned long release();
};

extern Global* global;

struct Member
{
    ~Member();
};

struct S
{
    virtual ~S();
    unsigned long references;
    Member member;
};

S::~S()
{
    references = 0xC0000001UL;
    global->release();
}
}
