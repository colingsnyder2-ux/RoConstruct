// from server: 100% by auto
// roc 2009-06 00427170  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00427170
//
// 00427170  8b01                 mov eax, dword ptr [ecx]
// 00427172  50                   push eax
// 00427173  e88cd04000           call 0x834204
// 00427178  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??1Graphics@Gdiplus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
