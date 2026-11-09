// from server: 100% by nuck16
// roc 2009-12 0068e4e0  unit: RBX::VStarterPackService::?$FactoryProduct  size: 99 bytes
//
// 0068e4e0  64a100000000         mov eax, dword ptr fs:[0]
// 0068e4e6  6aff                 push -1
// 0068e4e8  684e669400           push 0x94664e
// 0068e4ed  50                   push eax
// 0068e4ee  b801000000           mov eax, 1
// 0068e4f3  64892500000000       mov dword ptr fs:[0], esp
// 0068e4fa  8405cc10b900         test byte ptr [0xb910cc], al
// 0068e500  752e                 jne 0x68e530
// 0068e502  0905cc10b900         or dword ptr [0xb910cc], eax
// 0068e508  68f0109d00           push 0x9d10f0
// 0068e50d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0068e515  e8c63dfaff           call 0x6322e0
// 0068e51a  83c404               add esp, 4
// 0068e51d  a3c810b900           mov dword ptr [0xb910c8], eax
// 0068e522  8b0c24               mov ecx, dword ptr [esp]
// 0068e525  64890d00000000       mov dword ptr fs:[0], ecx
// 0068e52c  83c40c               add esp, 0xc
// 0068e52f  c3                   ret 
// 0068e530  8b0c24               mov ecx, dword ptr [esp]
// 0068e533  a1c810b900           mov eax, dword ptr [0xb910c8]
// 0068e538  64890d00000000       mov dword ptr fs:[0], ecx
// 0068e53f  83c40c               add esp, 0xc
// 0068e542  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("BackpackItem");
    return *name;
}
