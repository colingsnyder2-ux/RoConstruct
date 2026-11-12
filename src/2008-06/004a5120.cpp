// from server: 100% by auto
// roc 2008-06 004a5120  unit: RBX::VHint::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a5120
//
// 004a5120  56                   push esi
// 004a5121  8bf1                 mov esi, ecx
// 004a5123  8a4c2410             mov cl, byte ptr [esp + 0x10]
// 004a5127  57                   push edi
// 004a5128  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a512c  33d2                 xor edx, edx
// 004a512e  8d04fd00000000       lea eax, [edi*8]
// 004a5135  8906                 mov dword ptr [esi], eax
// 004a5137  895608               mov dword ptr [esi + 8], edx
// 004a513a  884e10               mov byte ptr [esi + 0x10], cl
// 004a513d  894604               mov dword ptr [esi + 4], eax
// 004a5140  3aca                 cmp cl, dl
// 004a5142  7447                 je 0x4a518b
// 004a5144  3bfa                 cmp edi, edx
// 004a5146  7639                 jbe 0x4a5181
// 004a5148  81ff00010000         cmp edi, 0x100
// 004a514e  730c                 jae 0x4a515c
// 004a5150  8d4611               lea eax, [esi + 0x11]
// 004a5153  c7460400080000       mov dword ptr [esi + 4], 0x800
// 004a515a  eb0a                 jmp 0x4a5166
// 004a515c  57                   push edi
// 004a515d  ff15b0288000         call dword ptr [0x8028b0]
// 004a5163  83c404               add esp, 4
// 004a5166  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a516a  57                   push edi
// 004a516b  51                   push ecx
// 004a516c  8bd0                 mov edx, eax
// 004a516e  52                   push edx
// 004a516f  89460c               mov dword ptr [esi + 0xc], eax
// 004a5172  e869c61f00           call 0x6a17e0
// 004a5177  83c40c               add esp, 0xc
// 004a517a  5f                   pop edi
// 004a517b  8bc6                 mov eax, esi
// 004a517d  5e                   pop esi
// 004a517e  c20c00               ret 0xc
// 004a5181  5f                   pop edi
// 004a5182  89560c               mov dword ptr [esi + 0xc], edx
// 004a5185  8bc6                 mov eax, esi
// 004a5187  5e                   pop esi
// 004a5188  c20c00               ret 0xc
// 004a518b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004a518f  89460c               mov dword ptr [esi + 0xc], eax
// 004a5192  5f                   pop edi
// 004a5193  8bc6                 mov eax, esi
// 004a5195  5e                   pop esi
// 004a5196  c20c00               ret 0xc
// library openrbx-raknet/BitStream.cpp (function ??0BitStream@RakNet@@QAE@PAEI_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet BitStream.cpp
