// from server: 100% by auto
// roc 2009-12 00492170  unit: Ogre::RbxEntity  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00492170
//
// 00492170  83ec08               sub esp, 8
// 00492173  53                   push ebx
// 00492174  56                   push esi
// 00492175  8bf1                 mov esi, ecx
// 00492177  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0049217a  57                   push edi
// 0049217b  85db                 test ebx, ebx
// 0049217d  7504                 jne 0x492183
// 0049217f  33c9                 xor ecx, ecx
// 00492181  eb15                 jmp 0x492198
// 00492183  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00492186  2bcb                 sub ecx, ebx
// 00492188  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0049218d  f7e9                 imul ecx
// 0049218f  d1fa                 sar edx, 1
// 00492191  8bca                 mov ecx, edx
// 00492193  c1e91f               shr ecx, 0x1f
// 00492196  03ca                 add ecx, edx
// 00492198  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0049219b  8bd7                 mov edx, edi
// 0049219d  2bd3                 sub edx, ebx
// 0049219f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004921a4  f7ea                 imul edx
// 004921a6  d1fa                 sar edx, 1
// 004921a8  8bc2                 mov eax, edx
// 004921aa  c1e81f               shr eax, 0x1f
// 004921ad  03c2                 add eax, edx
// 004921af  3bc1                 cmp eax, ecx
// 004921b1  7332                 jae 0x4921e5
// 004921b3  8b542418             mov edx, dword ptr [esp + 0x18]
// 004921b7  c644240c00           mov byte ptr [esp + 0xc], 0
// 004921bc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004921c0  51                   push ecx
// 004921c1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004921c5  52                   push edx
// 004921c6  8d4608               lea eax, [esi + 8]
// 004921c9  50                   push eax
// 004921ca  51                   push ecx
// 004921cb  6a01                 push 1
// 004921cd  57                   push edi
// 004921ce  e8edf31100           call 0x5b15c0
// 004921d3  83c418               add esp, 0x18
// 004921d6  83c70c               add edi, 0xc
// 004921d9  897e10               mov dword ptr [esi + 0x10], edi
// 004921dc  5f                   pop edi
// 004921dd  5e                   pop esi
// 004921de  5b                   pop ebx
// 004921df  83c408               add esp, 8
// 004921e2  c20400               ret 4
// 004921e5  3bdf                 cmp ebx, edi
// 004921e7  7606                 jbe 0x4921ef
// 004921e9  ff1560b79800         call dword ptr [0x98b760]
// 004921ef  8b542418             mov edx, dword ptr [esp + 0x18]
// 004921f3  8b06                 mov eax, dword ptr [esi]
// 004921f5  52                   push edx
// 004921f6  57                   push edi
// 004921f7  50                   push eax
// 004921f8  8d442418             lea eax, [esp + 0x18]
// 004921fc  50                   push eax
// 004921fd  8bce                 mov ecx, esi
// 004921ff  e89cfeffff           call 0x4920a0
// 00492204  5f                   pop edi
// 00492205  5e                   pop esi
// 00492206  5b                   pop ebx
// 00492207  83c408               add esp, 8
// 0049220a  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
