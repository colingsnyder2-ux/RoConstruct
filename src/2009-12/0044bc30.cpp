// from server: 100% by nuck16
// roc 2009-12 0044bc30  unit: CRobloxApp  size: 99 bytes
//
// 0044bc30  64a100000000         mov eax, dword ptr fs:[0]
// 0044bc36  6aff                 push -1
// 0044bc38  68aead9200           push 0x92adae
// 0044bc3d  50                   push eax
// 0044bc3e  b801000000           mov eax, 1
// 0044bc43  64892500000000       mov dword ptr fs:[0], esp
// 0044bc4a  84055cb4b700         test byte ptr [0xb7b45c], al
// 0044bc50  752e                 jne 0x44bc80
// 0044bc52  09055cb4b700         or dword ptr [0xb7b45c], eax
// 0044bc58  68e86e9d00           push 0x9d6ee8
// 0044bc5d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0044bc65  e876661e00           call 0x6322e0
// 0044bc6a  83c404               add esp, 4
// 0044bc6d  a358b4b700           mov dword ptr [0xb7b458], eax
// 0044bc72  8b0c24               mov ecx, dword ptr [esp]
// 0044bc75  64890d00000000       mov dword ptr fs:[0], ecx
// 0044bc7c  83c40c               add esp, 0xc
// 0044bc7f  c3                   ret 
// 0044bc80  8b0c24               mov ecx, dword ptr [esp]
// 0044bc83  a158b4b700           mov eax, dword ptr [0xb7b458]
// 0044bc88  64890d00000000       mov dword ptr fs:[0], ecx
// 0044bc8f  83c40c               add esp, 0xc
// 0044bc92  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("PhysicsSettings");
    return *name;
}
