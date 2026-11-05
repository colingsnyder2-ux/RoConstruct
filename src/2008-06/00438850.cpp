// from server: 100% by auto
// roc 2008-06 00438850  unit: RBX::Soundscape::VSoundId::?$XItem  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00438850
//
// 00438850  56                   push esi
// 00438851  8bf1                 mov esi, ecx
// 00438853  8b4604               mov eax, dword ptr [esi + 4]
// 00438856  57                   push edi
// 00438857  85c0                 test eax, eax
// 00438859  7410                 je 0x43886b
// 0043885b  50                   push eax
// 0043885c  e8e9802600           call 0x6a094a
// 00438861  83c404               add esp, 4
// 00438864  c7460400000000       mov dword ptr [esi + 4], 0
// 0043886b  837c241000           cmp dword ptr [esp + 0x10], 0
// 00438870  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00438874  743a                 je 0x4388b0
// 00438876  33c9                 xor ecx, ecx
// 00438878  8bc7                 mov eax, edi
// 0043887a  ba04000000           mov edx, 4
// 0043887f  f7e2                 mul edx
// 00438881  0f90c1               seto cl
// 00438884  f7d9                 neg ecx
// 00438886  0bc8                 or ecx, eax
// 00438888  51                   push ecx
// 00438889  e8c8802600           call 0x6a0956
// 0043888e  83c404               add esp, 4
// 00438891  894604               mov dword ptr [esi + 4], eax
// 00438894  85c0                 test eax, eax
// 00438896  7505                 jne 0x43889d
// 00438898  e8a7802600           call 0x6a0944
// 0043889d  8d0cbd00000000       lea ecx, [edi*4]
// 004388a4  51                   push ecx
// 004388a5  6a00                 push 0
// 004388a7  50                   push eax
// 004388a8  e8578e2600           call 0x6a1704
// 004388ad  83c40c               add esp, 0xc
// 004388b0  897e08               mov dword ptr [esi + 8], edi
// 004388b3  5f                   pop edi
// 004388b4  5e                   pop esi
// 004388b5  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?InitHashTable@?$CMap@PAUHICON__@@PAU1@HH@@QAEXIH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
