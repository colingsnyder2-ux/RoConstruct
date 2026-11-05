// from server: 100% by auto
// roc 2011-06 00444640  unit: G3D::VVector3::?$XItem  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00444640
//
// 00444640  56                   push esi
// 00444641  8bf1                 mov esi, ecx
// 00444643  8b4604               mov eax, dword ptr [esi + 4]
// 00444646  57                   push edi
// 00444647  85c0                 test eax, eax
// 00444649  7410                 je 0x44465b
// 0044464b  50                   push eax
// 0044464c  e8b35c3c00           call 0x80a304
// 00444651  83c404               add esp, 4
// 00444654  c7460400000000       mov dword ptr [esi + 4], 0
// 0044465b  837c241000           cmp dword ptr [esp + 0x10], 0
// 00444660  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00444664  743a                 je 0x4446a0
// 00444666  33c9                 xor ecx, ecx
// 00444668  8bc7                 mov eax, edi
// 0044466a  ba04000000           mov edx, 4
// 0044466f  f7e2                 mul edx
// 00444671  0f90c1               seto cl
// 00444674  f7d9                 neg ecx
// 00444676  0bc8                 or ecx, eax
// 00444678  51                   push ecx
// 00444679  e8c25c3c00           call 0x80a340
// 0044467e  83c404               add esp, 4
// 00444681  894604               mov dword ptr [esi + 4], eax
// 00444684  85c0                 test eax, eax
// 00444686  7505                 jne 0x44468d
// 00444688  e87d5c3c00           call 0x80a30a
// 0044468d  8d0cbd00000000       lea ecx, [edi*4]
// 00444694  51                   push ecx
// 00444695  6a00                 push 0
// 00444697  50                   push eax
// 00444698  e8476c3c00           call 0x80b2e4
// 0044469d  83c40c               add esp, 0xc
// 004446a0  897e08               mov dword ptr [esi + 8], edi
// 004446a3  5f                   pop edi
// 004446a4  5e                   pop esi
// 004446a5  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?InitHashTable@?$CMap@PAUHICON__@@PAU1@HH@@QAEXIH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
