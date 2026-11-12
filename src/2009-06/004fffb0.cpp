// from server: 100% by auto
// roc 2009-06 004fffb0  unit: RakPeer  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fffb0
//
// 004fffb0  8b4104               mov eax, dword ptr [ecx + 4]
// 004fffb3  56                   push esi
// 004fffb4  8b742408             mov esi, dword ptr [esp + 8]
// 004fffb8  3bf0                 cmp esi, eax
// 004fffba  733c                 jae 0x4ffff8
// 004fffbc  48                   dec eax
// 004fffbd  3bf0                 cmp esi, eax
// 004fffbf  7334                 jae 0x4ffff5
// 004fffc1  8d1476               lea edx, [esi + esi*2]
// 004fffc4  03d2                 add edx, edx
// 004fffc6  03d2                 add edx, edx
// 004fffc8  57                   push edi
// 004fffc9  8da42400000000       lea esp, [esp]
// 004fffd0  8b01                 mov eax, dword ptr [ecx]
// 004fffd2  8b7c100c             mov edi, dword ptr [eax + edx + 0xc]
// 004fffd6  03c2                 add eax, edx
// 004fffd8  8938                 mov dword ptr [eax], edi
// 004fffda  668b7810             mov di, word ptr [eax + 0x10]
// 004fffde  66897804             mov word ptr [eax + 4], di
// 004fffe2  8b7814               mov edi, dword ptr [eax + 0x14]
// 004fffe5  897808               mov dword ptr [eax + 8], edi
// 004fffe8  8b4104               mov eax, dword ptr [ecx + 4]
// 004fffeb  46                   inc esi
// 004fffec  48                   dec eax
// 004fffed  83c20c               add edx, 0xc
// 004ffff0  3bf0                 cmp esi, eax
// 004ffff2  72dc                 jb 0x4fffd0
// 004ffff4  5f                   pop edi
// 004ffff5  ff4904               dec dword ptr [ecx + 4]
// 004ffff8  5e                   pop esi
// 004ffff9  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?RemoveAtIndex@?$List@USystemAddressAndIndex@@@DataStructures@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
