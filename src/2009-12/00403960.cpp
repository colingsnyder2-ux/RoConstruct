// from server: 100% by nuck16
// roc 2009-12 00403960  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 99 bytes
//
// 00403960  64a100000000         mov eax, dword ptr fs:[0]
// 00403966  6aff                 push -1
// 00403968  686e709200           push 0x92706e
// 0040396d  50                   push eax
// 0040396e  b801000000           mov eax, 1
// 00403973  64892500000000       mov dword ptr fs:[0], esp
// 0040397a  84057895b700         test byte ptr [0xb79578], al
// 00403980  752e                 jne 0x4039b0
// 00403982  09057895b700         or dword ptr [0xb79578], eax
// 00403988  68d8c39c00           push 0x9cc3d8
// 0040398d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00403995  e846e92200           call 0x6322e0
// 0040399a  83c404               add esp, 4
// 0040399d  a37495b700           mov dword ptr [0xb79574], eax
// 004039a2  8b0c24               mov ecx, dword ptr [esp]
// 004039a5  64890d00000000       mov dword ptr fs:[0], ecx
// 004039ac  83c40c               add esp, 0xc
// 004039af  c3                   ret 
// 004039b0  8b0c24               mov ecx, dword ptr [esp]
// 004039b3  a17495b700           mov eax, dword ptr [0xb79574]
// 004039b8  64890d00000000       mov dword ptr fs:[0], ecx
// 004039bf  83c40c               add esp, 0xc
// 004039c2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Team");
    return *name;
}
