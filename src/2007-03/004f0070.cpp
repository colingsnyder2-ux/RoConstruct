// from server: 100% by auto
// roc 2007-03 004f0070  unit: seg_004f0000  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004f0070
//
// 004f0070  53                   push ebx
// 004f0071  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004f0075  8b4304               mov eax, dword ptr [ebx + 4]
// 004f0078  56                   push esi
// 004f0079  57                   push edi
// 004f007a  8bf9                 mov edi, ecx
// 004f007c  33c9                 xor ecx, ecx
// 004f007e  3bc1                 cmp eax, ecx
// 004f0080  7504                 jne 0x4f0086
// 004f0082  33f6                 xor esi, esi
// 004f0084  eb08                 jmp 0x4f008e
// 004f0086  8b7308               mov esi, dword ptr [ebx + 8]
// 004f0089  2bf0                 sub esi, eax
// 004f008b  c1fe02               sar esi, 2
// 004f008e  3bf1                 cmp esi, ecx
// 004f0090  894f04               mov dword ptr [edi + 4], ecx
// 004f0093  894f08               mov dword ptr [edi + 8], ecx
// 004f0096  894f0c               mov dword ptr [edi + 0xc], ecx
// 004f0099  7465                 je 0x4f0100
// 004f009b  81feffffff3f         cmp esi, 0x3fffffff
// 004f00a1  7605                 jbe 0x4f00a8
// 004f00a3  e868a8f5ff           call 0x44a910
// 004f00a8  51                   push ecx
// 004f00a9  56                   push esi
// 004f00aa  e8b18cf2ff           call 0x418d60
// 004f00af  894704               mov dword ptr [edi + 4], eax
// 004f00b2  894708               mov dword ptr [edi + 8], eax
// 004f00b5  8d04b0               lea eax, [eax + esi*4]
// 004f00b8  89470c               mov dword ptr [edi + 0xc], eax
// 004f00bb  8b7308               mov esi, dword ptr [ebx + 8]
// 004f00be  83c408               add esp, 8
// 004f00c1  397304               cmp dword ptr [ebx + 4], esi
// 004f00c4  7606                 jbe 0x4f00cc
// 004f00c6  ff1544e97700         call dword ptr [0x77e944]
// 004f00cc  55                   push ebp
// 004f00cd  8b6b04               mov ebp, dword ptr [ebx + 4]
// 004f00d0  3b6b08               cmp ebp, dword ptr [ebx + 8]
// 004f00d3  7606                 jbe 0x4f00db
// 004f00d5  ff1544e97700         call dword ptr [0x77e944]
// 004f00db  8b4f04               mov ecx, dword ptr [edi + 4]
// 004f00de  2bf5                 sub esi, ebp
// 004f00e0  c1fe02               sar esi, 2
// 004f00e3  8d04b500000000       lea eax, [esi*4]
// 004f00ea  8d3408               lea esi, [eax + ecx]
// 004f00ed  740d                 je 0x4f00fc
// 004f00ef  50                   push eax
// 004f00f0  55                   push ebp
// 004f00f1  50                   push eax
// 004f00f2  51                   push ecx
// 004f00f3  ff1578e97700         call dword ptr [0x77e978]
// 004f00f9  83c410               add esp, 0x10
// 004f00fc  897708               mov dword ptr [edi + 8], esi
// 004f00ff  5d                   pop ebp
// 004f0100  8bc7                 mov eax, edi
// 004f0102  5f                   pop edi
// 004f0103  5e                   pop esi
// 004f0104  5b                   pop ebx
// 004f0105  c20400               ret 4
// standard library vector<ptr> (function ??0?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
