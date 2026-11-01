// from server: 100% by auto
// roc 2009-06 0072a1f0  unit: CXTPCommandBarKeyboardTip  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072a1f0
//
// 0072a1f0  8b442404             mov eax, dword ptr [esp + 4]
// 0072a1f4  894154               mov dword ptr [ecx + 0x54], eax
// 0072a1f7  e824f8ffff           call 0x729a20
// 0072a1fc  8bc8                 mov ecx, eax
// 0072a1fe  e85db60000           call 0x735860
// 0072a203  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?SetImageManager@CXTPCommandBars@@QAEXPAVCXTPImageManager@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
