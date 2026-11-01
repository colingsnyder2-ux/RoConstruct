// from server: 100% by auto
// roc 2009-12 008cea10  unit: CXTPTabManagerNavigateButton  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008cea10
//
// 008cea10  56                   push esi
// 008cea11  57                   push edi
// 008cea12  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008cea16  8bf1                 mov esi, ecx
// 008cea18  397e04               cmp dword ptr [esi + 4], edi
// 008cea1b  7435                 je 0x8cea52
// 008cea1d  8b06                 mov eax, dword ptr [esi]
// 008cea1f  85c0                 test eax, eax
// 008cea21  740f                 je 0x8cea32
// 008cea23  50                   push eax
// 008cea24  e8dd50f2ff           call 0x7f3b06
// 008cea29  83c404               add esp, 4
// 008cea2c  c70600000000         mov dword ptr [esi], 0
// 008cea32  33c9                 xor ecx, ecx
// 008cea34  8bc7                 mov eax, edi
// 008cea36  ba08000000           mov edx, 8
// 008cea3b  f7e2                 mul edx
// 008cea3d  0f90c1               seto cl
// 008cea40  f7d9                 neg ecx
// 008cea42  0bc8                 or ecx, eax
// 008cea44  51                   push ecx
// 008cea45  e8f850f2ff           call 0x7f3b42
// 008cea4a  83c404               add esp, 4
// 008cea4d  8906                 mov dword ptr [esi], eax
// 008cea4f  897e04               mov dword ptr [esi + 4], edi
// 008cea52  8b06                 mov eax, dword ptr [esi]
// 008cea54  85ff                 test edi, edi
// 008cea56  7e14                 jle 0x8cea6c
// 008cea58  c70000000000         mov dword ptr [eax], 0
// 008cea5e  8b4e08               mov ecx, dword ptr [esi + 8]
// 008cea61  8b515c               mov edx, dword ptr [ecx + 0x5c]
// 008cea64  8b06                 mov eax, dword ptr [esi]
// 008cea66  4a                   dec edx
// 008cea67  895004               mov dword ptr [eax + 4], edx
// 008cea6a  8b06                 mov eax, dword ptr [esi]
// 008cea6c  5f                   pop edi
// 008cea6d  5e                   pop esi
// 008cea6e  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?CreateIndexer@CRowIndexer@CXTPTabManager@@QAEPAUROW_ITEMS@2@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
