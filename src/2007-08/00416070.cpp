// from server: 100% by Yeetserama
// roc 2007-08 00416070  unit: VCLuaFunction::?$CComAggObject  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00416070
//
// 00416070  6aff                 push -1
// 00416072  688bab7300           push 0x73ab8b
// 00416077  64a100000000         mov eax, dword ptr fs:[0]
// 0041607d  50                   push eax
// 0041607e  51                   push ecx
// 0041607f  56                   push esi
// 00416080  a188518b00           mov eax, dword ptr [0x8b5188]
// 00416085  33c4                 xor eax, esp
// 00416087  50                   push eax
// 00416088  8d44240c             lea eax, [esp + 0xc]
// 0041608c  64a300000000         mov dword ptr fs:[0], eax
// 00416092  8bf1                 mov esi, ecx
// 00416094  89742408             mov dword ptr [esp + 8], esi
// 00416098  c70688737800         mov dword ptr [esi], 0x787388
// 0041609e  c74604010000c0       mov dword ptr [esi + 4], 0xc0000001
// 004160a5  8b0d44ae8b00         mov ecx, dword ptr [0x8bae44]
// 004160ab  8b01                 mov eax, dword ptr [ecx]
// 004160ad  8b5008               mov edx, dword ptr [eax + 8]
// 004160b0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004160b8  ffd2                 call edx
// 004160ba  8d4e08               lea ecx, [esi + 8]
// 004160bd  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004160c5  e8c6dcffff           call 0x413d90
// 004160ca  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004160ce  64890d00000000       mov dword ptr fs:[0], ecx
// 004160d5  59                   pop ecx
// 004160d6  5e                   pop esi
// 004160d7  83c410               add esp, 0x10
// 004160da  c3                   ret 
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
