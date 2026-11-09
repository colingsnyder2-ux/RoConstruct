// from server: 100% by auto
// roc 2010-06 00892730  unit: CXTColorLum  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00892730
//
// 00892730  8b442404             mov eax, dword ptr [esp + 4]
// 00892734  56                   push esi
// 00892735  50                   push eax
// 00892736  8bf1                 mov esi, ecx
// 00892738  e89160f1ff           call 0x7a87ce
// 0089273d  6a00                 push 0
// 0089273f  c7055466c20002000000 mov dword ptr [0xc26654], 2
// 00892749  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0089274c  6a00                 push 0
// 0089274e  51                   push ecx
// 0089274f  ff1578ba9e00         call dword ptr [0x9eba78]
// 00892755  5e                   pop esi
// 00892756  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?OnSetFocus@CXTColorLum@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
