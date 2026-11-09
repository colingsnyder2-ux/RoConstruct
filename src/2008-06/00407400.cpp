// from server: 100% by auto
// roc 2008-06 00407400  unit: VCApp::?$CComObject  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00407400
//
// 00407400  8b01                 mov eax, dword ptr [ecx]
// 00407402  8b542404             mov edx, dword ptr [esp + 4]
// 00407406  83e810               sub eax, 0x10
// 00407409  56                   push esi
// 0040740a  8b7004               mov esi, dword ptr [eax + 4]
// 0040740d  3bf2                 cmp esi, edx
// 0040740f  7e02                 jle 0x407413
// 00407411  8bd6                 mov edx, esi
// 00407413  83780c01             cmp dword ptr [eax + 0xc], 1
// 00407417  5e                   pop esi
// 00407418  7e09                 jle 0x407423
// 0040741a  89542404             mov dword ptr [esp + 4], edx
// 0040741e  e9bdf8ffff           jmp 0x406ce0
// 00407423  8b4008               mov eax, dword ptr [eax + 8]
// 00407426  3bc2                 cmp eax, edx
// 00407428  7d1f                 jge 0x407449
// 0040742a  3d00040000           cmp eax, 0x400
// 0040742f  7e07                 jle 0x407438
// 00407431  0500040000           add eax, 0x400
// 00407436  eb02                 jmp 0x40743a
// 00407438  03c0                 add eax, eax
// 0040743a  3bc2                 cmp eax, edx
// 0040743c  7d02                 jge 0x407440
// 0040743e  8bc2                 mov eax, edx
// 00407440  89442404             mov dword ptr [esp + 4], eax
// 00407444  e917f9ffff           jmp 0x406d60
// 00407449  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ?PrepareWrite2@?$CSimpleStringT@D$0A@@ATL@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
