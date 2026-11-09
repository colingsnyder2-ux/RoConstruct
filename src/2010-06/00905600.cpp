// from server: 100% by auto
// roc 2010-06 00905600  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00905600
//
// 00905600  83ec08               sub esp, 8
// 00905603  53                   push ebx
// 00905604  55                   push ebp
// 00905605  56                   push esi
// 00905606  8bf1                 mov esi, ecx
// 00905608  8b4610               mov eax, dword ptr [esi + 0x10]
// 0090560b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0090560e  8bc8                 mov ecx, eax
// 00905610  2bcb                 sub ecx, ebx
// 00905612  57                   push edi
// 00905613  f7c1f0ffffff         test ecx, 0xfffffff0
// 00905619  7504                 jne 0x90561f
// 0090561b  33ff                 xor edi, edi
// 0090561d  eb27                 jmp 0x905646
// 0090561f  3bd8                 cmp ebx, eax
// 00905621  7606                 jbe 0x905629
// 00905623  ff150ca99e00         call dword ptr [0x9ea90c]
// 00905629  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0090562d  8b06                 mov eax, dword ptr [esi]
// 0090562f  85c9                 test ecx, ecx
// 00905631  7404                 je 0x905637
// 00905633  3bc8                 cmp ecx, eax
// 00905635  7406                 je 0x90563d
// 00905637  ff150ca99e00         call dword ptr [0x9ea90c]
// 0090563d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00905641  2bfb                 sub edi, ebx
// 00905643  c1ff04               sar edi, 4
// 00905646  8b542428             mov edx, dword ptr [esp + 0x28]
// 0090564a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0090564e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00905652  52                   push edx
// 00905653  6a01                 push 1
// 00905655  50                   push eax
// 00905656  51                   push ecx
// 00905657  8bce                 mov ecx, esi
// 00905659  e8a2f4ffff           call 0x904b00
// 0090565e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00905661  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00905664  7606                 jbe 0x90566c
// 00905666  ff150ca99e00         call dword ptr [0x9ea90c]
// 0090566c  8b36                 mov esi, dword ptr [esi]
// 0090566e  8bee                 mov ebp, esi
// 00905670  895c2414             mov dword ptr [esp + 0x14], ebx
// 00905674  85f6                 test esi, esi
// 00905676  751a                 jne 0x905692
// 00905678  ff150ca99e00         call dword ptr [0x9ea90c]
// 0090567e  33c0                 xor eax, eax
// 00905680  c1e704               shl edi, 4
// 00905683  03fb                 add edi, ebx
// 00905685  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00905688  7713                 ja 0x90569d
// 0090568a  85f6                 test esi, esi
// 0090568c  7408                 je 0x905696
// 0090568e  8b36                 mov esi, dword ptr [esi]
// 00905690  eb06                 jmp 0x905698
// 00905692  8b06                 mov eax, dword ptr [esi]
// 00905694  ebea                 jmp 0x905680
// 00905696  33f6                 xor esi, esi
// 00905698  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0090569b  7306                 jae 0x9056a3
// 0090569d  ff150ca99e00         call dword ptr [0x9ea90c]
// 009056a3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 009056a7  897804               mov dword ptr [eax + 4], edi
// 009056aa  5f                   pop edi
// 009056ab  5e                   pop esi
// 009056ac  8928                 mov dword ptr [eax], ebp
// 009056ae  5d                   pop ebp
// 009056af  5b                   pop ebx
// 009056b0  83c408               add esp, 8
// 009056b3  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
