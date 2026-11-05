// from server: 100% by auto
// roc 2010-06 00891ff0  unit: CXTColorWnd  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00891ff0
//
// 00891ff0  8b442404             mov eax, dword ptr [esp + 4]
// 00891ff4  56                   push esi
// 00891ff5  50                   push eax
// 00891ff6  8bf1                 mov esi, ecx
// 00891ff8  e8d167f1ff           call 0x7a87ce
// 00891ffd  6a00                 push 0
// 00891fff  c7055466c20001000000 mov dword ptr [0xc26654], 1
// 00892009  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0089200c  6a00                 push 0
// 0089200e  51                   push ecx
// 0089200f  ff1578ba9e00         call dword ptr [0x9eba78]
// 00892015  5e                   pop esi
// 00892016  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?OnSetFocus@CXTColorWnd@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
