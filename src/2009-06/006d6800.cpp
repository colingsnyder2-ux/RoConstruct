// from server: 100% by auto
// roc 2009-06 006d6800  unit: RBX::Mechanism  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d6800
//
// 006d6800  83ec10               sub esp, 0x10
// 006d6803  53                   push ebx
// 006d6804  55                   push ebp
// 006d6805  56                   push esi
// 006d6806  8bf1                 mov esi, ecx
// 006d6808  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 006d680b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 006d680e  8bcb                 mov ecx, ebx
// 006d6810  2bcd                 sub ecx, ebp
// 006d6812  b893244992           mov eax, 0x92492493
// 006d6817  f7e9                 imul ecx
// 006d6819  03d1                 add edx, ecx
// 006d681b  c1fa04               sar edx, 4
// 006d681e  8bc2                 mov eax, edx
// 006d6820  c1e81f               shr eax, 0x1f
// 006d6823  57                   push edi
// 006d6824  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006d6828  03c2                 add eax, edx
// 006d682a  3bf8                 cmp edi, eax
// 006d682c  7640                 jbe 0x6d686e
// 006d682e  3beb                 cmp ebp, ebx
// 006d6830  7606                 jbe 0x6d6838
// 006d6832  ff15ace98900         call dword ptr [0x89e9ac]
// 006d6838  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006d683b  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 006d683e  8b2e                 mov ebp, dword ptr [esi]
// 006d6840  8d442428             lea eax, [esp + 0x28]
// 006d6844  50                   push eax
// 006d6845  b893244992           mov eax, 0x92492493
// 006d684a  f7e9                 imul ecx
// 006d684c  03d1                 add edx, ecx
// 006d684e  c1fa04               sar edx, 4
// 006d6851  8bca                 mov ecx, edx
// 006d6853  c1e91f               shr ecx, 0x1f
// 006d6856  03ca                 add ecx, edx
// 006d6858  2bf9                 sub edi, ecx
// 006d685a  57                   push edi
// 006d685b  53                   push ebx
// 006d685c  55                   push ebp
// 006d685d  8bce                 mov ecx, esi
// 006d685f  e8acfcffff           call 0x6d6510
// 006d6864  5f                   pop edi
// 006d6865  5e                   pop esi
// 006d6866  5d                   pop ebp
// 006d6867  5b                   pop ebx
// 006d6868  83c410               add esp, 0x10
// 006d686b  c22000               ret 0x20
// 006d686e  734e                 jae 0x6d68be
// 006d6870  3beb                 cmp ebp, ebx
// 006d6872  7606                 jbe 0x6d687a
// 006d6874  ff15ace98900         call dword ptr [0x89e9ac]
// 006d687a  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 006d687d  8b16                 mov edx, dword ptr [esi]
// 006d687f  89542418             mov dword ptr [esp + 0x18], edx
// 006d6883  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 006d6886  7606                 jbe 0x6d688e
// 006d6888  ff15ace98900         call dword ptr [0x89e9ac]
// 006d688e  8b06                 mov eax, dword ptr [esi]
// 006d6890  57                   push edi
// 006d6891  8d4c2414             lea ecx, [esp + 0x14]
// 006d6895  89442414             mov dword ptr [esp + 0x14], eax
// 006d6899  896c2418             mov dword ptr [esp + 0x18], ebp
// 006d689d  e83ef4ffff           call 0x6d5ce0
// 006d68a2  8b442418             mov eax, dword ptr [esp + 0x18]
// 006d68a6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006d68aa  8b542410             mov edx, dword ptr [esp + 0x10]
// 006d68ae  53                   push ebx
// 006d68af  50                   push eax
// 006d68b0  51                   push ecx
// 006d68b1  52                   push edx
// 006d68b2  8d442428             lea eax, [esp + 0x28]
// 006d68b6  50                   push eax
// 006d68b7  8bce                 mov ecx, esi
// 006d68b9  e892fbffff           call 0x6d6450
// 006d68be  5f                   pop edi
// 006d68bf  5e                   pop esi
// 006d68c0  5d                   pop ebp
// 006d68c1  5b                   pop ebx
// 006d68c2  83c410               add esp, 0x10
// 006d68c5  c22000               ret 0x20
// standard library vector<pod28> (function ?resize@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIUE@@@Z)

// stl: vector<pod28>
struct E { int v[7]; };
#include <vector>
template class std::vector<E>;
