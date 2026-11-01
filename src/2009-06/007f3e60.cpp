// from server: 100% by auto
// roc 2009-06 007f3e60  unit: CXTPTabManagerNavigateButton  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f3e60
//
// 007f3e60  56                   push esi
// 007f3e61  57                   push edi
// 007f3e62  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007f3e66  8bf1                 mov esi, ecx
// 007f3e68  397e04               cmp dword ptr [esi + 4], edi
// 007f3e6b  7435                 je 0x7f3ea2
// 007f3e6d  8b06                 mov eax, dword ptr [esi]
// 007f3e6f  85c0                 test eax, eax
// 007f3e71  740f                 je 0x7f3e82
// 007f3e73  50                   push eax
// 007f3e74  e8654ef2ff           call 0x718cde
// 007f3e79  83c404               add esp, 4
// 007f3e7c  c70600000000         mov dword ptr [esi], 0
// 007f3e82  33c9                 xor ecx, ecx
// 007f3e84  8bc7                 mov eax, edi
// 007f3e86  ba08000000           mov edx, 8
// 007f3e8b  f7e2                 mul edx
// 007f3e8d  0f90c1               seto cl
// 007f3e90  f7d9                 neg ecx
// 007f3e92  0bc8                 or ecx, eax
// 007f3e94  51                   push ecx
// 007f3e95  e8804ef2ff           call 0x718d1a
// 007f3e9a  83c404               add esp, 4
// 007f3e9d  8906                 mov dword ptr [esi], eax
// 007f3e9f  897e04               mov dword ptr [esi + 4], edi
// 007f3ea2  8b06                 mov eax, dword ptr [esi]
// 007f3ea4  85ff                 test edi, edi
// 007f3ea6  7e14                 jle 0x7f3ebc
// 007f3ea8  c70000000000         mov dword ptr [eax], 0
// 007f3eae  8b4e08               mov ecx, dword ptr [esi + 8]
// 007f3eb1  8b515c               mov edx, dword ptr [ecx + 0x5c]
// 007f3eb4  8b06                 mov eax, dword ptr [esi]
// 007f3eb6  4a                   dec edx
// 007f3eb7  895004               mov dword ptr [eax + 4], edx
// 007f3eba  8b06                 mov eax, dword ptr [esi]
// 007f3ebc  5f                   pop edi
// 007f3ebd  5e                   pop esi
// 007f3ebe  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?CreateIndexer@CRowIndexer@CXTPTabManager@@QAEPAUROW_ITEMS@2@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
