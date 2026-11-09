// from server: 100% by nuck16
// roc 2009-12 00428b50  unit: CMainFrame  size: 99 bytes
//
// 00428b50  64a100000000         mov eax, dword ptr fs:[0]
// 00428b56  6aff                 push -1
// 00428b58  683e959200           push 0x92953e
// 00428b5d  50                   push eax
// 00428b5e  b801000000           mov eax, 1
// 00428b63  64892500000000       mov dword ptr fs:[0], esp
// 00428b6a  8405e4a2b700         test byte ptr [0xb7a2e4], al
// 00428b70  752e                 jne 0x428ba0
// 00428b72  0905e4a2b700         or dword ptr [0xb7a2e4], eax
// 00428b78  68f0309d00           push 0x9d30f0
// 00428b7d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00428b85  e856972000           call 0x6322e0
// 00428b8a  83c404               add esp, 4
// 00428b8d  a3e0a2b700           mov dword ptr [0xb7a2e0], eax
// 00428b92  8b0c24               mov ecx, dword ptr [esp]
// 00428b95  64890d00000000       mov dword ptr fs:[0], ecx
// 00428b9c  83c40c               add esp, 0xc
// 00428b9f  c3                   ret 
// 00428ba0  8b0c24               mov ecx, dword ptr [esp]
// 00428ba3  a1e0a2b700           mov eax, dword ptr [0xb7a2e0]
// 00428ba8  64890d00000000       mov dword ptr fs:[0], ecx
// 00428baf  83c40c               add esp, 0xc
// 00428bb2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Hat");
    return *name;
}
