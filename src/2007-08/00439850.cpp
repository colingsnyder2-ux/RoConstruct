// from server: 100% by Yeetserama
// roc 2007-08 00439850  unit: RBX::VSoundId::?$XItem  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00439850
//
// 00439850  6aff                 push -1
// 00439852  6858cf7300           push 0x73cf58
// 00439857  64a100000000         mov eax, dword ptr fs:[0]
// 0043985d  50                   push eax
// 0043985e  51                   push ecx
// 0043985f  56                   push esi
// 00439860  a188518b00           mov eax, dword ptr [0x8b5188]
// 00439865  33c4                 xor eax, esp
// 00439867  50                   push eax
// 00439868  8d44240c             lea eax, [esp + 0xc]
// 0043986c  64a300000000         mov dword ptr fs:[0], eax
// 00439872  8bf1                 mov esi, ecx
// 00439874  89742408             mov dword ptr [esp + 8], esi
// 00439878  33c0                 xor eax, eax
// 0043987a  8906                 mov dword ptr [esi], eax
// 0043987c  894604               mov dword ptr [esi + 4], eax
// 0043987f  89442414             mov dword ptr [esp + 0x14], eax
// 00439883  894608               mov dword ptr [esi + 8], eax
// 00439886  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043988a  50                   push eax
// 0043988b  e840fa1100           call 0x5592d0
// 00439890  8bc6                 mov eax, esi
// 00439892  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00439896  64890d00000000       mov dword ptr fs:[0], ecx
// 0043989d  59                   pop ecx
// 0043989e  5e                   pop esi
// 0043989f  83c410               add esp, 0x10
// 004398a2  c20400               ret 4
// copied from an identical function in another client (function ??0S@ns_ROCX000004@@QAE@I@Z)

namespace ns_ROCX000004 {
// from server: 100% by king_originala
struct First
{
    void* first;

    First() : first(0) {}
};

struct Storage
{
    void* last;

    Storage() : last(0) {}
    ~Storage();
};

struct S : First, Storage
{
    void* limit;

    explicit S(unsigned int count);
    void initialize(unsigned int count);
};

S::S(unsigned int count) : First(), Storage(), limit(0)
{
    initialize(count);
}
}
