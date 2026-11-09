// from server: 100% by auto
// roc 2008-06 0069b070  unit: Ogre::InstancedGeometry  size: 196 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0069b070
//
// 0069b070  83ec18               sub esp, 0x18
// 0069b073  53                   push ebx
// 0069b074  55                   push ebp
// 0069b075  56                   push esi
// 0069b076  8bf1                 mov esi, ecx
// 0069b078  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0069b07b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0069b07e  8bcb                 mov ecx, ebx
// 0069b080  2bcd                 sub ecx, ebp
// 0069b082  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0069b087  f7e9                 imul ecx
// 0069b089  d1fa                 sar edx, 1
// 0069b08b  8bc2                 mov eax, edx
// 0069b08d  c1e81f               shr eax, 0x1f
// 0069b090  57                   push edi
// 0069b091  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0069b095  03c2                 add eax, edx
// 0069b097  3bf8                 cmp edi, eax
// 0069b099  763d                 jbe 0x69b0d8
// 0069b09b  3beb                 cmp ebp, ebx
// 0069b09d  7606                 jbe 0x69b0a5
// 0069b09f  ff1590288000         call dword ptr [0x802890]
// 0069b0a5  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0069b0a8  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 0069b0ab  8b2e                 mov ebp, dword ptr [esi]
// 0069b0ad  8d442430             lea eax, [esp + 0x30]
// 0069b0b1  50                   push eax
// 0069b0b2  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0069b0b7  f7e9                 imul ecx
// 0069b0b9  d1fa                 sar edx, 1
// 0069b0bb  8bca                 mov ecx, edx
// 0069b0bd  c1e91f               shr ecx, 0x1f
// 0069b0c0  03ca                 add ecx, edx
// 0069b0c2  2bf9                 sub edi, ecx
// 0069b0c4  57                   push edi
// 0069b0c5  53                   push ebx
// 0069b0c6  55                   push ebp
// 0069b0c7  8bce                 mov ecx, esi
// 0069b0c9  e892ebffff           call 0x699c60
// 0069b0ce  5f                   pop edi
// 0069b0cf  5e                   pop esi
// 0069b0d0  5d                   pop ebp
// 0069b0d1  5b                   pop ebx
// 0069b0d2  83c418               add esp, 0x18
// 0069b0d5  c21000               ret 0x10
// 0069b0d8  7350                 jae 0x69b12a
// 0069b0da  3beb                 cmp ebp, ebx
// 0069b0dc  7606                 jbe 0x69b0e4
// 0069b0de  ff1590288000         call dword ptr [0x802890]
// 0069b0e4  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0069b0e7  8b16                 mov edx, dword ptr [esi]
// 0069b0e9  89542418             mov dword ptr [esp + 0x18], edx
// 0069b0ed  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0069b0f0  7606                 jbe 0x69b0f8
// 0069b0f2  ff1590288000         call dword ptr [0x802890]
// 0069b0f8  8b06                 mov eax, dword ptr [esi]
// 0069b0fa  57                   push edi
// 0069b0fb  8d4c2424             lea ecx, [esp + 0x24]
// 0069b0ff  51                   push ecx
// 0069b100  8d4c2418             lea ecx, [esp + 0x18]
// 0069b104  89442418             mov dword ptr [esp + 0x18], eax
// 0069b108  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0069b10c  e8bf4fffff           call 0x6900d0
// 0069b111  8b542418             mov edx, dword ptr [esp + 0x18]
// 0069b115  8b4804               mov ecx, dword ptr [eax + 4]
// 0069b118  53                   push ebx
// 0069b119  52                   push edx
// 0069b11a  8b10                 mov edx, dword ptr [eax]
// 0069b11c  51                   push ecx
// 0069b11d  52                   push edx
// 0069b11e  8d442428             lea eax, [esp + 0x28]
// 0069b122  50                   push eax
// 0069b123  8bce                 mov ecx, esi
// 0069b125  e8e6caffff           call 0x697c10
// 0069b12a  5f                   pop edi
// 0069b12b  5e                   pop esi
// 0069b12c  5d                   pop ebp
// 0069b12d  5b                   pop ebx
// 0069b12e  83c418               add esp, 0x18
// 0069b131  c21000               ret 0x10
// standard library vector<pod12> (function ?resize@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
