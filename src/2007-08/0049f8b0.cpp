// from server: 100% by auto
// roc 2007-08 0049f8b0  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0049f8b0
//
// 0049f8b0  56                   push esi
// 0049f8b1  8bf1                 mov esi, ecx
// 0049f8b3  8a4c2410             mov cl, byte ptr [esp + 0x10]
// 0049f8b7  57                   push edi
// 0049f8b8  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0049f8bc  33d2                 xor edx, edx
// 0049f8be  3aca                 cmp cl, dl
// 0049f8c0  8d04fd00000000       lea eax, [edi*8]
// 0049f8c7  8906                 mov dword ptr [esi], eax
// 0049f8c9  895608               mov dword ptr [esi + 8], edx
// 0049f8cc  884e10               mov byte ptr [esi + 0x10], cl
// 0049f8cf  894604               mov dword ptr [esi + 4], eax
// 0049f8d2  7447                 je 0x49f91b
// 0049f8d4  3bfa                 cmp edi, edx
// 0049f8d6  7639                 jbe 0x49f911
// 0049f8d8  81ff00010000         cmp edi, 0x100
// 0049f8de  730c                 jae 0x49f8ec
// 0049f8e0  8d4611               lea eax, [esi + 0x11]
// 0049f8e3  c7460400080000       mov dword ptr [esi + 4], 0x800
// 0049f8ea  eb0a                 jmp 0x49f8f6
// 0049f8ec  57                   push edi
// 0049f8ed  ff15d0e67700         call dword ptr [0x77e6d0]
// 0049f8f3  83c404               add esp, 4
// 0049f8f6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0049f8fa  57                   push edi
// 0049f8fb  51                   push ecx
// 0049f8fc  8bd0                 mov edx, eax
// 0049f8fe  52                   push edx
// 0049f8ff  89460c               mov dword ptr [esi + 0xc], eax
// 0049f902  e845141900           call 0x630d4c
// 0049f907  83c40c               add esp, 0xc
// 0049f90a  5f                   pop edi
// 0049f90b  8bc6                 mov eax, esi
// 0049f90d  5e                   pop esi
// 0049f90e  c20c00               ret 0xc
// 0049f911  5f                   pop edi
// 0049f912  89560c               mov dword ptr [esi + 0xc], edx
// 0049f915  8bc6                 mov eax, esi
// 0049f917  5e                   pop esi
// 0049f918  c20c00               ret 0xc
// 0049f91b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0049f91f  89460c               mov dword ptr [esi + 0xc], eax
// 0049f922  5f                   pop edi
// 0049f923  8bc6                 mov eax, esi
// 0049f925  5e                   pop esi
// 0049f926  c20c00               ret 0xc
// library openrbx-raknet/BitStream.cpp (function ??0BitStream@RakNet@@QAE@PAEI_N@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet BitStream.cpp
