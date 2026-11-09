// from server: 100% by auto
// roc 2009-06 005d8da0  unit: VAuthoringSettings::?$BoundPropGetSet  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d8da0
//
// 005d8da0  53                   push ebx
// 005d8da1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005d8da5  57                   push edi
// 005d8da6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005d8daa  57                   push edi
// 005d8dab  53                   push ebx
// 005d8dac  ff15bce18900         call dword ptr [0x89e1bc]
// 005d8db2  85c0                 test eax, eax
// 005d8db4  7503                 jne 0x5d8db9
// 005d8db6  5f                   pop edi
// 005d8db7  5b                   pop ebx
// 005d8db8  c3                   ret 
// 005d8db9  56                   push esi
// 005d8dba  50                   push eax
// 005d8dbb  ff1550e28900         call dword ptr [0x89e250]
// 005d8dc1  8bf0                 mov esi, eax
// 005d8dc3  85f6                 test esi, esi
// 005d8dc5  742d                 je 0x5d8df4
// 005d8dc7  57                   push edi
// 005d8dc8  53                   push ebx
// 005d8dc9  ff15b8e18900         call dword ptr [0x89e1b8]
// 005d8dcf  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005d8dd3  03c6                 add eax, esi
// 005d8dd5  83e10f               and ecx, 0xf
// 005d8dd8  7616                 jbe 0x5d8df0
// 005d8dda  8d9b00000000         lea ebx, [ebx]
// 005d8de0  3bf0                 cmp esi, eax
// 005d8de2  7310                 jae 0x5d8df4
// 005d8de4  83e901               sub ecx, 1
// 005d8de7  0fb716               movzx edx, word ptr [esi]
// 005d8dea  8d745602             lea esi, [esi + edx*2 + 2]
// 005d8dee  75f0                 jne 0x5d8de0
// 005d8df0  3bf0                 cmp esi, eax
// 005d8df2  7206                 jb 0x5d8dfa
// 005d8df4  5e                   pop esi
// 005d8df5  5f                   pop edi
// 005d8df6  33c0                 xor eax, eax
// 005d8df8  5b                   pop ebx
// 005d8df9  c3                   ret 
// 005d8dfa  0fb706               movzx eax, word ptr [esi]
// 005d8dfd  f7d8                 neg eax
// 005d8dff  1bc0                 sbb eax, eax
// 005d8e01  23c6                 and eax, esi
// 005d8e03  5e                   pop esi
// 005d8e04  5f                   pop edi
// 005d8e05  5b                   pop ebx
// 005d8e06  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?_AtlGetStringResourceImage@ATL@@YAPBUATLSTRINGRESOURCEIMAGE@1@PAUHINSTANCE__@@PAUHRSRC__@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
