// from server: 100% by auto
// roc 2007-08 00720b20  unit: CXTCaptionButtonTheme  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00720b20
//
// 00720b20  56                   push esi
// 00720b21  8bf1                 mov esi, ecx
// 00720b23  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00720b27  85c9                 test ecx, ecx
// 00720b29  7442                 je 0x720b6d
// 00720b2b  8b01                 mov eax, dword ptr [ecx]
// 00720b2d  8b9060010000         mov edx, dword ptr [eax + 0x160]
// 00720b33  ffd2                 call edx
// 00720b35  a900100000           test eax, 0x1000
// 00720b3a  7431                 je 0x720b6d
// 00720b3c  83c674               add esi, 0x74
// 00720b3f  8bce                 mov ecx, esi
// 00720b41  e8da7af2ff           call 0x648620
// 00720b46  85c0                 test eax, eax
// 00720b48  750d                 jne 0x720b57
// 00720b4a  682c657c00           push 0x7c652c
// 00720b4f  50                   push eax
// 00720b50  8bce                 mov ecx, esi
// 00720b52  e8f9e1f7ff           call 0x69ed50
// 00720b57  8bce                 mov ecx, esi
// 00720b59  e892e2f7ff           call 0x69edf0
// 00720b5e  85c0                 test eax, eax
// 00720b60  740b                 je 0x720b6d
// 00720b62  8bce                 mov ecx, esi
// 00720b64  e8b77af2ff           call 0x648620
// 00720b69  5e                   pop esi
// 00720b6a  c20400               ret 4
// 00720b6d  33c0                 xor eax, eax
// 00720b6f  5e                   pop esi
// 00720b70  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?UseWinXPThemes@CXTButtonTheme@@UAEHPAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
