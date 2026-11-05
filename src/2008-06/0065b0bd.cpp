// from server: 100% by auto
// roc 2008-06 0065b0bd  unit: RBX::BallBallContact  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065b0bd
//
// 0065b0bd  6a00                 push 0
// 0065b0bf  6a00                 push 0
// 0065b0c1  e8c6640400           call 0x6a158c
// 0065b0c6  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0065b0c9  8bcf                 mov ecx, edi
// 0065b0cb  2bc8                 sub ecx, eax
// 0065b0cd  c1f903               sar ecx, 3
// 0065b0d0  3bcb                 cmp ecx, ebx
// 0065b0d2  7374                 jae 0x65b148
// 0065b0d4  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0065b0d7  8b11                 mov edx, dword ptr [ecx]
// 0065b0d9  8b4904               mov ecx, dword ptr [ecx + 4]
// 0065b0dc  894de8               mov dword ptr [ebp - 0x18], ecx
// 0065b0df  8d0cdd00000000       lea ecx, [ebx*8]
// 0065b0e6  894d14               mov dword ptr [ebp + 0x14], ecx
// 0065b0e9  03c8                 add ecx, eax
// 0065b0eb  51                   push ecx
// 0065b0ec  57                   push edi
// 0065b0ed  50                   push eax
// 0065b0ee  8bce                 mov ecx, esi
// 0065b0f0  8955e4               mov dword ptr [ebp - 0x1c], edx
// 0065b0f3  e8b8240200           call 0x67d5b0
// 0065b0f8  8b4610               mov eax, dword ptr [esi + 0x10]
// 0065b0fb  8bc8                 mov ecx, eax
// 0065b0fd  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 0065b100  8d55e4               lea edx, [ebp - 0x1c]
// 0065b103  c1f903               sar ecx, 3
// 0065b106  52                   push edx
// 0065b107  2bd9                 sub ebx, ecx
// 0065b109  53                   push ebx
// 0065b10a  50                   push eax
// 0065b10b  8bce                 mov ecx, esi
// 0065b10d  c745fc02000000       mov dword ptr [ebp - 4], 2
// 0065b114  e807fbffff           call 0x65ac20
// 0065b119  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0065b11c  014610               add dword ptr [esi + 0x10], eax
// 0065b11f  8b7610               mov esi, dword ptr [esi + 0x10]
// 0065b122  8d55e4               lea edx, [ebp - 0x1c]
// 0065b125  52                   push edx
// 0065b126  2bf0                 sub esi, eax
// 0065b128  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0065b12b  56                   push esi
// 0065b12c  50                   push eax
// 0065b12d  e8ee560100           call 0x670820
// 0065b132  83c40c               add esp, 0xc
// 0065b135  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0065b138  64890d00000000       mov dword ptr fs:[0], ecx
// 0065b13f  5f                   pop edi
// 0065b140  5e                   pop esi
// 0065b141  5b                   pop ebx
// 0065b142  8be5                 mov esp, ebp
// 0065b144  5d                   pop ebp
// 0065b145  c21000               ret 0x10
// 0065b148  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0065b14b  8b08                 mov ecx, dword ptr [eax]
// 0065b14d  8b5004               mov edx, dword ptr [eax + 4]
// 0065b150  8d04dd00000000       lea eax, [ebx*8]
// 0065b157  57                   push edi
// 0065b158  8bdf                 mov ebx, edi
// 0065b15a  2bd8                 sub ebx, eax
// 0065b15c  57                   push edi
// 0065b15d  894de4               mov dword ptr [ebp - 0x1c], ecx
// 0065b160  53                   push ebx
// 0065b161  8bce                 mov ecx, esi
// 0065b163  8955e8               mov dword ptr [ebp - 0x18], edx
// 0065b166  894514               mov dword ptr [ebp + 0x14], eax
// 0065b169  e842240200           call 0x67d5b0
// 0065b16e  57                   push edi
// 0065b16f  894610               mov dword ptr [esi + 0x10], eax
// 0065b172  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0065b175  53                   push ebx
// 0065b176  50                   push eax
// 0065b177  e8b4f6ffff           call 0x65a830
// 0065b17c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0065b17f  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0065b182  8d4de4               lea ecx, [ebp - 0x1c]
// 0065b185  51                   push ecx
// 0065b186  03d0                 add edx, eax
// 0065b188  52                   push edx
// 0065b189  50                   push eax
// 0065b18a  e891560100           call 0x670820
// 0065b18f  83c418               add esp, 0x18
// 0065b192  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0065b195  5f                   pop edi
// 0065b196  5e                   pop esi
// 0065b197  64890d00000000       mov dword ptr fs:[0], ecx
// 0065b19e  5b                   pop ebx
// 0065b19f  8be5                 mov esp, ebp
// 0065b1a1  5d                   pop ebp
// 0065b1a2  c21000               ret 0x10
// standard library vector<pod8> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
