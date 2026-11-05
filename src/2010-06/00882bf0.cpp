// from server: 100% by auto
// roc 2010-06 00882bf0  unit: CXTPTabManagerNavigateButton  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00882bf0
//
// 00882bf0  56                   push esi
// 00882bf1  57                   push edi
// 00882bf2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00882bf6  8bf1                 mov esi, ecx
// 00882bf8  397e04               cmp dword ptr [esi + 4], edi
// 00882bfb  7435                 je 0x882c32
// 00882bfd  8b06                 mov eax, dword ptr [esi]
// 00882bff  85c0                 test eax, eax
// 00882c01  740f                 je 0x882c12
// 00882c03  50                   push eax
// 00882c04  e83d50f2ff           call 0x7a7c46
// 00882c09  83c404               add esp, 4
// 00882c0c  c70600000000         mov dword ptr [esi], 0
// 00882c12  33c9                 xor ecx, ecx
// 00882c14  8bc7                 mov eax, edi
// 00882c16  ba08000000           mov edx, 8
// 00882c1b  f7e2                 mul edx
// 00882c1d  0f90c1               seto cl
// 00882c20  f7d9                 neg ecx
// 00882c22  0bc8                 or ecx, eax
// 00882c24  51                   push ecx
// 00882c25  e85850f2ff           call 0x7a7c82
// 00882c2a  83c404               add esp, 4
// 00882c2d  8906                 mov dword ptr [esi], eax
// 00882c2f  897e04               mov dword ptr [esi + 4], edi
// 00882c32  8b06                 mov eax, dword ptr [esi]
// 00882c34  85ff                 test edi, edi
// 00882c36  7e14                 jle 0x882c4c
// 00882c38  c70000000000         mov dword ptr [eax], 0
// 00882c3e  8b4e08               mov ecx, dword ptr [esi + 8]
// 00882c41  8b515c               mov edx, dword ptr [ecx + 0x5c]
// 00882c44  8b06                 mov eax, dword ptr [esi]
// 00882c46  4a                   dec edx
// 00882c47  895004               mov dword ptr [eax + 4], edx
// 00882c4a  8b06                 mov eax, dword ptr [esi]
// 00882c4c  5f                   pop edi
// 00882c4d  5e                   pop esi
// 00882c4e  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?CreateIndexer@CRowIndexer@CXTPTabManager@@QAEPAUROW_ITEMS@2@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
