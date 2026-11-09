// from server: 100% by auto
// roc 2007-08 004ad820  unit: RBX::Network::Replicator::DeleteInstanceItem  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ad820
//
// 004ad820  51                   push ecx
// 004ad821  53                   push ebx
// 004ad822  55                   push ebp
// 004ad823  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004ad827  56                   push esi
// 004ad828  8bf1                 mov esi, ecx
// 004ad82a  8b5e04               mov ebx, dword ptr [esi + 4]
// 004ad82d  85db                 test ebx, ebx
// 004ad82f  57                   push edi
// 004ad830  740c                 je 0x4ad83e
// 004ad832  8b4608               mov eax, dword ptr [esi + 8]
// 004ad835  8bc8                 mov ecx, eax
// 004ad837  2bcb                 sub ecx, ebx
// 004ad839  c1f904               sar ecx, 4
// 004ad83c  7504                 jne 0x4ad842
// 004ad83e  33ff                 xor edi, edi
// 004ad840  eb21                 jmp 0x4ad863
// 004ad842  3bd8                 cmp ebx, eax
// 004ad844  7606                 jbe 0x4ad84c
// 004ad846  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ad84c  85ed                 test ebp, ebp
// 004ad84e  7404                 je 0x4ad854
// 004ad850  3bee                 cmp ebp, esi
// 004ad852  7406                 je 0x4ad85a
// 004ad854  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ad85a  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ad85e  2bfb                 sub edi, ebx
// 004ad860  c1ff04               sar edi, 4
// 004ad863  8b542424             mov edx, dword ptr [esp + 0x24]
// 004ad867  8b442420             mov eax, dword ptr [esp + 0x20]
// 004ad86b  52                   push edx
// 004ad86c  6a01                 push 1
// 004ad86e  50                   push eax
// 004ad86f  55                   push ebp
// 004ad870  8bce                 mov ecx, esi
// 004ad872  e8d9fcffff           call 0x4ad550
// 004ad877  8b5e04               mov ebx, dword ptr [esi + 4]
// 004ad87a  3b5e08               cmp ebx, dword ptr [esi + 8]
// 004ad87d  7606                 jbe 0x4ad885
// 004ad87f  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ad885  c1e704               shl edi, 4
// 004ad888  03fb                 add edi, ebx
// 004ad88a  3b7e08               cmp edi, dword ptr [esi + 8]
// 004ad88d  895c2420             mov dword ptr [esp + 0x20], ebx
// 004ad891  7705                 ja 0x4ad898
// 004ad893  3b7e04               cmp edi, dword ptr [esi + 4]
// 004ad896  7306                 jae 0x4ad89e
// 004ad898  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ad89e  8b442418             mov eax, dword ptr [esp + 0x18]
// 004ad8a2  897804               mov dword ptr [eax + 4], edi
// 004ad8a5  5f                   pop edi
// 004ad8a6  8930                 mov dword ptr [eax], esi
// 004ad8a8  5e                   pop esi
// 004ad8a9  5d                   pop ebp
// 004ad8aa  5b                   pop ebx
// 004ad8ab  59                   pop ecx
// 004ad8ac  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V32@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
