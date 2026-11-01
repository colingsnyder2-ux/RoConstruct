// from server: 100% by auto
// roc 2009-06 0080aff0  unit: CXTCaptionButton  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080aff0
//
// 0080aff0  8b442404             mov eax, dword ptr [esp + 4]
// 0080aff4  56                   push esi
// 0080aff5  50                   push eax
// 0080aff6  8bf1                 mov esi, ecx
// 0080aff8  e85de8f0ff           call 0x71985a
// 0080affd  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0080b000  6a00                 push 0
// 0080b002  6a00                 push 0
// 0080b004  51                   push ecx
// 0080b005  ff157cee8900         call dword ptr [0x89ee7c]
// 0080b00b  5e                   pop esi
// 0080b00c  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnSetFocus@CXTButton@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
