// from server: 100% by auto
// roc 2009-06 0040cae0  unit: RBX::Reflection::Metadata::VMember::?$FactoryProduct::Creator  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040cae0
//
// 0040cae0  85c9                 test ecx, ecx
// 0040cae2  7503                 jne 0x40cae7
// 0040cae4  33c0                 xor eax, eax
// 0040cae6  c3                   ret 
// 0040cae7  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040caea  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetSafeHwnd@CWnd@@QBEPAUHWND__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
