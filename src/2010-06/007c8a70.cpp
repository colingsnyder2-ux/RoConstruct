// from server: 100% by auto
// roc 2010-06 007c8a70  unit: PAVCXTPCommandBarKeyboardTip::?$CArray  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8a70
//
// 007c8a70  83ec10               sub esp, 0x10
// 007c8a73  56                   push esi
// 007c8a74  8bf1                 mov esi, ecx
// 007c8a76  83bec000000000       cmp dword ptr [esi + 0xc0], 0
// 007c8a7d  0f859d000000         jne 0x7c8b20
// 007c8a83  8b86a0000000         mov eax, dword ptr [esi + 0xa0]
// 007c8a89  85c0                 test eax, eax
// 007c8a8b  0f848f000000         je 0x7c8b20
// 007c8a91  83782000             cmp dword ptr [eax + 0x20], 0
// 007c8a95  0f8485000000         je 0x7c8b20
// 007c8a9b  8bc8                 mov ecx, eax
// 007c8a9d  8b01                 mov eax, dword ptr [ecx]
// 007c8a9f  8b9030010000         mov edx, dword ptr [eax + 0x130]
// 007c8aa5  ffd2                 call edx
// 007c8aa7  85c0                 test eax, eax
// 007c8aa9  7435                 je 0x7c8ae0
// 007c8aab  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 007c8ab1  85c9                 test ecx, ecx
// 007c8ab3  742b                 je 0x7c8ae0
// 007c8ab5  837c241800           cmp dword ptr [esp + 0x18], 0
// 007c8aba  740e                 je 0x7c8aca
// 007c8abc  8389e400000008       or dword ptr [ecx + 0xe4], 8
// 007c8ac3  5e                   pop esi
// 007c8ac4  83c410               add esp, 0x10
// 007c8ac7  c20400               ret 4
// 007c8aca  8b01                 mov eax, dword ptr [ecx]
// 007c8acc  5e                   pop esi
// 007c8acd  83c410               add esp, 0x10
// 007c8ad0  c744240400000000     mov dword ptr [esp + 4], 0
// 007c8ad8  8b9058010000         mov edx, dword ptr [eax + 0x158]
// 007c8ade  ffe2                 jmp edx
// 007c8ae0  8b86a0000000         mov eax, dword ptr [esi + 0xa0]
// 007c8ae6  50                   push eax
// 007c8ae7  8d4c2408             lea ecx, [esp + 8]
// 007c8aeb  e820680300           call 0x7ff310
// 007c8af0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007c8af4  2b4c2408             sub ecx, dword ptr [esp + 8]
// 007c8af8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007c8afc  2b442404             sub eax, dword ptr [esp + 4]
// 007c8b00  0fb7d1               movzx edx, cx
// 007c8b03  0fb7c8               movzx ecx, ax
// 007c8b06  c1e210               shl edx, 0x10
// 007c8b09  0bd1                 or edx, ecx
// 007c8b0b  52                   push edx
// 007c8b0c  8b96a0000000         mov edx, dword ptr [esi + 0xa0]
// 007c8b12  8b4220               mov eax, dword ptr [edx + 0x20]
// 007c8b15  6a00                 push 0
// 007c8b17  6a05                 push 5
// 007c8b19  50                   push eax
// 007c8b1a  ff1554ba9e00         call dword ptr [0x9eba54]
// 007c8b20  5e                   pop esi
// 007c8b21  83c410               add esp, 0x10
// 007c8b24  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPCommandBars.cpp (function ?RecalcFrameLayout@CXTPCommandBars@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPCommandBars.cpp
