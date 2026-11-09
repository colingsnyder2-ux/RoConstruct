// from server: 100% by auto
// roc 2010-06 0084afd0  unit: CXTPRibbonBar  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0084afd0
//
// 0084afd0  83ec08               sub esp, 8
// 0084afd3  56                   push esi
// 0084afd4  57                   push edi
// 0084afd5  8d442408             lea eax, [esp + 8]
// 0084afd9  50                   push eax
// 0084afda  8bf1                 mov esi, ecx
// 0084afdc  ff1574bc9e00         call dword ptr [0x9ebc74]
// 0084afe2  8b5620               mov edx, dword ptr [esi + 0x20]
// 0084afe5  8d4c2408             lea ecx, [esp + 8]
// 0084afe9  51                   push ecx
// 0084afea  52                   push edx
// 0084afeb  ff1578bc9e00         call dword ptr [0x9ebc78]
// 0084aff1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0084aff5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0084aff9  50                   push eax
// 0084affa  51                   push ecx
// 0084affb  8bce                 mov ecx, esi
// 0084affd  e8bee2ffff           call 0x8492c0
// 0084b002  8bf8                 mov edi, eax
// 0084b004  8d57f6               lea edx, [edi - 0xa]
// 0084b007  83fa07               cmp edx, 7
// 0084b00a  772f                 ja 0x84b03b
// 0084b00c  8bce                 mov ecx, esi
// 0084b00e  e8ed01f7ff           call 0x7bb200
// 0084b013  0fb74c241c           movzx ecx, word ptr [esp + 0x1c]
// 0084b018  8b4020               mov eax, dword ptr [eax + 0x20]
// 0084b01b  0fb7d7               movzx edx, di
// 0084b01e  c1e110               shl ecx, 0x10
// 0084b021  0bca                 or ecx, edx
// 0084b023  51                   push ecx
// 0084b024  50                   push eax
// 0084b025  6a20                 push 0x20
// 0084b027  50                   push eax
// 0084b028  ff1554ba9e00         call dword ptr [0x9eba54]
// 0084b02e  5f                   pop edi
// 0084b02f  b801000000           mov eax, 1
// 0084b034  5e                   pop esi
// 0084b035  83c408               add esp, 8
// 0084b038  c20c00               ret 0xc
// 0084b03b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0084b03f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0084b043  8b542414             mov edx, dword ptr [esp + 0x14]
// 0084b047  50                   push eax
// 0084b048  51                   push ecx
// 0084b049  52                   push edx
// 0084b04a  8bce                 mov ecx, esi
// 0084b04c  e88faef7ff           call 0x7c5ee0
// 0084b051  5f                   pop edi
// 0084b052  5e                   pop esi
// 0084b053  83c408               add esp, 8
// 0084b056  c20c00               ret 0xc
// library xtp-13.2.1/Source\Ribbon\XTPRibbonBar.cpp (function ?OnSetCursor@CXTPRibbonBar@@IAEHPAVCWnd@@II@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonBar.cpp
