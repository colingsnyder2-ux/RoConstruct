// from server: 100% by auto
// roc 2010-06 00798ab0  unit: RBX::Log  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00798ab0
//
// 00798ab0  8b01                 mov eax, dword ptr [ecx]
// 00798ab2  50                   push eax
// 00798ab3  e876a71200           call 0x8c322e
// 00798ab8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??1Graphics@Gdiplus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
