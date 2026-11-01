// from server: 100% by auto
// roc 2009-06 007b9c20  unit: CXTPRibbonBar  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b9c20
//
// 007b9c20  83ec08               sub esp, 8
// 007b9c23  56                   push esi
// 007b9c24  57                   push edi
// 007b9c25  8d442408             lea eax, [esp + 8]
// 007b9c29  50                   push eax
// 007b9c2a  8bf1                 mov esi, ecx
// 007b9c2c  ff152cee8900         call dword ptr [0x89ee2c]
// 007b9c32  8b5620               mov edx, dword ptr [esi + 0x20]
// 007b9c35  8d4c2408             lea ecx, [esp + 8]
// 007b9c39  51                   push ecx
// 007b9c3a  52                   push edx
// 007b9c3b  ff1530ee8900         call dword ptr [0x89ee30]
// 007b9c41  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007b9c45  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007b9c49  50                   push eax
// 007b9c4a  51                   push ecx
// 007b9c4b  8bce                 mov ecx, esi
// 007b9c4d  e88ee2ffff           call 0x7b7ee0
// 007b9c52  8bf8                 mov edi, eax
// 007b9c54  8d57f6               lea edx, [edi - 0xa]
// 007b9c57  83fa07               cmp edx, 7
// 007b9c5a  772f                 ja 0x7b9c8b
// 007b9c5c  8bce                 mov ecx, esi
// 007b9c5e  e8cd62f7ff           call 0x72ff30
// 007b9c63  0fb74c241c           movzx ecx, word ptr [esp + 0x1c]
// 007b9c68  8b4020               mov eax, dword ptr [eax + 0x20]
// 007b9c6b  0fb7d7               movzx edx, di
// 007b9c6e  c1e110               shl ecx, 0x10
// 007b9c71  0bca                 or ecx, edx
// 007b9c73  51                   push ecx
// 007b9c74  50                   push eax
// 007b9c75  6a20                 push 0x20
// 007b9c77  50                   push eax
// 007b9c78  ff1590ee8900         call dword ptr [0x89ee90]
// 007b9c7e  5f                   pop edi
// 007b9c7f  b801000000           mov eax, 1
// 007b9c84  5e                   pop esi
// 007b9c85  83c408               add esp, 8
// 007b9c88  c20c00               ret 0xc
// 007b9c8b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007b9c8f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007b9c93  8b542414             mov edx, dword ptr [esp + 0x14]
// 007b9c97  50                   push eax
// 007b9c98  51                   push ecx
// 007b9c99  52                   push edx
// 007b9c9a  8bce                 mov ecx, esi
// 007b9c9c  e88f10f8ff           call 0x73ad30
// 007b9ca1  5f                   pop edi
// 007b9ca2  5e                   pop esi
// 007b9ca3  83c408               add esp, 8
// 007b9ca6  c20c00               ret 0xc
// library xtp-15.2.1/Source\Ribbon\XTPRibbonBar.cpp (function ?OnSetCursor@CXTPRibbonBar@@IAEHPAVCWnd@@II@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonBar.cpp
