// from server: 100% by auto
// roc 2008-06 0067d8f0  unit: Ogre::RbxEntity  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0067d8f0
//
// 0067d8f0  83ec08               sub esp, 8
// 0067d8f3  53                   push ebx
// 0067d8f4  55                   push ebp
// 0067d8f5  56                   push esi
// 0067d8f6  8bf1                 mov esi, ecx
// 0067d8f8  8b4610               mov eax, dword ptr [esi + 0x10]
// 0067d8fb  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0067d8fe  8bc8                 mov ecx, eax
// 0067d900  2bcb                 sub ecx, ebx
// 0067d902  57                   push edi
// 0067d903  f7c1f0ffffff         test ecx, 0xfffffff0
// 0067d909  7504                 jne 0x67d90f
// 0067d90b  33ff                 xor edi, edi
// 0067d90d  eb27                 jmp 0x67d936
// 0067d90f  3bd8                 cmp ebx, eax
// 0067d911  7606                 jbe 0x67d919
// 0067d913  ff1590288000         call dword ptr [0x802890]
// 0067d919  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0067d91d  8b06                 mov eax, dword ptr [esi]
// 0067d91f  85c9                 test ecx, ecx
// 0067d921  7404                 je 0x67d927
// 0067d923  3bc8                 cmp ecx, eax
// 0067d925  7406                 je 0x67d92d
// 0067d927  ff1590288000         call dword ptr [0x802890]
// 0067d92d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0067d931  2bfb                 sub edi, ebx
// 0067d933  c1ff04               sar edi, 4
// 0067d936  8b542428             mov edx, dword ptr [esp + 0x28]
// 0067d93a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0067d93e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0067d942  52                   push edx
// 0067d943  6a01                 push 1
// 0067d945  50                   push eax
// 0067d946  51                   push ecx
// 0067d947  8bce                 mov ecx, esi
// 0067d949  e8b2fcffff           call 0x67d600
// 0067d94e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0067d951  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0067d954  7606                 jbe 0x67d95c
// 0067d956  ff1590288000         call dword ptr [0x802890]
// 0067d95c  8b36                 mov esi, dword ptr [esi]
// 0067d95e  8bee                 mov ebp, esi
// 0067d960  895c2414             mov dword ptr [esp + 0x14], ebx
// 0067d964  85f6                 test esi, esi
// 0067d966  751a                 jne 0x67d982
// 0067d968  ff1590288000         call dword ptr [0x802890]
// 0067d96e  33c0                 xor eax, eax
// 0067d970  c1e704               shl edi, 4
// 0067d973  03fb                 add edi, ebx
// 0067d975  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0067d978  7713                 ja 0x67d98d
// 0067d97a  85f6                 test esi, esi
// 0067d97c  7408                 je 0x67d986
// 0067d97e  8b36                 mov esi, dword ptr [esi]
// 0067d980  eb06                 jmp 0x67d988
// 0067d982  8b06                 mov eax, dword ptr [esi]
// 0067d984  ebea                 jmp 0x67d970
// 0067d986  33f6                 xor esi, esi
// 0067d988  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0067d98b  7306                 jae 0x67d993
// 0067d98d  ff1590288000         call dword ptr [0x802890]
// 0067d993  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0067d997  897804               mov dword ptr [eax + 4], edi
// 0067d99a  5f                   pop edi
// 0067d99b  5e                   pop esi
// 0067d99c  8928                 mov dword ptr [eax], ebp
// 0067d99e  5d                   pop ebp
// 0067d99f  5b                   pop ebx
// 0067d9a0  83c408               add esp, 8
// 0067d9a3  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
