// from server: 100% by auto
// roc 2009-12 007b3b30  unit: RBX::Assembly  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b3b30
//
// 007b3b30  83ec10               sub esp, 0x10
// 007b3b33  53                   push ebx
// 007b3b34  55                   push ebp
// 007b3b35  56                   push esi
// 007b3b36  8bf1                 mov esi, ecx
// 007b3b38  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 007b3b3b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 007b3b3e  8bcb                 mov ecx, ebx
// 007b3b40  2bcd                 sub ecx, ebp
// 007b3b42  b893244992           mov eax, 0x92492493
// 007b3b47  f7e9                 imul ecx
// 007b3b49  03d1                 add edx, ecx
// 007b3b4b  c1fa04               sar edx, 4
// 007b3b4e  8bc2                 mov eax, edx
// 007b3b50  c1e81f               shr eax, 0x1f
// 007b3b53  57                   push edi
// 007b3b54  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 007b3b58  03c2                 add eax, edx
// 007b3b5a  3bf8                 cmp edi, eax
// 007b3b5c  7640                 jbe 0x7b3b9e
// 007b3b5e  3beb                 cmp ebp, ebx
// 007b3b60  7606                 jbe 0x7b3b68
// 007b3b62  ff1560b79800         call dword ptr [0x98b760]
// 007b3b68  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007b3b6b  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 007b3b6e  8b2e                 mov ebp, dword ptr [esi]
// 007b3b70  8d442428             lea eax, [esp + 0x28]
// 007b3b74  50                   push eax
// 007b3b75  b893244992           mov eax, 0x92492493
// 007b3b7a  f7e9                 imul ecx
// 007b3b7c  03d1                 add edx, ecx
// 007b3b7e  c1fa04               sar edx, 4
// 007b3b81  8bca                 mov ecx, edx
// 007b3b83  c1e91f               shr ecx, 0x1f
// 007b3b86  03ca                 add ecx, edx
// 007b3b88  2bf9                 sub edi, ecx
// 007b3b8a  57                   push edi
// 007b3b8b  53                   push ebx
// 007b3b8c  55                   push ebp
// 007b3b8d  8bce                 mov ecx, esi
// 007b3b8f  e8acfcffff           call 0x7b3840
// 007b3b94  5f                   pop edi
// 007b3b95  5e                   pop esi
// 007b3b96  5d                   pop ebp
// 007b3b97  5b                   pop ebx
// 007b3b98  83c410               add esp, 0x10
// 007b3b9b  c22000               ret 0x20
// 007b3b9e  734e                 jae 0x7b3bee
// 007b3ba0  3beb                 cmp ebp, ebx
// 007b3ba2  7606                 jbe 0x7b3baa
// 007b3ba4  ff1560b79800         call dword ptr [0x98b760]
// 007b3baa  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 007b3bad  8b16                 mov edx, dword ptr [esi]
// 007b3baf  89542418             mov dword ptr [esp + 0x18], edx
// 007b3bb3  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 007b3bb6  7606                 jbe 0x7b3bbe
// 007b3bb8  ff1560b79800         call dword ptr [0x98b760]
// 007b3bbe  8b06                 mov eax, dword ptr [esi]
// 007b3bc0  57                   push edi
// 007b3bc1  8d4c2414             lea ecx, [esp + 0x14]
// 007b3bc5  89442414             mov dword ptr [esp + 0x14], eax
// 007b3bc9  896c2418             mov dword ptr [esp + 0x18], ebp
// 007b3bcd  e8eefec6ff           call 0x423ac0
// 007b3bd2  8b442418             mov eax, dword ptr [esp + 0x18]
// 007b3bd6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007b3bda  8b542410             mov edx, dword ptr [esp + 0x10]
// 007b3bde  53                   push ebx
// 007b3bdf  50                   push eax
// 007b3be0  51                   push ecx
// 007b3be1  52                   push edx
// 007b3be2  8d442428             lea eax, [esp + 0x28]
// 007b3be6  50                   push eax
// 007b3be7  8bce                 mov ecx, esi
// 007b3be9  e892fbffff           call 0x7b3780
// 007b3bee  5f                   pop edi
// 007b3bef  5e                   pop esi
// 007b3bf0  5d                   pop ebp
// 007b3bf1  5b                   pop ebx
// 007b3bf2  83c410               add esp, 0x10
// 007b3bf5  c22000               ret 0x20
// standard library vector<pod28> (function ?resize@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIUE@@@Z)

// stl: vector<pod28>
struct E { int v[7]; };
#include <vector>
template class std::vector<E>;
