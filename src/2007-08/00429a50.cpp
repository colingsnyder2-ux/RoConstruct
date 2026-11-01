// from server: 100% by auto
// roc 2007-08 00429a50  unit: ThreadLogManager  size: 187 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00429a50
//
// 00429a50  55                   push ebp
// 00429a51  8bec                 mov ebp, esp
// 00429a53  6aff                 push -1
// 00429a55  6850cd7300           push 0x73cd50
// 00429a5a  64a100000000         mov eax, dword ptr fs:[0]
// 00429a60  50                   push eax
// 00429a61  83ec0c               sub esp, 0xc
// 00429a64  53                   push ebx
// 00429a65  56                   push esi
// 00429a66  57                   push edi
// 00429a67  a188518b00           mov eax, dword ptr [0x8b5188]
// 00429a6c  33c5                 xor eax, ebp
// 00429a6e  50                   push eax
// 00429a6f  8d45f4               lea eax, [ebp - 0xc]
// 00429a72  64a300000000         mov dword ptr fs:[0], eax
// 00429a78  8965f0               mov dword ptr [ebp - 0x10], esp
// 00429a7b  8bf9                 mov edi, ecx
// 00429a7d  897de8               mov dword ptr [ebp - 0x18], edi
// 00429a80  8b7508               mov esi, dword ptr [ebp + 8]
// 00429a83  8b4604               mov eax, dword ptr [esi + 4]
// 00429a86  85c0                 test eax, eax
// 00429a88  7418                 je 0x429aa2
// 00429a8a  8b4e08               mov ecx, dword ptr [esi + 8]
// 00429a8d  2bc8                 sub ecx, eax
// 00429a8f  b893244992           mov eax, 0x92492493
// 00429a94  f7e9                 imul ecx
// 00429a96  03d1                 add edx, ecx
// 00429a98  c1fa04               sar edx, 4
// 00429a9b  8bc2                 mov eax, edx
// 00429a9d  c1e81f               shr eax, 0x1f
// 00429aa0  03c2                 add eax, edx
// 00429aa2  50                   push eax
// 00429aa3  8bcf                 mov ecx, edi
// 00429aa5  e826f4ffff           call 0x428ed0
// 00429aaa  84c0                 test al, al
// 00429aac  7447                 je 0x429af5
// 00429aae  8b4608               mov eax, dword ptr [esi + 8]
// 00429ab1  394604               cmp dword ptr [esi + 4], eax
// 00429ab4  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00429abb  8945ec               mov dword ptr [ebp - 0x14], eax
// 00429abe  7606                 jbe 0x429ac6
// 00429ac0  ff15d8e67700         call dword ptr [0x77e6d8]
// 00429ac6  8b5e04               mov ebx, dword ptr [esi + 4]
// 00429ac9  3b5e08               cmp ebx, dword ptr [esi + 8]
// 00429acc  7606                 jbe 0x429ad4
// 00429ace  ff15d8e67700         call dword ptr [0x77e6d8]
// 00429ad4  8b4704               mov eax, dword ptr [edi + 4]
// 00429ad7  c6450800             mov byte ptr [ebp + 8], 0
// 00429adb  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00429ade  8b5508               mov edx, dword ptr [ebp + 8]
// 00429ae1  51                   push ecx
// 00429ae2  52                   push edx
// 00429ae3  57                   push edi
// 00429ae4  50                   push eax
// 00429ae5  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00429ae8  50                   push eax
// 00429ae9  53                   push ebx
// 00429aea  e8c1edffff           call 0x4288b0
// 00429aef  83c418               add esp, 0x18
// 00429af2  894708               mov dword ptr [edi + 8], eax
// 00429af5  8bc7                 mov eax, edi
// 00429af7  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00429afa  64890d00000000       mov dword ptr fs:[0], ecx
// 00429b01  59                   pop ecx
// 00429b02  5f                   pop edi
// 00429b03  5e                   pop esi
// 00429b04  5b                   pop ebx
// 00429b05  8be5                 mov esp, ebp
// 00429b07  5d                   pop ebp
// 00429b08  c20400               ret 4
// standard library vector<string> (function ??0?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@ABV01@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
