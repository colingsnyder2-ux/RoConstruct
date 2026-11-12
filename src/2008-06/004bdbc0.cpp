// from server: 100% by auto
// roc 2008-06 004bdbc0  unit: ProfiledRakPeer  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bdbc0
//
// 004bdbc0  8b4104               mov eax, dword ptr [ecx + 4]
// 004bdbc3  56                   push esi
// 004bdbc4  8b742408             mov esi, dword ptr [esp + 8]
// 004bdbc8  3bf0                 cmp esi, eax
// 004bdbca  733c                 jae 0x4bdc08
// 004bdbcc  48                   dec eax
// 004bdbcd  3bf0                 cmp esi, eax
// 004bdbcf  7334                 jae 0x4bdc05
// 004bdbd1  8d1476               lea edx, [esi + esi*2]
// 004bdbd4  03d2                 add edx, edx
// 004bdbd6  03d2                 add edx, edx
// 004bdbd8  57                   push edi
// 004bdbd9  8da42400000000       lea esp, [esp]
// 004bdbe0  8b01                 mov eax, dword ptr [ecx]
// 004bdbe2  8b7c100c             mov edi, dword ptr [eax + edx + 0xc]
// 004bdbe6  03c2                 add eax, edx
// 004bdbe8  8938                 mov dword ptr [eax], edi
// 004bdbea  668b7810             mov di, word ptr [eax + 0x10]
// 004bdbee  66897804             mov word ptr [eax + 4], di
// 004bdbf2  8b7814               mov edi, dword ptr [eax + 0x14]
// 004bdbf5  897808               mov dword ptr [eax + 8], edi
// 004bdbf8  8b4104               mov eax, dword ptr [ecx + 4]
// 004bdbfb  46                   inc esi
// 004bdbfc  48                   dec eax
// 004bdbfd  83c20c               add edx, 0xc
// 004bdc00  3bf0                 cmp esi, eax
// 004bdc02  72dc                 jb 0x4bdbe0
// 004bdc04  5f                   pop edi
// 004bdc05  ff4904               dec dword ptr [ecx + 4]
// 004bdc08  5e                   pop esi
// 004bdc09  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?RemoveAtIndex@?$List@USystemAddressAndIndex@@@DataStructures@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
