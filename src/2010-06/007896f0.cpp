// from server: 100% by auto
// roc 2010-06 007896f0  unit: RBX::HUMAN::GettingUp  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007896f0
//
// 007896f0  83ec08               sub esp, 8
// 007896f3  53                   push ebx
// 007896f4  55                   push ebp
// 007896f5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 007896fb  56                   push esi
// 007896fc  8bf1                 mov esi, ecx
// 007896fe  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00789701  57                   push edi
// 00789702  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00789705  8bcb                 mov ecx, ebx
// 00789707  2bcf                 sub ecx, edi
// 00789709  b867666666           mov eax, 0x66666667
// 0078970e  f7e9                 imul ecx
// 00789710  c1fa04               sar edx, 4
// 00789713  8bc2                 mov eax, edx
// 00789715  c1e81f               shr eax, 0x1f
// 00789718  03c2                 add eax, edx
// 0078971a  7504                 jne 0x789720
// 0078971c  33ff                 xor edi, edi
// 0078971e  eb2d                 jmp 0x78974d
// 00789720  3bfb                 cmp edi, ebx
// 00789722  7602                 jbe 0x789726
// 00789724  ffd5                 call ebp
// 00789726  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0078972a  8b06                 mov eax, dword ptr [esi]
// 0078972c  85c9                 test ecx, ecx
// 0078972e  7404                 je 0x789734
// 00789730  3bc8                 cmp ecx, eax
// 00789732  7402                 je 0x789736
// 00789734  ffd5                 call ebp
// 00789736  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0078973a  2bcf                 sub ecx, edi
// 0078973c  b867666666           mov eax, 0x66666667
// 00789741  f7e9                 imul ecx
// 00789743  c1fa04               sar edx, 4
// 00789746  8bfa                 mov edi, edx
// 00789748  c1ef1f               shr edi, 0x1f
// 0078974b  03fa                 add edi, edx
// 0078974d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00789751  8b542424             mov edx, dword ptr [esp + 0x24]
// 00789755  8b442420             mov eax, dword ptr [esp + 0x20]
// 00789759  51                   push ecx
// 0078975a  6a01                 push 1
// 0078975c  52                   push edx
// 0078975d  50                   push eax
// 0078975e  8bce                 mov ecx, esi
// 00789760  e82bf8ffff           call 0x788f90
// 00789765  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00789768  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0078976b  7602                 jbe 0x78976f
// 0078976d  ffd5                 call ebp
// 0078976f  8b36                 mov esi, dword ptr [esi]
// 00789771  57                   push edi
// 00789772  8d4c2414             lea ecx, [esp + 0x14]
// 00789776  89742414             mov dword ptr [esp + 0x14], esi
// 0078977a  895c2418             mov dword ptr [esp + 0x18], ebx
// 0078977e  e8dd0af2ff           call 0x6aa260
// 00789783  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00789787  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0078978b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0078978f  5f                   pop edi
// 00789790  5e                   pop esi
// 00789791  5d                   pop ebp
// 00789792  8908                 mov dword ptr [eax], ecx
// 00789794  895004               mov dword ptr [eax + 4], edx
// 00789797  5b                   pop ebx
// 00789798  83c408               add esp, 8
// 0078979b  c21000               ret 0x10
// standard library vector<pod40> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
