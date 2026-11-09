// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 00620f40  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00620f40
//
// 00620f40  55                   push ebp
// 00620f41  8bec                 mov ebp, esp
// 00620f43  6aff                 push -1
// 00620f45  6808977d00           push 0x7d9708
// 00620f4a  64a100000000         mov eax, dword ptr fs:[0]
// 00620f50  50                   push eax
// 00620f51  64892500000000       mov dword ptr fs:[0], esp
// 00620f58  83ec0c               sub esp, 0xc
// 00620f5b  53                   push ebx
// 00620f5c  56                   push esi
// 00620f5d  57                   push edi
// 00620f5e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00620f61  8bf1                 mov esi, ecx
// 00620f63  6a04                 push 4
// 00620f65  8975e8               mov dword ptr [ebp - 0x18], esi
// 00620f68  e8b3f90700           call 0x6a0920
// 00620f6d  83c404               add esp, 4
// 00620f70  85c0                 test eax, eax
// 00620f72  7404                 je 0x620f78
// 00620f74  8930                 mov dword ptr [eax], esi
// 00620f76  eb02                 jmp 0x620f7a
// 00620f78  33c0                 xor eax, eax
// 00620f7a  8906                 mov dword ptr [esi], eax
// 00620f7c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00620f7f  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00620f82  2b4b0c               sub ecx, dword ptr [ebx + 0xc]
// 00620f85  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00620f8a  f7e9                 imul ecx
// 00620f8c  c1fa02               sar edx, 2
// 00620f8f  8bfa                 mov edi, edx
// 00620f91  b800000000           mov eax, 0
// 00620f96  c1ef1f               shr edi, 0x1f
// 00620f99  03fa                 add edi, edx
// 00620f9b  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00620fa2  89460c               mov dword ptr [esi + 0xc], eax
// 00620fa5  894610               mov dword ptr [esi + 0x10], eax
// 00620fa8  894614               mov dword ptr [esi + 0x14], eax
// 00620fab  746d                 je 0x62101a
// 00620fad  81ffaaaaaa0a         cmp edi, 0xaaaaaaa
// 00620fb3  7605                 jbe 0x620fba
// 00620fb5  e8865deaff           call 0x4c6d40
// 00620fba  50                   push eax
// 00620fbb  57                   push edi
// 00620fbc  e84ff9ffff           call 0x620910
// 00620fc1  8d0c7f               lea ecx, [edi + edi*2]
// 00620fc4  8d14c8               lea edx, [eax + ecx*8]
// 00620fc7  89460c               mov dword ptr [esi + 0xc], eax
// 00620fca  894610               mov dword ptr [esi + 0x10], eax
// 00620fcd  895614               mov dword ptr [esi + 0x14], edx
// 00620fd0  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00620fd3  83c408               add esp, 8
// 00620fd6  c645fc01             mov byte ptr [ebp - 4], 1
// 00620fda  8945ec               mov dword ptr [ebp - 0x14], eax
// 00620fdd  39430c               cmp dword ptr [ebx + 0xc], eax
// 00620fe0  7606                 jbe 0x620fe8
// 00620fe2  ff1590288000         call dword ptr [0x802890]
// 00620fe8  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 00620feb  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 00620fee  7606                 jbe 0x620ff6
// 00620ff0  ff1590288000         call dword ptr [0x802890]
// 00620ff6  8b460c               mov eax, dword ptr [esi + 0xc]
// 00620ff9  c6450800             mov byte ptr [ebp + 8], 0
// 00620ffd  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00621000  8b5508               mov edx, dword ptr [ebp + 8]
// 00621003  51                   push ecx
// 00621004  52                   push edx
// 00621005  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00621008  8d4e08               lea ecx, [esi + 8]
// 0062100b  51                   push ecx
// 0062100c  50                   push eax
// 0062100d  52                   push edx
// 0062100e  57                   push edi
// 0062100f  e86cfcffff           call 0x620c80
// 00621014  83c418               add esp, 0x18
// 00621017  894610               mov dword ptr [esi + 0x10], eax
// 0062101a  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0062101d  5f                   pop edi
// 0062101e  8bc6                 mov eax, esi
// 00621020  5e                   pop esi
// 00621021  64890d00000000       mov dword ptr fs:[0], ecx
// 00621028  5b                   pop ebx
// 00621029  8be5                 mov esp, ebp
// 0062102b  5d                   pop ebp
// 0062102c  c20400               ret 4
// standard library vector<pod24> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
