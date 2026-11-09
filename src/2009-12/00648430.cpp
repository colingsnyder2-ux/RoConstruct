// from server: 100% by nuck16
// roc 2009-12 00648430  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648430  64a100000000         mov eax, dword ptr fs:[0]
// 00648436  6aff                 push -1
// 00648438  687e179400           push 0x94177e
// 0064843d  50                   push eax
// 0064843e  b801000000           mov eax, 1
// 00648443  64892500000000       mov dword ptr fs:[0], esp
// 0064844a  8405505eb800         test byte ptr [0xb85e50], al
// 00648450  752e                 jne 0x648480
// 00648452  0905505eb800         or dword ptr [0xb85e50], eax
// 00648458  68e8299e00           push 0x9e29e8
// 0064845d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648465  e8769efeff           call 0x6322e0
// 0064846a  83c404               add esp, 4
// 0064846d  a34c5eb800           mov dword ptr [0xb85e4c], eax
// 00648472  8b0c24               mov ecx, dword ptr [esp]
// 00648475  64890d00000000       mov dword ptr fs:[0], ecx
// 0064847c  83c40c               add esp, 0xc
// 0064847f  c3                   ret 
// 00648480  8b0c24               mov ecx, dword ptr [esp]
// 00648483  a14c5eb800           mov eax, dword ptr [0xb85e4c]
// 00648488  64890d00000000       mov dword ptr fs:[0], ecx
// 0064848f  83c40c               add esp, 0xc
// 00648492  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Hole");
    return *name;
}
