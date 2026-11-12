// roc 2009-12 005676b0  unit: RakPeer  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005676b0
//
// 005676b0  8b4104               mov eax, dword ptr [ecx + 4]
// 005676b3  56                   push esi
// 005676b4  8b742408             mov esi, dword ptr [esp + 8]
// 005676b8  3bf0                 cmp esi, eax
// 005676ba  733c                 jae 0x5676f8
// 005676bc  48                   dec eax
// 005676bd  3bf0                 cmp esi, eax
// 005676bf  7334                 jae 0x5676f5
// 005676c1  8d1476               lea edx, [esi + esi*2]
// 005676c4  03d2                 add edx, edx
// 005676c6  03d2                 add edx, edx
// 005676c8  57                   push edi
// 005676c9  8da42400000000       lea esp, [esp]
// 005676d0  8b01                 mov eax, dword ptr [ecx]
// 005676d2  8b7c100c             mov edi, dword ptr [eax + edx + 0xc]
// 005676d6  03c2                 add eax, edx
// 005676d8  8938                 mov dword ptr [eax], edi
// 005676da  668b7810             mov di, word ptr [eax + 0x10]
// 005676de  66897804             mov word ptr [eax + 4], di
// 005676e2  8b7814               mov edi, dword ptr [eax + 0x14]
// 005676e5  897808               mov dword ptr [eax + 8], edi
// 005676e8  8b4104               mov eax, dword ptr [ecx + 4]
// 005676eb  46                   inc esi
// 005676ec  48                   dec eax
// 005676ed  83c20c               add edx, 0xc
// 005676f0  3bf0                 cmp esi, eax
// 005676f2  72dc                 jb 0x5676d0
// 005676f4  5f                   pop edi
// 005676f5  ff4904               dec dword ptr [ecx + 4]
// 005676f8  5e                   pop esi
// 005676f9  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?RemoveAtIndex@?$List@USystemAddressAndIndex@@@DataStructures@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
