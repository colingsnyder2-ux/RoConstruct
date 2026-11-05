// from server: 100% by auto
// roc 2008-06 00699dce  unit: Ogre::RbxSceneManager  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00699dce
//
// 00699dce  6a00                 push 0
// 00699dd0  6a00                 push 0
// 00699dd2  e8b5770000           call 0x6a158c
// 00699dd7  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00699dda  8bd3                 mov edx, ebx
// 00699ddc  2bd1                 sub edx, ecx
// 00699dde  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00699de3  f7ea                 imul edx
// 00699de5  d1fa                 sar edx, 1
// 00699de7  8bc2                 mov eax, edx
// 00699de9  c1e81f               shr eax, 0x1f
// 00699dec  03c2                 add eax, edx
// 00699dee  3bc7                 cmp eax, edi
// 00699df0  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00699df3  0f8384000000         jae 0x699e7d
// 00699df9  8b10                 mov edx, dword ptr [eax]
// 00699dfb  8955dc               mov dword ptr [ebp - 0x24], edx
// 00699dfe  8b5004               mov edx, dword ptr [eax + 4]
// 00699e01  8b4008               mov eax, dword ptr [eax + 8]
// 00699e04  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00699e07  8d047f               lea eax, [edi + edi*2]
// 00699e0a  03c0                 add eax, eax
// 00699e0c  03c0                 add eax, eax
// 00699e0e  894514               mov dword ptr [ebp + 0x14], eax
// 00699e11  03c1                 add eax, ecx
// 00699e13  50                   push eax
// 00699e14  53                   push ebx
// 00699e15  51                   push ecx
// 00699e16  8bce                 mov ecx, esi
// 00699e18  8955e0               mov dword ptr [ebp - 0x20], edx
// 00699e1b  e880deffff           call 0x697ca0
// 00699e20  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00699e23  8d4ddc               lea ecx, [ebp - 0x24]
// 00699e26  51                   push ecx
// 00699e27  8bcb                 mov ecx, ebx
// 00699e29  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 00699e2c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00699e31  f7e9                 imul ecx
// 00699e33  d1fa                 sar edx, 1
// 00699e35  8bc2                 mov eax, edx
// 00699e37  c1e81f               shr eax, 0x1f
// 00699e3a  03c2                 add eax, edx
// 00699e3c  2bf8                 sub edi, eax
// 00699e3e  57                   push edi
// 00699e3f  53                   push ebx
// 00699e40  8bce                 mov ecx, esi
// 00699e42  c745fc02000000       mov dword ptr [ebp - 4], 2
// 00699e49  e862a0ffff           call 0x693eb0
// 00699e4e  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00699e51  014610               add dword ptr [esi + 0x10], eax
// 00699e54  8b7610               mov esi, dword ptr [esi + 0x10]
// 00699e57  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00699e5a  8d4ddc               lea ecx, [ebp - 0x24]
// 00699e5d  51                   push ecx
// 00699e5e  2bf0                 sub esi, eax
// 00699e60  56                   push esi
// 00699e61  52                   push edx
// 00699e62  e87963ffff           call 0x6901e0
// 00699e67  83c40c               add esp, 0xc
// 00699e6a  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00699e6d  64890d00000000       mov dword ptr fs:[0], ecx
// 00699e74  5f                   pop edi
// 00699e75  5e                   pop esi
// 00699e76  5b                   pop ebx
// 00699e77  8be5                 mov esp, ebp
// 00699e79  5d                   pop ebp
// 00699e7a  c21000               ret 0x10
// 00699e7d  8b08                 mov ecx, dword ptr [eax]
// 00699e7f  8b5004               mov edx, dword ptr [eax + 4]
// 00699e82  8b4008               mov eax, dword ptr [eax + 8]
// 00699e85  8d3c7f               lea edi, [edi + edi*2]
// 00699e88  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00699e8b  03ff                 add edi, edi
// 00699e8d  53                   push ebx
// 00699e8e  03ff                 add edi, edi
// 00699e90  8bc3                 mov eax, ebx
// 00699e92  2bc7                 sub eax, edi
// 00699e94  53                   push ebx
// 00699e95  894ddc               mov dword ptr [ebp - 0x24], ecx
// 00699e98  50                   push eax
// 00699e99  8bce                 mov ecx, esi
// 00699e9b  8955e0               mov dword ptr [ebp - 0x20], edx
// 00699e9e  894514               mov dword ptr [ebp + 0x14], eax
// 00699ea1  e8faddffff           call 0x697ca0
// 00699ea6  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00699ea9  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00699eac  53                   push ebx
// 00699ead  51                   push ecx
// 00699eae  52                   push edx
// 00699eaf  894610               mov dword ptr [esi + 0x10], eax
// 00699eb2  e86986ffff           call 0x692520
// 00699eb7  8d45dc               lea eax, [ebp - 0x24]
// 00699eba  50                   push eax
// 00699ebb  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00699ebe  03f8                 add edi, eax
// 00699ec0  57                   push edi
// 00699ec1  50                   push eax
// 00699ec2  e81963ffff           call 0x6901e0
// 00699ec7  83c418               add esp, 0x18
// 00699eca  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00699ecd  5f                   pop edi
// 00699ece  5e                   pop esi
// 00699ecf  64890d00000000       mov dword ptr fs:[0], ecx
// 00699ed6  5b                   pop ebx
// 00699ed7  8be5                 mov esp, ebp
// 00699ed9  5d                   pop ebp
// 00699eda  c21000               ret 0x10
// standard library vector<pod12> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
