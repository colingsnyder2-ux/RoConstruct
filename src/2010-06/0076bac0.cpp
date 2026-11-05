// from server: 100% by auto
// roc 2010-06 0076bac0  unit: RBX::VChatLine::?$sp_counted_impl_p  size: 190 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076bac0
//
// 0076bac0  55                   push ebp
// 0076bac1  8bec                 mov ebp, esp
// 0076bac3  6aff                 push -1
// 0076bac5  6868bf9a00           push 0x9abf68
// 0076baca  64a100000000         mov eax, dword ptr fs:[0]
// 0076bad0  50                   push eax
// 0076bad1  64892500000000       mov dword ptr fs:[0], esp
// 0076bad8  83ec1c               sub esp, 0x1c
// 0076badb  53                   push ebx
// 0076badc  56                   push esi
// 0076badd  57                   push edi
// 0076bade  8965f0               mov dword ptr [ebp - 0x10], esp
// 0076bae1  8bd9                 mov ebx, ecx
// 0076bae3  6a04                 push 4
// 0076bae5  895de8               mov dword ptr [ebp - 0x18], ebx
// 0076bae8  e8b3be0300           call 0x7a79a0
// 0076baed  33c9                 xor ecx, ecx
// 0076baef  83c404               add esp, 4
// 0076baf2  3bc1                 cmp eax, ecx
// 0076baf4  7407                 je 0x76bafd
// 0076baf6  8918                 mov dword ptr [eax], ebx
// 0076baf8  8945ec               mov dword ptr [ebp - 0x14], eax
// 0076bafb  eb03                 jmp 0x76bb00
// 0076bafd  894dec               mov dword ptr [ebp - 0x14], ecx
// 0076bb00  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0076bb03  8903                 mov dword ptr [ebx], eax
// 0076bb05  8b7508               mov esi, dword ptr [ebp + 8]
// 0076bb08  894b10               mov dword ptr [ebx + 0x10], ecx
// 0076bb0b  894b14               mov dword ptr [ebx + 0x14], ecx
// 0076bb0e  894b18               mov dword ptr [ebx + 0x18], ecx
// 0076bb11  894b1c               mov dword ptr [ebx + 0x1c], ecx
// 0076bb14  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076bb17  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 0076bb1a  03f8                 add edi, eax
// 0076bb1c  894dfc               mov dword ptr [ebp - 4], ecx
// 0076bb1f  c645fc01             mov byte ptr [ebp - 4], 1
// 0076bb23  894ddc               mov dword ptr [ebp - 0x24], ecx
// 0076bb26  3bc7                 cmp eax, edi
// 0076bb28  7606                 jbe 0x76bb30
// 0076bb2a  ff150ca99e00         call dword ptr [0x9ea90c]
// 0076bb30  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076bb33  8b561c               mov edx, dword ptr [esi + 0x1c]
// 0076bb36  8b0e                 mov ecx, dword ptr [esi]
// 0076bb38  03d0                 add edx, eax
// 0076bb3a  894de0               mov dword ptr [ebp - 0x20], ecx
// 0076bb3d  894508               mov dword ptr [ebp + 8], eax
// 0076bb40  3bc2                 cmp eax, edx
// 0076bb42  7609                 jbe 0x76bb4d
// 0076bb44  ff150ca99e00         call dword ptr [0x9ea90c]
// 0076bb4a  8b4508               mov eax, dword ptr [ebp + 8]
// 0076bb4d  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0076bb50  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 0076bb53  8b36                 mov esi, dword ptr [esi]
// 0076bb55  51                   push ecx
// 0076bb56  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0076bb59  57                   push edi
// 0076bb5a  52                   push edx
// 0076bb5b  50                   push eax
// 0076bb5c  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0076bb5f  56                   push esi
// 0076bb60  50                   push eax
// 0076bb61  51                   push ecx
// 0076bb62  8bcb                 mov ecx, ebx
// 0076bb64  e887fcffff           call 0x76b7f0
// 0076bb69  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0076bb6c  5f                   pop edi
// 0076bb6d  5e                   pop esi
// 0076bb6e  8bc3                 mov eax, ebx
// 0076bb70  64890d00000000       mov dword ptr fs:[0], ecx
// 0076bb77  5b                   pop ebx
// 0076bb78  8be5                 mov esp, ebp
// 0076bb7a  5d                   pop ebp
// 0076bb7b  c20400               ret 4
// standard library deque<ptr> (function ??0?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV01@@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
