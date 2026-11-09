// from server: 100% by nuck16
// roc 2009-12 007d8b30  unit: RBX::HUMAN::Jumping  size: 99 bytes
//
// 007d8b30  64a100000000         mov eax, dword ptr fs:[0]
// 007d8b36  6aff                 push -1
// 007d8b38  68be719500           push 0x9571be
// 007d8b3d  50                   push eax
// 007d8b3e  b801000000           mov eax, 1
// 007d8b43  64892500000000       mov dword ptr fs:[0], esp
// 007d8b4a  8405608fb900         test byte ptr [0xb98f60], al
// 007d8b50  752e                 jne 0x7d8b80
// 007d8b52  0905608fb900         or dword ptr [0xb98f60], eax
// 007d8b58  68a0f89e00           push 0x9ef8a0
// 007d8b5d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007d8b65  e87697e5ff           call 0x6322e0
// 007d8b6a  83c404               add esp, 4
// 007d8b6d  a35c8fb900           mov dword ptr [0xb98f5c], eax
// 007d8b72  8b0c24               mov ecx, dword ptr [esp]
// 007d8b75  64890d00000000       mov dword ptr fs:[0], ecx
// 007d8b7c  83c40c               add esp, 0xc
// 007d8b7f  c3                   ret 
// 007d8b80  8b0c24               mov ecx, dword ptr [esp]
// 007d8b83  a15c8fb900           mov eax, dword ptr [0xb98f5c]
// 007d8b88  64890d00000000       mov dword ptr fs:[0], ecx
// 007d8b8f  83c40c               add esp, 0xc
// 007d8b92  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("GettingUp");
    return *name;
}
