// from server: 100% by nuck16
// roc 2009-12 007d7e10  unit: RBX::HUMAN::Seated  size: 99 bytes
//
// 007d7e10  64a100000000         mov eax, dword ptr fs:[0]
// 007d7e16  6aff                 push -1
// 007d7e18  68fe709500           push 0x9570fe
// 007d7e1d  50                   push eax
// 007d7e1e  b801000000           mov eax, 1
// 007d7e23  64892500000000       mov dword ptr fs:[0], esp
// 007d7e2a  8405e88eb900         test byte ptr [0xb98ee8], al
// 007d7e30  752e                 jne 0x7d7e60
// 007d7e32  0905e88eb900         or dword ptr [0xb98ee8], eax
// 007d7e38  6808f79e00           push 0x9ef708
// 007d7e3d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007d7e45  e896a4e5ff           call 0x6322e0
// 007d7e4a  83c404               add esp, 4
// 007d7e4d  a3e48eb900           mov dword ptr [0xb98ee4], eax
// 007d7e52  8b0c24               mov ecx, dword ptr [esp]
// 007d7e55  64890d00000000       mov dword ptr fs:[0], ecx
// 007d7e5c  83c40c               add esp, 0xc
// 007d7e5f  c3                   ret 
// 007d7e60  8b0c24               mov ecx, dword ptr [esp]
// 007d7e63  a1e48eb900           mov eax, dword ptr [0xb98ee4]
// 007d7e68  64890d00000000       mov dword ptr fs:[0], ecx
// 007d7e6f  83c40c               add esp, 0xc
// 007d7e72  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("StrafingNoPhysics");
    return *name;
}
