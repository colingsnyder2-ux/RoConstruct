// from server: 100% by auto
// roc 2008-06 00697510  unit: Ogre::RbxSceneManager  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00697510
//
// 00697510  55                   push ebp
// 00697511  8bec                 mov ebp, esp
// 00697513  6aff                 push -1
// 00697515  6850e87d00           push 0x7de850
// 0069751a  64a100000000         mov eax, dword ptr fs:[0]
// 00697520  50                   push eax
// 00697521  64892500000000       mov dword ptr fs:[0], esp
// 00697528  83ec0c               sub esp, 0xc
// 0069752b  53                   push ebx
// 0069752c  56                   push esi
// 0069752d  57                   push edi
// 0069752e  8b7d08               mov edi, dword ptr [ebp + 8]
// 00697531  8965f0               mov dword ptr [ebp - 0x10], esp
// 00697534  8bf1                 mov esi, ecx
// 00697536  81ffaaaaaa0a         cmp edi, 0xaaaaaaa
// 0069753c  7605                 jbe 0x697543
// 0069753e  e8fdf7e2ff           call 0x4c6d40
// 00697543  8b460c               mov eax, dword ptr [esi + 0xc]
// 00697546  85c0                 test eax, eax
// 00697548  7416                 je 0x697560
// 0069754a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0069754d  2bc8                 sub ecx, eax
// 0069754f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00697554  f7e9                 imul ecx
// 00697556  c1fa02               sar edx, 2
// 00697559  8bc2                 mov eax, edx
// 0069755b  c1e81f               shr eax, 0x1f
// 0069755e  03c2                 add eax, edx
// 00697560  3bc7                 cmp eax, edi
// 00697562  0f8390000000         jae 0x6975f8
// 00697568  6a00                 push 0
// 0069756a  57                   push edi
// 0069756b  e8a093f8ff           call 0x620910
// 00697570  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00697573  83c408               add esp, 8
// 00697576  8945ec               mov dword ptr [ebp - 0x14], eax
// 00697579  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00697580  395e0c               cmp dword ptr [esi + 0xc], ebx
// 00697583  7606                 jbe 0x69758b
// 00697585  ff1590288000         call dword ptr [0x802890]
// 0069758b  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0069758e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00697591  7606                 jbe 0x697599
// 00697593  ff1590288000         call dword ptr [0x802890]
// 00697599  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0069759c  c645e800             mov byte ptr [ebp - 0x18], 0
// 006975a0  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 006975a3  50                   push eax
// 006975a4  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 006975a7  51                   push ecx
// 006975a8  8d5608               lea edx, [esi + 8]
// 006975ab  52                   push edx
// 006975ac  50                   push eax
// 006975ad  53                   push ebx
// 006975ae  57                   push edi
// 006975af  e8ec6bffff           call 0x68e1a0
// 006975b4  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 006975b7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006975ba  2bcb                 sub ecx, ebx
// 006975bc  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006975c1  f7e9                 imul ecx
// 006975c3  c1fa02               sar edx, 2
// 006975c6  8bfa                 mov edi, edx
// 006975c8  c1ef1f               shr edi, 0x1f
// 006975cb  83c418               add esp, 0x18
// 006975ce  03fa                 add edi, edx
// 006975d0  85db                 test ebx, ebx
// 006975d2  7409                 je 0x6975dd
// 006975d4  53                   push ebx
// 006975d5  e8a0900000           call 0x6a067a
// 006975da  83c404               add esp, 4
// 006975dd  8b4508               mov eax, dword ptr [ebp + 8]
// 006975e0  8d0c40               lea ecx, [eax + eax*2]
// 006975e3  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 006975e6  8d14c8               lea edx, [eax + ecx*8]
// 006975e9  8d0c7f               lea ecx, [edi + edi*2]
// 006975ec  895614               mov dword ptr [esi + 0x14], edx
// 006975ef  8d14c8               lea edx, [eax + ecx*8]
// 006975f2  895610               mov dword ptr [esi + 0x10], edx
// 006975f5  89460c               mov dword ptr [esi + 0xc], eax
// 006975f8  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006975fb  5f                   pop edi
// 006975fc  5e                   pop esi
// 006975fd  64890d00000000       mov dword ptr fs:[0], ecx
// 00697604  5b                   pop ebx
// 00697605  8be5                 mov esp, ebp
// 00697607  5d                   pop ebp
// 00697608  c20400               ret 4
// standard library vector<pod24> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
