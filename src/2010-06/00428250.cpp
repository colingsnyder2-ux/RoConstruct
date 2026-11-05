// from server: 100% by auto
// roc 2010-06 00428250  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00428250
//
// 00428250  8b01                 mov eax, dword ptr [ecx]
// 00428252  50                   push eax
// 00428253  e8caaf4900           call 0x8c3222
// 00428258  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??1Graphics@Gdiplus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
