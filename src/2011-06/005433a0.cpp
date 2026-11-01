// from server: 100% by auto
// roc 2011-06 005433a0  unit: G3D::Sphere  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005433a0
//
// 005433a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005433a4  83ec0c               sub esp, 0xc
// 005433a7  85c9                 test ecx, ecx
// 005433a9  7712                 ja 0x5433bd
// 005433ab  33c9                 xor ecx, ecx
// 005433ad  8d1409               lea edx, [ecx + ecx]
// 005433b0  52                   push edx
// 005433b1  e8a86c2c00           call 0x80a05e
// 005433b6  83c404               add esp, 4
// 005433b9  83c40c               add esp, 0xc
// 005433bc  c3                   ret 
// 005433bd  83c8ff               or eax, 0xffffffff
// 005433c0  33d2                 xor edx, edx
// 005433c2  f7f1                 div ecx
// 005433c4  83f802               cmp eax, 2
// 005433c7  73e4                 jae 0x5433ad
// 005433c9  8d442410             lea eax, [esp + 0x10]
// 005433cd  50                   push eax
// 005433ce  8d4c2404             lea ecx, [esp + 4]
// 005433d2  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005433da  ff156c0aa400         call dword ptr [0xa40a6c]
// 005433e0  68c472b800           push 0xb872c4
// 005433e5  8d4c2404             lea ecx, [esp + 4]
// 005433e9  51                   push ecx
// 005433ea  c7442408b4b5a500     mov dword ptr [esp + 8], 0xa5b5b4
// 005433f2  e8b57c2c00           call 0x80b0ac
// standard library vector<short> (function ??$_Allocate@F@std@@YAPAFIPAF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
