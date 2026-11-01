// from server: 100% by auto
// roc 2007-03 0071da10  unit: seg_00710000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071da10
//
// 0071da10  8b442404             mov eax, dword ptr [esp + 4]
// 0071da14  56                   push esi
// 0071da15  50                   push eax
// 0071da16  8bf1                 mov esi, ecx
// 0071da18  e86f13f0ff           call 0x61ed8c
// 0071da1d  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0071da20  6a00                 push 0
// 0071da22  6a00                 push 0
// 0071da24  51                   push ecx
// 0071da25  ff1554ee7700         call dword ptr [0x77ee54]
// 0071da2b  5e                   pop esi
// 0071da2c  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnSetFocus@CXTButton@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
