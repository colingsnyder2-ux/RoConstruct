// from server: 100% by auto
// roc 2009-12 007c29d0  unit: RBX::VChatLine::?$sp_counted_impl_p  size: 190 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c29d0
//
// 007c29d0  55                   push ebp
// 007c29d1  8bec                 mov ebp, esp
// 007c29d3  6aff                 push -1
// 007c29d5  6868659500           push 0x956568
// 007c29da  64a100000000         mov eax, dword ptr fs:[0]
// 007c29e0  50                   push eax
// 007c29e1  64892500000000       mov dword ptr fs:[0], esp
// 007c29e8  83ec1c               sub esp, 0x1c
// 007c29eb  53                   push ebx
// 007c29ec  56                   push esi
// 007c29ed  57                   push edi
// 007c29ee  8965f0               mov dword ptr [ebp - 0x10], esp
// 007c29f1  8bd9                 mov ebx, ecx
// 007c29f3  6a04                 push 4
// 007c29f5  895de8               mov dword ptr [ebp - 0x18], ebx
// 007c29f8  e8630e0300           call 0x7f3860
// 007c29fd  33c9                 xor ecx, ecx
// 007c29ff  83c404               add esp, 4
// 007c2a02  3bc1                 cmp eax, ecx
// 007c2a04  7407                 je 0x7c2a0d
// 007c2a06  8918                 mov dword ptr [eax], ebx
// 007c2a08  8945ec               mov dword ptr [ebp - 0x14], eax
// 007c2a0b  eb03                 jmp 0x7c2a10
// 007c2a0d  894dec               mov dword ptr [ebp - 0x14], ecx
// 007c2a10  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 007c2a13  8903                 mov dword ptr [ebx], eax
// 007c2a15  8b7508               mov esi, dword ptr [ebp + 8]
// 007c2a18  894b10               mov dword ptr [ebx + 0x10], ecx
// 007c2a1b  894b14               mov dword ptr [ebx + 0x14], ecx
// 007c2a1e  894b18               mov dword ptr [ebx + 0x18], ecx
// 007c2a21  894b1c               mov dword ptr [ebx + 0x1c], ecx
// 007c2a24  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c2a27  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 007c2a2a  03f8                 add edi, eax
// 007c2a2c  894dfc               mov dword ptr [ebp - 4], ecx
// 007c2a2f  c645fc01             mov byte ptr [ebp - 4], 1
// 007c2a33  894ddc               mov dword ptr [ebp - 0x24], ecx
// 007c2a36  3bc7                 cmp eax, edi
// 007c2a38  7606                 jbe 0x7c2a40
// 007c2a3a  ff1560b79800         call dword ptr [0x98b760]
// 007c2a40  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c2a43  8b561c               mov edx, dword ptr [esi + 0x1c]
// 007c2a46  8b0e                 mov ecx, dword ptr [esi]
// 007c2a48  03d0                 add edx, eax
// 007c2a4a  894de0               mov dword ptr [ebp - 0x20], ecx
// 007c2a4d  894508               mov dword ptr [ebp + 8], eax
// 007c2a50  3bc2                 cmp eax, edx
// 007c2a52  7609                 jbe 0x7c2a5d
// 007c2a54  ff1560b79800         call dword ptr [0x98b760]
// 007c2a5a  8b4508               mov eax, dword ptr [ebp + 8]
// 007c2a5d  8b4d08               mov ecx, dword ptr [ebp + 8]
// 007c2a60  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 007c2a63  8b36                 mov esi, dword ptr [esi]
// 007c2a65  51                   push ecx
// 007c2a66  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 007c2a69  57                   push edi
// 007c2a6a  52                   push edx
// 007c2a6b  50                   push eax
// 007c2a6c  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 007c2a6f  56                   push esi
// 007c2a70  50                   push eax
// 007c2a71  51                   push ecx
// 007c2a72  8bcb                 mov ecx, ebx
// 007c2a74  e887fcffff           call 0x7c2700
// 007c2a79  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 007c2a7c  5f                   pop edi
// 007c2a7d  5e                   pop esi
// 007c2a7e  8bc3                 mov eax, ebx
// 007c2a80  64890d00000000       mov dword ptr fs:[0], ecx
// 007c2a87  5b                   pop ebx
// 007c2a88  8be5                 mov esp, ebp
// 007c2a8a  5d                   pop ebp
// 007c2a8b  c20400               ret 4
// standard library deque<ptr> (function ??0?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV01@@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
