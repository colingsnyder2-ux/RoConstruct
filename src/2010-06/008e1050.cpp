// from server: 100% by auto
// roc 2010-06 008e1050  unit: Ogre::RbxMaterialAdapter  size: 196 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e1050
//
// 008e1050  83ec18               sub esp, 0x18
// 008e1053  53                   push ebx
// 008e1054  55                   push ebp
// 008e1055  56                   push esi
// 008e1056  8bf1                 mov esi, ecx
// 008e1058  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008e105b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 008e105e  8bcb                 mov ecx, ebx
// 008e1060  2bcd                 sub ecx, ebp
// 008e1062  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008e1067  f7e9                 imul ecx
// 008e1069  d1fa                 sar edx, 1
// 008e106b  8bc2                 mov eax, edx
// 008e106d  c1e81f               shr eax, 0x1f
// 008e1070  57                   push edi
// 008e1071  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 008e1075  03c2                 add eax, edx
// 008e1077  3bf8                 cmp edi, eax
// 008e1079  763d                 jbe 0x8e10b8
// 008e107b  3beb                 cmp ebp, ebx
// 008e107d  7606                 jbe 0x8e1085
// 008e107f  ff150ca99e00         call dword ptr [0x9ea90c]
// 008e1085  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008e1088  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 008e108b  8b2e                 mov ebp, dword ptr [esi]
// 008e108d  8d442430             lea eax, [esp + 0x30]
// 008e1091  50                   push eax
// 008e1092  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008e1097  f7e9                 imul ecx
// 008e1099  d1fa                 sar edx, 1
// 008e109b  8bca                 mov ecx, edx
// 008e109d  c1e91f               shr ecx, 0x1f
// 008e10a0  03ca                 add ecx, edx
// 008e10a2  2bf9                 sub edi, ecx
// 008e10a4  57                   push edi
// 008e10a5  53                   push ebx
// 008e10a6  55                   push ebp
// 008e10a7  8bce                 mov ecx, esi
// 008e10a9  e832faffff           call 0x8e0ae0
// 008e10ae  5f                   pop edi
// 008e10af  5e                   pop esi
// 008e10b0  5d                   pop ebp
// 008e10b1  5b                   pop ebx
// 008e10b2  83c418               add esp, 0x18
// 008e10b5  c21000               ret 0x10
// 008e10b8  7350                 jae 0x8e110a
// 008e10ba  3beb                 cmp ebp, ebx
// 008e10bc  7606                 jbe 0x8e10c4
// 008e10be  ff150ca99e00         call dword ptr [0x9ea90c]
// 008e10c4  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 008e10c7  8b16                 mov edx, dword ptr [esi]
// 008e10c9  89542418             mov dword ptr [esp + 0x18], edx
// 008e10cd  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 008e10d0  7606                 jbe 0x8e10d8
// 008e10d2  ff150ca99e00         call dword ptr [0x9ea90c]
// 008e10d8  8b06                 mov eax, dword ptr [esi]
// 008e10da  57                   push edi
// 008e10db  8d4c2424             lea ecx, [esp + 0x24]
// 008e10df  51                   push ecx
// 008e10e0  8d4c2418             lea ecx, [esp + 0x18]
// 008e10e4  89442418             mov dword ptr [esp + 0x18], eax
// 008e10e8  896c241c             mov dword ptr [esp + 0x1c], ebp
// 008e10ec  e8efebffff           call 0x8dfce0
// 008e10f1  8b542418             mov edx, dword ptr [esp + 0x18]
// 008e10f5  8b4804               mov ecx, dword ptr [eax + 4]
// 008e10f8  53                   push ebx
// 008e10f9  52                   push edx
// 008e10fa  8b10                 mov edx, dword ptr [eax]
// 008e10fc  51                   push ecx
// 008e10fd  52                   push edx
// 008e10fe  8d442428             lea eax, [esp + 0x28]
// 008e1102  50                   push eax
// 008e1103  8bce                 mov ecx, esi
// 008e1105  e846f9ffff           call 0x8e0a50
// 008e110a  5f                   pop edi
// 008e110b  5e                   pop esi
// 008e110c  5d                   pop ebp
// 008e110d  5b                   pop ebx
// 008e110e  83c418               add esp, 0x18
// 008e1111  c21000               ret 0x10
// standard library vector<pod12> (function ?resize@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
