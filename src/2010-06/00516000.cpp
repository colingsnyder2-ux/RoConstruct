// from server: 100% by auto
// roc 2010-06 00516000  unit: RakPeer  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00516000
//
// 00516000  8b4104               mov eax, dword ptr [ecx + 4]
// 00516003  56                   push esi
// 00516004  8b742408             mov esi, dword ptr [esp + 8]
// 00516008  3bf0                 cmp esi, eax
// 0051600a  733c                 jae 0x516048
// 0051600c  48                   dec eax
// 0051600d  3bf0                 cmp esi, eax
// 0051600f  7334                 jae 0x516045
// 00516011  8d1476               lea edx, [esi + esi*2]
// 00516014  03d2                 add edx, edx
// 00516016  03d2                 add edx, edx
// 00516018  57                   push edi
// 00516019  8da42400000000       lea esp, [esp]
// 00516020  8b01                 mov eax, dword ptr [ecx]
// 00516022  8b7c100c             mov edi, dword ptr [eax + edx + 0xc]
// 00516026  03c2                 add eax, edx
// 00516028  8938                 mov dword ptr [eax], edi
// 0051602a  668b7810             mov di, word ptr [eax + 0x10]
// 0051602e  66897804             mov word ptr [eax + 4], di
// 00516032  8b7814               mov edi, dword ptr [eax + 0x14]
// 00516035  897808               mov dword ptr [eax + 8], edi
// 00516038  8b4104               mov eax, dword ptr [ecx + 4]
// 0051603b  46                   inc esi
// 0051603c  48                   dec eax
// 0051603d  83c20c               add edx, 0xc
// 00516040  3bf0                 cmp esi, eax
// 00516042  72dc                 jb 0x516020
// 00516044  5f                   pop edi
// 00516045  ff4904               dec dword ptr [ecx + 4]
// 00516048  5e                   pop esi
// 00516049  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?RemoveAtIndex@?$List@USystemAddressAndIndex@@@DataStructures@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
